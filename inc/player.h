#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"

class Player: public Creature {
public:
	Player(const std::pair<size_t, size_t>& coords);
	Prototype* clone() const;
	const sf::Texture& getTexture() const;
};

#endif