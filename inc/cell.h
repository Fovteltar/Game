#ifndef CELL_H
#define CELL_H

#include <utility>
#include "game_object.h"
#include "textures.h"
#include "prototype.h"
#include "visitor.h"

class Cell: public Prototype {
protected:
	GameObject* game_object;
public:
	GameObject& getObject();
	void setObject(GameObject* game_object);
	virtual ~Cell();
	virtual Prototype* clone() const = 0;
	virtual void accept(Visitor& visitor) const = 0;
};

#endif