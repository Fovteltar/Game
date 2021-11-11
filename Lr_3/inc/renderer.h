#ifndef RENDERER_H
#define RENDERER_H

#include <thread>
#include <chrono>

#include "textures.h"
#include "game_field_view.h"

class Renderer {
private:
	bool& not_ended;
	sf::RenderWindow* window;
	GameFieldView* game_field_view;
	const Textures* textures; 
public:
	Renderer(GameField& game_field, bool& not_ended);
	~Renderer();
	sf::RenderWindow& getWindow() const;
	void drawFrame() const;
	void checkWindowEvents(const sf::Event& event);
};

#endif