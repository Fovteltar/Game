#include "game_object.h"

int main() {
	GameObject* game_object = new GameObject();
	game_object->startGame();
	delete game_object;
	return 0;
}