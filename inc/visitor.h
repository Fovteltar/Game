#ifndef VISITOR_H
#define VISITOR_H

#include <string>

class Visitor {
private:
	std::string texture_name;
public:
	void visitTextureName(const std::string& texture_name);
	const std::string& getTextureName() const;
};

#endif