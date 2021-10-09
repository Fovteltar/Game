#ifndef TEXTURE_GETTER_H
#define TEXTURE_GETTER_H

#include "textures.h"

class TextureGetter {
public:
	virtual const sf::Texture& getTexture() const = 0;
};

#endif