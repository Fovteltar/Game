#ifndef RULE_H
#define RULE_H

#include "game_stats.h"

class Rule {
protected:
	GameStats* game_stats;
public:
	virtual bool check() const = 0;
	virtual ~Rule() {}
};

#endif