#include "key_checker.h"
#include "game.h"

KeyChecker::KeyChecker(Game* game) {
	this->game = game;
	keyboard_input = new KeyboardInput();
    keyboard_input->bindKey(sf::Keyboard::Up, KeyboardActions::Up);
    keyboard_input->bindKey(sf::Keyboard::Left, KeyboardActions::Left);
    keyboard_input->bindKey(sf::Keyboard::Down, KeyboardActions::Down);
    keyboard_input->bindKey(sf::Keyboard::Right, KeyboardActions::Right);

    keyboard_input->bindKey(sf::Keyboard::W, KeyboardActions::Down);
    keyboard_input->bindKey(sf::Keyboard::A, KeyboardActions::Right);
    keyboard_input->bindKey(sf::Keyboard::S, KeyboardActions::Up);
    keyboard_input->bindKey(sf::Keyboard::D, KeyboardActions::Left);
}

void KeyChecker::checkKey(const sf::Keyboard::Key& key) {
	KeyboardActions action = keyboard_input->getAction(key);
	if (action != KeyboardActions::Unknown) {
		if (action == KeyboardActions::Up || action == KeyboardActions::Left ||
			action == KeyboardActions::Down || action == KeyboardActions::Right) {
			game->getEventManager()->checkGameEvents(action);
		}
		else if (action == KeyboardActions::Save) {
			GameSaver saver(game);
		}
		else if (action == KeyboardActions::Load) {
            GameLoader load(game);
        }
	}
}

KeyChecker::~KeyChecker() {
	delete keyboard_input;
}