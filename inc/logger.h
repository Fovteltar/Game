#ifndef LOGGER_H
#define LOGGER_H

#include <algorithm>
#include <list>

#include "operators.h"
#include "publisher.h"

#include "console_wrapper.h"
#include "file_wrapper.h"

#include <sstream>
#include <string>

class GameObject;
class Creature;

enum class LoggerMode {
	COUT, FOUT, BOTH
};

class Logger: public Publisher {
private:
	LoggerMode mode;
	std::list<GameObject*> obj_list;
public:
	// void update(const std::string& context);
	Logger(const LoggerMode& mode = LoggerMode::COUT);
	~Logger();
	
	void subscribeObject(GameObject* game_object);
	void unsubscribeObject(GameObject* game_object);

	void handlePotion(const Player& player, const Potion& potion);
	void handleAttack(const Creature& attacker, const Creature& defender);
	void handleFinishReached(const Player& player);
};

#endif