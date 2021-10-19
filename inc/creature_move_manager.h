#ifndef CREATURE_MOVE_MANAGER_H
#define CREATURE_MOVE_MANAGER_H

#include "moveable.h"

class CreatureMoveManager: public Moveable {
protected:
	std::pair<size_t, size_t> coords;
	bool is_moved = false;
public:
	CreatureMoveManager(const std::pair<size_t, size_t>& coords);
	void move(const std::pair<char, char>& difference);
	bool getIsMoved() const ;
	void setIsMoved(bool state);
	const std::pair<size_t, size_t>& getCoords() const;
	virtual ~CreatureMoveManager(){};
};

#endif