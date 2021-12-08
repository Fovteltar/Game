#include "game.h"

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
}

Game::~Game() {
	delete game_field;
    delete game_stats;
}

Game& Game::getInstance() {
	static Game instance;
    return instance;
}

void Game::startGame() {
	Renderer renderer(*game_field, not_ended);
	EventManager ev_manager(*game_field, *player, not_ended, *game_stats);
    sf::RenderWindow& window = renderer.getWindow();

    sf::Event event;
    while (not_ended) {
        renderer.drawFrame();
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        window.waitEvent(event);
        renderer.checkWindowEvents(event);
        ev_manager.checkGameEvents(event);
    }
}