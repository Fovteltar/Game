#include "user_input.h"

void UserInput::readFieldSize() {
	long long int width, height;
	while(true) {
		std::cout << "Enter field width and height: ";
		std::cin >> width >> height;
		if (width >= 3 && height >= 3) {
			this->field_size = {height, width};
			break;
		}
		std::cout << "Incorrect data. Try again!" << std::endl;
	}
}

const std::pair<size_t, size_t>& UserInput::getFieldSize() {
	return field_size;
}