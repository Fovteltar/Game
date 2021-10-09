#ifndef TEXTURES_H
#define TEXTURES_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <string>
#include <filesystem>

class Textures {
private:
	std::map<std::string, sf::Texture> all_textures;
	Textures();

public:
	static Textures& getInstance();
	Textures(Textures &other) = delete;
	void operator=(const Textures &) = delete;

	const sf::Texture& getTexture(const std::string& texture_name) const;
	void createTextures();
};

#endif