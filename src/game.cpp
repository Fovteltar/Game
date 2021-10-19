#include "game.h"

Game::Game() {}

Player& Game::getPlayer() {
	return *player;
}

void Game::setPlayer(Player* player) {
	this->player = player;
}

Game::~Game() {
	delete game_field;
}

Game& Game::getInstance() {
	static Game instance;
    return instance;
}

GameField& Game::getGameField(){
    return *game_field;
}

void Game::create() {
	UserInput user_input;
	user_input.readFieldSize();

	std::pair<size_t, size_t> field_size = user_input.getFieldSize();

	GameFieldBuilder gf_builder(field_size);
	gf_builder.buildField();
	gf_builder.buildSF();

	this->game_field = gf_builder.getGameField();

	PlayerSpawner p_spawner = PlayerSpawner();
	EnemiesSpawner en_spawner = EnemiesSpawner();
    ItemsSpawner it_spawner = ItemsSpawner();
	Spawner* spawner = dynamic_cast<Spawner*>(&p_spawner);
	spawner->spawn();
	spawner = dynamic_cast<Spawner*>(&en_spawner);
	spawner->spawn();
    spawner = dynamic_cast<Spawner*>(&it_spawner);
    spawner->spawn();
}

void Game::startGame() {
	Game::getInstance().create();
	Renderer renderer;
	EventManager ev_manager;
    sf::RenderWindow& window = renderer.getWindow();
	while (window.isOpen()) {
        renderer.drawFrame();
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            if (!not_ended) {
                window.close();
                break;
            }
            switch(event.type) {
                case sf::Event::Closed:
                {
                    window.close();
                    break;
                }
                case sf::Event::Resized:
                {
                    // update the view to the new size of the window
                    sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
                    window.setView(sf::View(visibleArea));
                    break;
                }
                case sf::Event::KeyPressed:
                {
                    ev_manager.KeyPressed(event);
                }
                default:
                {
                    break;
                }
                // case sf::Event::KeyPressed:
                // {
                //     float x_c = window.getView().getCenter().x;
                //     float y_c = window.getView().getCenter().y;
                //     float width = window.getView().getSize().x;
                //     float height = window.getView().getSize().y;
                //     sf::FloatRect visibleArea(x_c - width / 2, y_c - height / 2, width, height);

                //     const float kMove = 64.f;
                //     switch(event.key.code) {
                //         case sf::Keyboard::Right:
                //         {
                //             if (visibleArea.left + kMove <= game_field.getFieldSize().first * 64.f) {
                //                 visibleArea.left += kMove;
                //             }
                //             break;
                //         }
                //         case sf::Keyboard::Left:
                //         {
                //             if (visibleArea.left - kMove >= 0.f) {
                //                 visibleArea.left -= kMove;
                //             }
                //             break;
                //         }
                //         case sf::Keyboard::Up:
                //         {
                //             if (visibleArea.top - kMove >= 0.f) {
                //                 visibleArea.top -= kMove;
                //             }
                //             break;
                //         }
                //         case sf::Keyboard::Down:
                //         {
                //             if (visibleArea.top + kMove <= game_field.getFieldSize().second * 64.f) {
                //                 visibleArea.top += kMove;
                //             }
                //             break;
                //         }
                //         default:
                //         {
                //             break;
                //         }
                //     }
                //     window.setView(sf::View(visibleArea));
                //     break;
                // }
                // default:
                // {
                //     break;
                // }
            }       
        }
    }
}

void Game::setEnd() {
	this->not_ended = false;
}

bool Game::getGameState() const {
	return not_ended;
}