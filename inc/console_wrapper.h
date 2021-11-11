#ifndef CONSOLE_WRAPPER_H
#define CONSOLE_WRAPPER_H

#include "wrapper.h"

class ConsoleWrapper: public Wrapper {
private:
	std::ostream* ostr;
public:
	void write(const std::string& string);
	ConsoleWrapper();
	~ConsoleWrapper();
};

#endif