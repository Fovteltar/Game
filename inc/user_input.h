#ifndef USER_INPUT_H
#define USER_INPUT_H

#include <iostream>
#include <utility>
#include <cstddef>

class UserInput {
private:
	std::pair<size_t, size_t> field_size;
public:
	void readFieldSize();
	const std::pair<size_t, size_t>& getFieldSize();
};

#endif