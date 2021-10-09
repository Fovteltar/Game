#ifndef ICELL_H
#define ICELL_H

#include "prototype.h"
#include "texture_getter.h"
#include "textures.h"

class ICell: public Prototype, public TextureGetter {
public:
	virtual void getItem() const = 0;
	virtual Prototype* clone() const = 0;
	const sf::Texture& getTexture() const = 0;
	virtual ~ICell(){};
};

#endif