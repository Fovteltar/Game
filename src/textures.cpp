#include "textures.h"

Textures::Textures() {};

Textures& Textures::getInstance() {
	static Textures instance;
    return instance;
}
const sf::Texture& Textures::getTexture(const std::string& texture_name) const{
	return this->all_textures.at(texture_name);
}

void Textures::createTextures() {
	sf::Texture t;
	std::string path = "./textures";
    for (const auto & entry : std::filesystem::directory_iterator(path)){
    	if (!(t.loadFromFile(entry.path().string()))) {
			std::cerr << "Download texture error!" << std::endl;
	        std::exit(1);
		}
		auto const pos = entry.path().string().find_last_of('/');
	    const auto leaf = entry.path().string().substr(pos+1);
		this->all_textures[leaf] = t;
    }
}