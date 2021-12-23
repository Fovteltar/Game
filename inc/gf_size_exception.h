#ifndef GF_SIZE_EXCEPTION_H
#define GF_SIZE_EXCEPTION_H

#include <exception>

class GFSizeException : public std::exception{
public:
	const char * what() const throw () {
    	return "Incorrect GF size!";
    }
};

#endif