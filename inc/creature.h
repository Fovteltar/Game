#ifndef CREATURE_H
#define CREATURE_H

#include <cstddef>
#include "creature_move_manager.h"
#include "game_field.h"

class Creature: public GameObject {
protected:
	size_t health;
	size_t armor; //in percentage (store it from 0 to 100)
	size_t attack;
	CreatureMoveManager* move_manager;
	GameField* game_field;
public:
	// Using in move_manager
	virtual ~Creature();
	
	const size_t& getHealth() const;
	const size_t& getArmor() const;
	const size_t& getAttack() const;

	void setHealth(const size_t& health);
	void setArmor(const size_t& armor);
	void setAttack(const size_t& attack);
	// difference must be <0 to make sth less or >0 to make sth bigger
	void changeHealth(const int& difference);
	void changeArmor(const int& difference);
	void changeAttack(const int& difference);

	CreatureMoveManager& getMoveManager();

	virtual Prototype* clone() const =0;
	virtual void accept(Visitor& visitor) const = 0;
};

#endif