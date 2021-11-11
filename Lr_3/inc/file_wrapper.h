#ifndef FILE_WRAPPER_H
#define FILE_WRAPPER_H

#include "wrapper.h"
#include <fstream>

class FileWrapper: public Wrapper {
private:
	std::ofstream* ofstr;
public:
	void write(const std::string& string);
	FileWrapper();
	~FileWrapper();
};

#endif