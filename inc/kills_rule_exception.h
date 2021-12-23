#ifndef KILLS_RULE_EXCEPTION_H
#define KILLS_RULE_EXCEPTION_H

#include <exception>

class KillsRuleException : public std::exception{
public:
	const char * what() const throw () {
    	return "Incorrect KillsRule size!";
    }
};

#endif