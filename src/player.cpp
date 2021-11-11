#include "player.h"

Prototype* Player::clone() const {
	return new Player(move_manager->getCoords(), *game_field);
}

Player::Player(const std::pair<size_t, size_t>& coords, GameField& game_field) {
	move_manager = new CreatureMoveManager(coords, game_field);
	this->game_field = &game_field;
	health = 20;
	armor = 20;
	attack = 5;
}

void Player::accept(Visitor& visitor) const {
	visitor.visitTextureName("player.png");
}