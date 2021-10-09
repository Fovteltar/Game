#include "user_input.h"

void UserInput::readFieldSize() {
	long long int width, height;
	while(true) {
		std::cout << "Height = ";
		std::cin >> width;
		std::cout << "Width = ";
		std::cin >> height;
		if (width >= 3 && height >= 3) {
			break;
		}
		std::cout << "Incorrect data. Try again!" << std::endl;
	}
	this->field_size = {width, height};
}

std::pair<size_t, size_t> UserInput::getFieldSize() {
	return this->field_size;
}