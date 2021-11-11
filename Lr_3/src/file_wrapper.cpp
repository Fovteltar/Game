#include "file_wrapper.h"

void FileWrapper::write(const std::string& string) {
	if (is_open)
		(*ofstr) << string;
}

FileWrapper::FileWrapper() {
	ofstr = new std::ofstream("./logs/log.txt", std::ofstream::out);
	if (ofstr->is_open()) {
		this->is_open = true;
	}
	else {
		this->is_open = false;
	}
}
FileWrapper::~FileWrapper() {
	this->is_open = false;
	ofstr->close();
	delete ofstr;
}
