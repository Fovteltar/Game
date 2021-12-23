#ifndef STEPS_RULE_EXCEPTION_H
#define STEPS_RULE_EXCEPTION_H

#include <exception>

class StepsRuleException : public std::exception{
public:
	const char * what() const throw () {
    	return "Incorrect StepsRule size!";
    }
};

#endif