#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>
#include "texture_getter.h"
#include "prototype.h"

class GameObject: public TextureGetter, public sf::Drawable, public Prototype {
public:
	virtual const sf::Texture& getTexture() const = 0;
	virtual Prototype* clone() const = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

#endif