#ifndef CREATURE_H
#define CREATURE_H

#include <cstddef>
#include "game_object.h"
#include "creature_move_manager.h"

class Creature: public GameObject {
protected:
	size_t health;
	size_t armor; //in percentage (hold it from 0 to 100)
	size_t attack;
	CreatureMoveManager* move_manager;
public:
	virtual ~Creature();
	const size_t& getHealth() const;
	const size_t& getArmor() const;
	const size_t& getAttack() const;
	// difference must be <0 to make sth less or >0 to make sth bigger
	void changeHealth(const int& difference);
	void changeArmor(const int& difference);
	void changeAttack(const int& difference);

	CreatureMoveManager& getMoveManager();

	virtual Prototype* clone() const =0;

	virtual const sf::Texture& getTexture() const = 0;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif