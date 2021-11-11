#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "prototype.h"
#include "visitor.h"
#include "publisher.h"

class GameObject: public Prototype {
public:
	virtual Prototype* clone() const = 0;
	virtual void accept(Visitor& visitor) const = 0;
	virtual ~GameObject(){};
};

#endif