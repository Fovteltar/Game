#ifndef IRONSKIN_POTION_H
#define IRONSKIN_POTION_H

#include "potion.h"
#include <string>

class IronskinPotion: public Potion {
public:
	IronskinPotion(const std::pair<size_t, size_t>& coords);
	void use(Player& player) const;
	Prototype* clone() const;
	void accept(Visitor& visitor) const;
};

#endif