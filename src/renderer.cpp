#include "renderer.h"

Renderer::Renderer(GameField& game_field): game_field(game_field) {
    Textures& t = t.getInstance();
    t.createTextures();
}

void Renderer::startRender() const {
	sf::RenderWindow window(sf::VideoMode(768.f, 768.f), "Game");
    sf::View view(sf::FloatRect(0.f, 0.f, 768.f, 768.f));
    window.setView(view);

	while (window.isOpen()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
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
                    float x_c = window.getView().getCenter().x;
                    float y_c = window.getView().getCenter().y;
                    float width = window.getView().getSize().x;
                    float height = window.getView().getSize().y;
                    sf::FloatRect visibleArea(x_c - width / 2, y_c - height / 2, width, height);

                    const float kMove = 64.f;
                    switch(event.key.code) {
                        case sf::Keyboard::Right:
                        {
                            if (visibleArea.left + kMove <= game_field.getFieldSize().first * 64.f) {
                                visibleArea.left += kMove;
                            }
                            break;
                        }
                        case sf::Keyboard::Left:
                        {
                            if (visibleArea.left - kMove >= 0.f) {
                                visibleArea.left -= kMove;
                            }
                            break;
                        }
                        case sf::Keyboard::Up:
                        {
                            if (visibleArea.top - kMove >= 0.f) {
                                visibleArea.top -= kMove;
                            }
                            break;
                        }
                        case sf::Keyboard::Down:
                        {
                            if (visibleArea.top + kMove <= game_field.getFieldSize().second * 64.f) {
                                visibleArea.top += kMove;
                            }
                            break;
                        }
                        default:
                        {
                            break;
                        }
                    }
                    window.setView(sf::View(visibleArea));
                    break;
                }
                default:
                {
                    break;
                }
            }       
        }
        window.clear();
        window.draw(this->game_field);
        window.display();
    }
}