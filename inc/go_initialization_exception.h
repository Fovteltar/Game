#ifndef GO_INITIALIZATION_EXCEPTION_H
#define GF_INITIALIZATION_EXCEPTION_H

#include <exception>

class GOInitializationException : public std::exception{
public:
	const char * what() const throw () {
    	return "GameObject initialization error!";
    }
};

#endif