#include "renderer.h"

Renderer::Renderer() {
    window = new sf::RenderWindow(sf::VideoMode(768.f, 768.f), "Game");
    sf::View view(sf::FloatRect(0.f, 0.f, 768.f, 768.f));
    window->setView(view);

    Textures& t = t.getInstance();
    t.createTextures();
}

Renderer::~Renderer() {
    delete window;
}

void Renderer::drawFrame() {
    window->clear();
    window->draw(Game::getInstance().getGameField());
    window->display();
}

sf::RenderWindow& Renderer::getWindow() {
    return *window;
}