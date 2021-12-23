#include "game.h"
#include "key_checker.h"

Game::Game() {
    game_stats = new GameStats(); 

    not_ended = true;

    UserInput user_input;
    user_input.readFieldSize();

    std::pair<size_t, size_t> field_size = user_input.getFieldSize();

    GameFieldBuilder gf_builder(field_size);
    gf_builder.buildField();
    gf_builder.buildSF();
    gf_builder.buildCreatures();

    this->game_field = gf_builder.getGameField();

    const std::pair<size_t, size_t>& start_coords = game_field->getStartCoords();
    this->player = dynamic_cast<Player*>(&game_field->getCell(start_coords).getObject());

    this->renderer = new Renderer(*game_field, not_ended);
    this->event_manager = new EventManager(*game_field, *player, not_ended, *game_stats);
}

Game::~Game() {
	delete game_field;
    delete game_stats;
    delete renderer;
    delete event_manager;
}

Game& Game::getInstance() {
	static Game instance;
    return instance;
}

void Game::startGame() {
    KeyChecker key_checker(this);
    sf::RenderWindow& window = renderer->getWindow();

    sf::Event event;
    while (not_ended) {
        renderer->drawFrame();
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        // window.waitEvent(event);
        // if (event.type == sf::Event::KeyPressed) {
        //     key_checker.checkKey(event.key.code);
        // }
        while(window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                key_checker.checkKey(event.key.code);
            }
        }
        renderer->checkWindowEvents(event);
    }
}

void Game::loadSave(GameField* new_game_field, Player* new_player, GameStats* new_game_stats) {
    delete this->game_field;
    delete this->game_stats;
    this->game_field = new_game_field;
    // std::cout << new_game_field->getFieldSize().first << " " << 
    //   new_game_field->getFieldSize().second << std::endl;
    this->player = new_player;
    this->game_stats = new_game_stats;

    renderer->recreate(new_game_field);

    delete event_manager;
    this->event_manager = new EventManager(*game_field, *player, not_ended, *game_stats);
}

EventManager* Game::getEventManager() {
    return event_manager;
}

GameStats* Game::getGameStats() {
    return game_stats;
}

GameField* Game::getGameField() {
    return game_field;
}