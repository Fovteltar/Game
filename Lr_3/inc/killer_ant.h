#ifndef KILLER_ANT_H
#define KILLER_ANT_H

#include "enemy.h"
#include "game_field.h"

class KillerAnt: public Enemy {
public:
	KillerAnt(const std::pair<size_t, size_t>& coords, GameField& game_field);
	Prototype* clone() const;
	void accept(Visitor& visitor) const;
};

#endif