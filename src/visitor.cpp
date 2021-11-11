#include "visitor.h"

void Visitor::visitTextureName(const std::string& texture_name) {
	this->texture_name = texture_name;
}

const std::string& Visitor::getTextureName() const {
	return texture_name;
}