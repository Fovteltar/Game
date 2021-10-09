#include "game_field_director.h"

void GameFieldDirector::setBuilder(IGameFieldBuilder* builder) {
	this->builder = builder;
}

void GameFieldDirector::constructGameField(){
	builder->buildField();
}