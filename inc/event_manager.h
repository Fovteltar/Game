#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <SFML/Window/Event.hpp>

class Enemy;
class Player;
class Creature;
class Item;

class EventManager {
private:
	void pickUp(Player& player, Item& item);
	void attack(Creature& attacker, Creature& defender);
	void enemiesMove();
	void move(Enemy& enemy);
	void move(Player& player, const std::pair<char, char>& difference);
	/*check is move in field*/
	bool checkMoveInField(Creature& creature, const std::pair<char, char>& difference) const;
	bool checkNotWall(Creature& creature, const std::pair<char, char>& difference) const;
	bool checkNotEnemy(Creature& creature, const std::pair<char, char>& difference);
	bool checkNotItem(Creature& creature, const std::pair<char, char>& difference);

	bool checkNotPlayer(Enemy& enemy, const std::pair<char, char>& difference) const;

	void isFinishCell(Player& player);
	
public:
	void KeyPressed(sf::Event event);
};

#endif