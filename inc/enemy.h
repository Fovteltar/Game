#ifndef ENEMY_H
#define ENEMY_H

#include "creature.h"

class Enemy: public Creature {
public:
	virtual Prototype* clone() const = 0;
	virtual const sf::Texture& getTexture() const = 0;
};

#endif