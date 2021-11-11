#include "console_wrapper.h"

void ConsoleWrapper::write(const std::string& string) {
	if (is_open)
		(*ostr) << string;
}

ConsoleWrapper::ConsoleWrapper() {
	this->is_open = true;
	ostr = &std::cout;
}

ConsoleWrapper::~ConsoleWrapper() {
	this->is_open = false;
}
