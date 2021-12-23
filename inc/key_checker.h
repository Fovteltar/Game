#ifndef KEY_CHECKER_H
#define KEY_CHECKER_H

#include "event_manager.h"
#include "keyboard_input.h"

#include "game_saver.h"
#include "game_loader.h"

class Game;

class KeyChecker {
private:
	Game* game;
	KeyboardInput* keyboard_input;
public:
	KeyChecker(Game* game);
	void checkKey(const sf::Keyboard::Key& key);
	~KeyChecker();
};

#endif