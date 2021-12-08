#ifndef RULES_CHECKER_H
#define RULES_CHECKER_H

#include "rule.h"
#include <algorithm>
#include <vector>

template<typename ... AnyRule>
class RulesChecker {
private:
	std::vector<Rule*> rules;
public:
	RulesChecker(AnyRule* ... rule) {
		rules = {rule ...};
	}
	bool checkRules() const {
		for (const Rule* rule : rules) {
			if (rule->check() == false) {
				return false;
			}
		}
		return true;
	}
	~RulesChecker() {
		for (auto& rule : rules) {
			delete rule;
		}
	}
};

#endif