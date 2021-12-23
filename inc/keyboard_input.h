#ifndef KEYBOARD_INPUT_H
#define KEYBOARD_INPUT_H

#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <fstream>
#include <map>
#include <exception>

enum class KeyboardActions {
	Unknown = -1,
	Up, Left, Down, Right,
	Save, Load
};

const std::map<std::string, KeyboardActions> from_string_to_action = {
	{ "Up", KeyboardActions::Up },
	{ "Left", KeyboardActions::Left },
	{ "Down", KeyboardActions::Down },
	{ "Right", KeyboardActions::Right },
	{ "Save", KeyboardActions::Save },
	{ "Load", KeyboardActions::Load },
};

const std::map<KeyboardActions, std::string> from_action_to_string = {
	{ KeyboardActions::Up, "Up" },
	{ KeyboardActions::Left, "Left" },
	{ KeyboardActions::Down, "Down" },
	{ KeyboardActions::Right, "Right" },
	{ KeyboardActions::Save, "Save" },
	{ KeyboardActions::Load, "Load" },
};

class KeyboardInput {
private:
	std::map<sf::Keyboard::Key, KeyboardActions> keyboard;
public:
	KeyboardInput();
	~KeyboardInput();
	void bindKey(const sf::Keyboard::Key& key, const KeyboardActions& action);
	KeyboardActions getAction(const sf::Keyboard::Key& key); 
};

#endif