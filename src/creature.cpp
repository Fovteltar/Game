#include "creature.h"

const size_t& Creature::getHealth() const { return this->health; }
const size_t& Creature::getArmor() const { return this->armor; }
const size_t& Creature::getAttack() const { return this->attack; }

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

void Creature::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	const std::pair<size_t, size_t>& coords = this->move_manager->getCoords();
	
	size_t width = coords.first;
	size_t height = coords.second;
	sf::VertexArray quad(sf::Quads, 4);

	quad[0].position = sf::Vector2f(64.f * height, 64.f * width);
	quad[1].position = sf::Vector2f(64.f + 64.f * height, 64.f * width);
	quad[2].position = sf::Vector2f(64.f + 64.f * height, 64.f + 64.f * width);
	quad[3].position = sf::Vector2f(64.f * height, 64.f + 64.f * width);

	quad[0].texCoords = sf::Vector2f(0.f, 0.f);
	quad[1].texCoords = sf::Vector2f(64.f, 0.f);
	quad[2].texCoords = sf::Vector2f(64.f, 64.f);
	quad[3].texCoords = sf::Vector2f(0.f, 64.f);

	target.draw(quad, &this->getTexture());
}

Creature::~Creature() {
	delete move_manager;
}