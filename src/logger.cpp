#include "logger.h"
#include "healing_potion.h"
#include "ironskin_potion.h"
#include "rage_potion.h"
#include "creature.h"
#include "player.h"
#include "enemy.h"

Logger::Logger(const LoggerMode& mode) {
	switch(mode) {
		case LoggerMode::COUT:
			this->subscribe(new ConsoleWrapper());
			break;
		case LoggerMode::FOUT:
			this->subscribe(new FileWrapper());
			break;
		case LoggerMode::BOTH:
			this->subscribe(new ConsoleWrapper());
			this->subscribe(new FileWrapper());
			break;
	}
}

Logger::~Logger() {
	for (auto& el: subscribers) {
		delete el;
		// unsubscribe(el);
	}
	for (auto& obj: obj_list) {
		// unsubscribeObject(obj);
	}
}

void Logger::subscribeObject(GameObject* game_object) {
	obj_list.push_front(game_object);
}

void Logger::unsubscribeObject(GameObject* game_object) {
	auto it = std::find(obj_list.begin(), obj_list.end(), game_object);
    if (it != obj_list.end()) { obj_list.erase(it); }
}

void Logger::handlePotion(const Player& player, const Potion& potion) {
	std::stringstream ss;
	std::list<GameObject*>::iterator it = std::find(obj_list.begin(), obj_list.end(), &potion);
	if(it != obj_list.end()) {
		ss << potion << " USED!\n";
	}
	it = std::find(obj_list.begin(), obj_list.end(), &player);
	if(it != obj_list.end()) {
		ss << player << " ";
		if (dynamic_cast<const HealingPotion*>(&potion) != nullptr) {
			const size_t& player_hp = player.getHealth();
			const size_t& effect = potion.getEffect();
			ss << ("HEAL " + std::to_string(player_hp) +
          	  " + " + std::to_string(effect) + " -> " + 
          	  std::to_string(player_hp + effect) + "\n");
		}
		else if (dynamic_cast<const IronskinPotion*>(&potion) != nullptr) {
			const size_t& player_def = player.getArmor();
			const size_t& effect = potion.getEffect();
			ss << ("DEF INCREASED(" + std::to_string(player_def) +
		      " + " + std::to_string(effect) + " -> " + 
		      std::to_string(player_def + effect) + ")\n");
		}
		else if (dynamic_cast<const RagePotion*>(&potion) != nullptr) {
			const size_t& player_att = player.getAttack();
			const size_t& effect = potion.getEffect();
			ss << ("ATTACK INCREASED(" + std::to_string(player_att) +
		  	  " + " + std::to_string(effect) + " -> " + 
		  	  std::to_string(player_att + effect) + ")\n");
		}
	}
	notifySubscribers(ss.str());
}

void Logger::handleAttack(const Creature& attacker, const Creature& defender) {
	std::list<GameObject*>::iterator it = std::find(obj_list.begin(), obj_list.end(), &defender);
	if(it != obj_list.end()) {
		std::stringstream ss;
		if (dynamic_cast<const Player*>(&defender) != nullptr) {
	    	ss << *dynamic_cast<const Player*>(&defender) << " ";
	    }
	    else {
	    	ss << *dynamic_cast<const Enemy*>(&defender) << " ";
	    }
	    const size_t& attacker_attack = attacker.getAttack();
	    const size_t& defender_hp = defender.getHealth();
	    const size_t& defender_armor = defender.getArmor();
	    unsigned int hp_dif_defender = (unsigned int) (attacker_attack * (1 - (double)defender_armor / 100));

	    ss << ("ATTACKED: " + std::to_string(defender_hp) +
	      " - " + std::to_string(hp_dif_defender) + " -> ");

	    if (hp_dif_defender >= defender_hp) {
	        ss << "KILLED!\n";
	    }
	    else {
	        ss << (std::to_string(defender_hp - hp_dif_defender) + "\n");
	    }
	    notifySubscribers(ss.str());
	}
}

void Logger::handleFinishReached(const Player& player) {
	std::list<GameObject*>::iterator it = std::find(obj_list.begin(), obj_list.end(), &player);
	if(it != obj_list.end()) {
		std::stringstream ss;
		ss << player << " Finish reached!\n";
		notifySubscribers(ss.str());
	}
}