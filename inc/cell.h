#ifndef CELL_H
#define CELL_H

#include <utility>
#include "game_object.h"
#include "texture_getter.h"
#include "textures.h"
#include "prototype.h"

class Cell: public TextureGetter, public Prototype {
protected:
	GameObject* game_object;
public:
	GameObject& getObject();
	void setObject(GameObject* game_object);
	virtual const sf::Texture& getTexture() const = 0;
	virtual ~Cell();
	virtual Prototype* clone() const = 0;
};

#endif