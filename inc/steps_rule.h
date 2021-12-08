#ifndef STEPS_RULE_H
#define STEPS_RULE_H

#include <cstddef>
#include "rule.h"

template<size_t max_steps> class StepsRule: public Rule {
public:
	bool check() const{
		return (game_stats->getSteps() < max_steps);
	}
	StepsRule(GameStats& game_stats) {
		this->game_stats = &game_stats;
	}
};

#endif