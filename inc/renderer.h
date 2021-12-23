#ifndef RENDERER_H
#define RENDERER_H

#include <thread>
#include <chrono>

#include "textures.h"
#include "game_field_view.h"
#include "creature.h"

class Renderer {
private:
	GameField* game_field;
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
	void recreate(GameField* new_game_field);
};

#endif