#include "event_manager.h"


void EventManager::checkGameEvents(const sf::Event& event) {
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
        move(player, difference);
        enemiesMove();
    }
}

void EventManager::pickUp(Player& player, Item& item) {
    const std::pair<size_t, size_t>& obj_coords = item.getCoords();
    Potion* potion = dynamic_cast<Potion*>(&item);
    if (potion != nullptr) {
        logger->handlePotion(player, *potion);
        potion->use(player);
        game_field.getCell(obj_coords).setObject(nullptr);
        delete &item;
    }
}

void EventManager::attack(Creature& attacker, Creature& defender) {
    logger->handleAttack(attacker, defender);
    const size_t& attacker_attack = attacker.getAttack();

    const size_t& defender_hp = defender.getHealth();
    const size_t& defender_armor = defender.getArmor();

    unsigned int hp_dif_defender = (unsigned int) (attacker_attack * (1 - (double)defender_armor / 100));
    if (hp_dif_defender >= defender_hp) {
        game_field.getCell(
            defender.getMoveManager().getCoords()).setObject(nullptr);
        if (dynamic_cast<Player*>(&defender) != nullptr) {
            not_ended = false;
        }
        else {
            delete &defender;
        }
    }
    else {
        defender.changeHealth(-hp_dif_defender);
    }
}

void EventManager::enemiesMove() {
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
                    attack(enemy, player);
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
    const std::pair<size_t, size_t>& field_size = game_field.getFieldSize();
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
    if (dynamic_cast<WallCell*>(&game_field.getCell(
       std::make_pair(coords.first + difference.first, coords.second + difference.second)))
        == nullptr) {
       return true;
    }
    return false;
}

bool EventManager::checkNotPlayer(Enemy& enemy, const std::pair<char, char>& difference) const {
    const std::pair<size_t, size_t>& coords = enemy.getMoveManager().getCoords();
    if (dynamic_cast<Player*>(&game_field.getCell(
       std::make_pair(coords.first + difference.first, coords.second + difference.second)).getObject())
        == nullptr) {
       return true;
    }
    return false;
}

bool EventManager::checkNotEnemy(Creature& creature, const std::pair<char, char>& difference) {
    const std::pair<size_t, size_t>& coords = creature.getMoveManager().getCoords();
    if (dynamic_cast<Enemy*>(&game_field.getCell(
       std::make_pair(coords.first + difference.first, coords.second + difference.second)).getObject())
        == nullptr) {
       return true;
    }
    return false;
}

bool EventManager::checkNotItem(Creature& creature, const std::pair<char, char>& difference) {
    const std::pair<size_t, size_t>& coords = creature.getMoveManager().getCoords();
    if (dynamic_cast<Item*>(&game_field.getCell(
       std::make_pair(coords.first + difference.first, coords.second + difference.second)).getObject())
        == nullptr) {
       return true;
    }
    return false;
}

void EventManager::isFinishCell(Player& player) {
    if (player.getMoveManager().getCoords() == 
        game_field.getFinishCoords()) {
			not_ended = false;
            logger->handleFinishReached(player);
    }
}

EventManager::EventManager(GameField& game_field, Player& player, bool& not_ended):
  game_field(game_field), player(player), not_ended(not_ended) {
    logger = new Logger(LoggerMode::BOTH);
    for (size_t x = 0; x < game_field.getFieldSize().first; x++) {
        for (size_t y = 0; y < game_field.getFieldSize().second; y++) {
            if (&game_field.getCell({x, y}).getObject() != nullptr) {
                logger->subscribeObject(&game_field.getCell({x, y}).getObject());
            }
        }
    }
}

EventManager::~EventManager() {
    delete logger;
}