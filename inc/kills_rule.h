#ifndef KILLS_RULE_H
#define KILLS_RULE_H

#include <cstddef>
#include "rule.h"

template<size_t max_kills> class KillsRule: public Rule {
public:
	bool check() const {
		return (game_stats->getKills() >= max_kills);
	}
	KillsRule(GameStats& game_stats) {
		this->game_stats = &game_stats;
	}
};

#endif