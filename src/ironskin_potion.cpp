#include "ironskin_potion.h"

IronskinPotion::IronskinPotion(const std::pair<size_t, size_t>& coords) {
	this->coords = coords;
	this->effect = 5;
}

void IronskinPotion::use(Player& player) const {
	player.changeArmor(effect);
}

Prototype* IronskinPotion::clone() const {
	return new IronskinPotion(this->coords);
}

void IronskinPotion::accept(Visitor& visitor) const {
	visitor.visitTextureName("ironskin_potion.png");
}