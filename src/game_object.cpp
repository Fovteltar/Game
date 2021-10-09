#include "game_object.h"

GameObject::GameObject() {
	GameFieldDirector director;
	UserInput user_input;
	user_input.readFieldSize();

	IGameFieldBuilder* builder = new GameFieldBuilder(user_input.getFieldSize());

	director.setBuilder(builder);
	director.constructGameField();

	this->game_field = builder->getGameField();

	delete builder;
}

GameObject::~GameObject() {
	delete game_field;
}

void GameObject::startGame() {
	Renderer renderer(*this->game_field);
	renderer.startRender();
}