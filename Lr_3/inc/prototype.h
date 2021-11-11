#ifndef PROTOTYPE_H
#define PROTOTYPE_H

class Prototype {
public:
	virtual Prototype* clone() const = 0;
};

#endif