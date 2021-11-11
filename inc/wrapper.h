#ifndef WRAPPER_H
#define WRAPPER_H

#include <iostream>

class Wrapper {
protected:
	bool is_open;
public:
	virtual void write(const std::string& string) = 0;
	virtual ~Wrapper() {};
};

#endif