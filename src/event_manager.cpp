#include "event_manager.h"
#include "game.h"

void EventManager::pickUp(Player& player, Item& item) {
    const std::pair<size_t, size_t>& obj_coords = item.getCoords();
    GameField& game_field = Game::getInstance().getGameField();
    if (dynamic_cast<Potion*>(&item) != nullptr) {
        if (dynamic_cast<HealingPotion*>(&item) != nullptr) {
            player.changeHealth(dynamic_cast<HealingPotion&>(item).getEffect());
            std::cout << "playerHp " << player.getHealth() << std::endl; 
        }
        else if (dynamic_cast<RagePotion*>(&item) != nullptr) {
            player.changeAttack(dynamic_cast<RagePotion&>(item).getEffect());
            std::cout << "playerAttack " << player.getAttack() << std::endl; 
        }
        else if (dynamic_cast<IronskinPotion*>(&item) != nullptr) {
            player.changeArmor(dynamic_cast<IronskinPotion&>(item).getEffect());
            std::cout << "playerDefence " << player.getArmor() << "%" << std::endl; 
        }
        game_field.getCell(obj_coords).setObject(nullptr);
        delete &item;
    }
}

void EventManager::attack(Creature& attacker, Creature& defender) {
    const size_t& attacker_attack = attacker.getAttack();

    const size_t& defender_hp = defender.getHealth();
    const size_t& defender_armor = defender.getArmor();

    unsigned int hp_dif_defender = (unsigned int) (attacker_attack * (1 - (double)defender_armor / 100));
    std::cout << "ATTACKED: " << defender_hp << " - " << hp_dif_defender << " = ";
    if (hp_dif_defender >= defender_hp) {
        Game::getInstance().getGameField().getCell(
            defender.getMoveManager().getCoords()).setObject(nullptr);
        if (dynamic_cast<Player*>(&defender) != nullptr) {
            Game::getInstance().setEnd();
        }
        else {
            delete &defender;
        }
        std::cout << "KILLED!" << std::endl; 
    }
    else {
        std::cout << defender_hp - hp_dif_defender << std::endl;
        defender.changeHealth(-hp_dif_defender);
    }
}

void EventManager::enemiesMove() {
    GameField& game_field = Game::getInstance().getGameField();
    const std::pair<size_t, size_t> field_size = game_field.getFieldSize();
    for (size_t x = 0; x < field_size.first; x++) {
        for (size_t y = 0; y < field_size.second; y++) {
            Enemy* enemy = dynamic_cast<Enemy*>(&game_field.getCell(std::make_pair(x, y)).getObject());
            if (enemy != nullptr && !enemy->getMoveManager().getIsMoved()) {
                move(*enemy);
            }
        }
    }
    for (size_t x = 0; x < field_size.first; x++) {
        for (size_t y = 0; y < field_size.second; y++) {
            Enemy* enemy = dynamic_cast<Enemy*>(&game_field.getCell(std::make_pair(x, y)).getObject());
            if (enemy != nullptr) {
                enemy->getMoveManager().setIsMoved(false);
            }
        }
    } 
}

void EventManager::move(Enemy& enemy) {
    std::pair<char, char> difference = {0, 0};
    bool can_move = true;
    int random_move = std::rand() % 4;
    for (size_t i = 0; ((i < 4) && can_move); i++) {
        switch(random_move) {
            case 0:
                difference = std::make_pair((char)0, (char)1);
                break;
            case 1:
                difference = std::make_pair((char)0, (char)-1);
                break;
            case 2:
                difference = std::make_pair((char)-1, (char)0);
                break;
            case 3:
                difference = std::make_pair((char)1, (char)0);
                break;
        }
        random_move = (random_move + 1) % 4;
        if (checkMoveInField(enemy, difference)) {
            if (checkNotWall(enemy, difference) &&
             checkNotEnemy(enemy, difference) && 
             checkNotItem(enemy, difference)) {
                can_move = false;
                if (!checkNotPlayer(enemy, difference)) {
                    attack(enemy, Game::getInstance().getPlayer());
                }
                else {
                    enemy.getMoveManager().setIsMoved(true);
                    enemy.getMoveManager().move(difference);
                }
            }
        }
    }
}

void EventManager::move(Player& player, const std::pair<char, char>& difference) {
    GameField& game_field = Game::getInstance().getGameField();
    if (checkMoveInField(player, difference)) {
        if (checkNotWall(player, difference)) {
            const std::pair<size_t, size_t>& player_coords = player.getMoveManager().getCoords();
            const std::pair<size_t, size_t> obj_coords = {player_coords.first + difference.first, player_coords.second + difference.second};
            if (!checkNotEnemy(player, difference)) {
                Enemy& enemy = dynamic_cast<Enemy&>(game_field.getCell(obj_coords).getObject());
                attack(player, enemy);
                return;
            }
            if(!checkNotItem(player, difference)) {
                Item& item = dynamic_cast<Item&>(game_field.getCell(obj_coords).getObject());
                pickUp(player, item);
            }
            player.getMoveManager().move(difference);
            isFinishCell(player);
        }
    }
}

bool EventManager::checkMoveInField(Creature& creature, const std::pair<char, char>& difference) const{
    const std::pair<size_t, size_t>& coords = creature.getMoveManager().getCoords();
    const std::pair<size_t, size_t>& field_size = Game::getInstance().getGameField().getFieldSize();
    if (((difference.first <= 0 && coords.first >= std::abs(difference.first)) || 
        (difference.first > 0 && coords.first + difference.first < field_size.first)) &&
        ((difference.second <= 0 && coords.second >= std::abs(difference.second)) || 
        (difference.second > 0 && coords.second + difference.second < field_size.second)
        )) 
    {
        return true;  
    }
    return false;
}

bool EventManager::checkNotWall(Creature& creature, const std::pair<char, char>& difference) const{
    const std::pair<size_t, size_t>& coords = creature.getMoveManager().getCoords();
    if (dynamic_cast<WallCell*>(&Game::getInstance().getGameField().getCell(
       std::make_pair(coords.first + difference.first, coords.second + difference.second)))
        == nullptr) {
       return true;
    }
    return false;
}

bool EventManager::checkNotPlayer(Enemy& enemy, const std::pair<char, char>& difference) const {
    const std::pair<size_t, size_t>& coords = enemy.getMoveManager().getCoords();
    if (dynamic_cast<Player*>(&Game::getInstance().getGameField().getCell(
       std::make_pair(coords.first + difference.first, coords.second + difference.second)).getObject())
        == nullptr) {
       return true;
    }
    return false;
}

bool EventManager::checkNotEnemy(Creature& creature, const std::pair<char, char>& difference) {
    const std::pair<size_t, size_t>& coords = creature.getMoveManager().getCoords();
    if (dynamic_cast<Enemy*>(&Game::getInstance().getGameField().getCell(
       std::make_pair(coords.first + difference.first, coords.second + difference.second)).getObject())
        == nullptr) {
       return true;
    }
    return false;
}

bool EventManager::checkNotItem(Creature& creature, const std::pair<char, char>& difference) {
    const std::pair<size_t, size_t>& coords = creature.getMoveManager().getCoords();
    if (dynamic_cast<Item*>(&Game::getInstance().getGameField().getCell(
       std::make_pair(coords.first + difference.first, coords.second + difference.second)).getObject())
        == nullptr) {
       return true;
    }
    return false;
}

void EventManager::isFinishCell(Player& player) {
    Game& game = Game::getInstance();
    if (player.getMoveManager().getCoords() == 
        game.getGameField().getFinishCoords()) {
        game.setEnd();
    }
}

void EventManager::KeyPressed(sf::Event event) {
	if (event.type == sf::Event::KeyPressed) {
        std::pair<char, char> difference = {0, 0};
        switch(event.key.code) {
            case sf::Keyboard::Right:
            {
                difference = std::make_pair((char)0, (char)1);
                break;
            }
            case sf::Keyboard::Left:
            {
                difference = std::make_pair((char)0, (char)-1);
                break;
            }
            case sf::Keyboard::Up:
            {
                difference = std::make_pair((char)-1, (char)0);
                break;
            }
            case sf::Keyboard::Down:
            {
                difference = std::make_pair((char)1, (char)0);
                break;
            }
            default:
            {
                break;
            }
        }
        move(Game::getInstance().getPlayer(), difference);
        enemiesMove();
    }
}