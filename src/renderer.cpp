#include "renderer.h"

Renderer::Renderer(GameField& game_field, bool& not_ended): not_ended(not_ended) {
    this->game_field = &game_field;
    textures = new Textures();
    game_field_view = new GameFieldView(game_field, *textures);
    window = new sf::RenderWindow(sf::VideoMode(768.f, 768.f), "Game");
    sf::View view(sf::FloatRect(0.f, 0.f, 768.f, 768.f));
    window->setView(view);
}

Renderer::~Renderer() {
    delete textures;
    delete game_field_view;
    delete window;
}

void Renderer::drawFrame() const{
    window->clear();
    window->draw(*game_field_view);
    window->display();
}

void Renderer::checkWindowEvents(const sf::Event& event) {
    switch(event.type) {
        case sf::Event::Closed:
        {
            window->close();
            not_ended = false;
            break;
        }
        case sf::Event::Resized:
        {
            // update the view to the new size of the window
            sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
            window->setView(sf::View(visibleArea));
            break;
        }
        default:
        {
            break;
        }
    }
}

sf::RenderWindow& Renderer::getWindow() const {
    return *window;
}

void Renderer::recreate(GameField* new_game_field) {
    this->game_field = nullptr;
    this->game_field = new_game_field; 
    delete game_field_view;
    game_field_view = new GameFieldView(*game_field, *textures);
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