#ifndef KILLER_ANT_H
#define KILLER_ANT_H

#include "enemy.h"

class KillerAnt: public Enemy {
public:
	KillerAnt(const std::pair<size_t, size_t>& coords);
	Prototype* clone() const;
	const sf::Texture& getTexture() const;
};

#endif