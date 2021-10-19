#ifndef ITEM_H
#define ITEM_H

#include "game_object.h"

class Item: public GameObject {
protected:
	std::pair<size_t, size_t> coords;
public:
	const std::pair<size_t, size_t>& getCoords() const;
	virtual Prototype* clone() const = 0;
	virtual const sf::Texture& getTexture() const = 0;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif