#ifndef SPIDER_H
#define SPIDER_H

#include "enemy.h"

class Spider: public Enemy {
public:
	Spider(const std::pair<size_t, size_t>& coords);
	Prototype* clone() const;
	const sf::Texture& getTexture() const;
};

#endif