#ifndef TEXTURES_H
#define TEXTURES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <filesystem>
#include <map>
#include <string>

class Textures {
private:
	std::map<std::string, sf::Texture> all_textures;
public:
	Textures();
	const sf::Texture& getTexture(const std::string& texture_name) const;
};

#endif