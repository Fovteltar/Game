#ifndef IRONSKIN_POTION_H
#define IRONSKIN_POTION_H

#include "potion.h"

class IronskinPotion: public Potion {
public:
	IronskinPotion(const std::pair<size_t, size_t>& coords);
	Prototype* clone() const;
	const sf::Texture& getTexture() const;
};

#endif