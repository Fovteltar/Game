#ifndef NO_TAG_EXCEPTION_H
#define NO_TAG_EXCEPTION_H

#include <exception>

class NoTagException : public std::exception{
public:
	const char * what() const throw () {
    	return "Where is no tag!";
    }
};

#endif