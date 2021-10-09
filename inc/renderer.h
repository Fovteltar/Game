#ifndef RENDERER_H
#define RENDERER_H

#include "textures.h"
#include "game_field.h"
#include <thread>
#include <chrono>

class Renderer {
private:
	GameField& game_field;
public:
	Renderer(GameField& game_field);
	void startRender() const;
};

#endif