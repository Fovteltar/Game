#ifndef EVENT_MANAGER_H
#define EVENT_MANAGER_H

#include <SFML/Window/Event.hpp>
#include <string>
#include "game_field.h"
#include "player.h"
#include "item.h"
#include "enemy.h"
#include "potion.h"
#include "logger.h"

class EventManager {
private:
	GameField& game_field;
	Player& player;
	bool& not_ended;

	Logger* logger;
	
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
	void checkGameEvents(const sf::Event& event);
	EventManager(GameField& game_field, Player& player, bool& not_ended);
	~EventManager();
};

#endif