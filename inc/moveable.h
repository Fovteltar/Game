#ifndef MOVEABLE_H
#define MOVEABLE_H

#include <cstddef>
#include <utility>

class Moveable {
public:
	virtual void move(const std::pair<char, char>& difference) = 0;
};

#endif