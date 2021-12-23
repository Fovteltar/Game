#include "creature.h"

const size_t& Creature::getHealth() const { return this->health; }
const size_t& Creature::getArmor() const { return this->armor; }
const size_t& Creature::getAttack() const { return this->attack; }

void Creature::setHealth(const size_t& health) {
	this->health = health;
}

void Creature::setArmor(const size_t& armor) {
	this->armor = armor;
}

void Creature::setAttack(const size_t& attack) {
	this->attack = attack;
}

void Creature::changeHealth(const int& difference) {
	if (difference <= 0) {
		if (health <= std::abs(difference)) {
			health = 0;
			return;
		}
	}
	this->health += difference;
}

void Creature::changeArmor(const int& difference) {
	if (difference <= 0) {
		if (armor <= std::abs(difference)) {
			armor = 0;
			return;
		}
	}
	this->armor += difference;
}
void Creature::changeAttack(const int& difference) {
	if (difference <= 0) {
		if (attack <= std::abs(difference)) {
			attack = 0;
			return;
		}
	}
	this->attack += difference;
}

CreatureMoveManager& Creature::getMoveManager(){
	return *move_manager;
}

Creature::~Creature() {
	delete move_manager;
}