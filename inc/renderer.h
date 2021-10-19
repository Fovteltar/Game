#ifndef RENDERER_H
#define RENDERER_H

#include "textures.h"
#include <thread>
#include <chrono>
#include "game.h"

class Renderer {
private:
	sf::RenderWindow* window;
public:
	Renderer();
	~Renderer();
	sf::RenderWindow& getWindow();
	void drawFrame();
};

#endif