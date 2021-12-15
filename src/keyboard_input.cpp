#include "keyboard_input.h"

KeyboardInput::KeyboardInput() {
	std::string line;
	std::ifstream f_read("./config/binds.txt");

	/*
	23 = Up
	0 = Left
	19 = Down
	3 = Right
	*/

	if (f_read.is_open()) {
		while (getline(f_read, line)) {
			size_t pos = line.find(" ");
			int key_number = std::stoi(line.substr(0, pos));
			pos = line.find(" ", pos + 1);
			std::string action = line.substr(pos + 1);
			if (key_number >= 0 && key_number <= 100) {
				try {
					this->bindKey(static_cast<sf::Keyboard::Key>(key_number), from_string_to_action.at(action));
				}
				catch (std::exception& e) {
					std::cerr << "err: " << e.what() << '\n';
				}
			}
		}
		f_read.close();
	}
}

KeyboardInput::~KeyboardInput() {
	std::map<KeyboardActions, std::string> from_action_to_string = {};
	for (const auto& pair : from_string_to_action) {
		from_action_to_string[pair.second] = pair.first;
	}

	std::ofstream f_write("./config/binds.txt");
	if (f_write.is_open()) {
		for (const auto& my_pair : keyboard) {
			std::string row;
			row = std::to_string(static_cast<int>(my_pair.first)) + " = " + from_action_to_string.at(my_pair.second) + "\n";
			f_write << row;
	    }
		f_write.close();
	}
}

void KeyboardInput::bindKey(const sf::Keyboard::Key& key, const KeyboardActions& action) {
	keyboard[key] = action;
}

KeyboardActions KeyboardInput::getAction(const sf::Keyboard::Key& key) {
	if (keyboard.count(key)) {
		return keyboard.at(key);
	}
	return KeyboardActions::Unknown;
}