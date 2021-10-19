#include "item.h"

const std::pair<size_t, size_t>& Item::getCoords() const {
	return coords;
}

void Item::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	size_t width = coords.first;
	size_t height = coords.second;
	sf::VertexArray quad(sf::Quads, 4);

	quad[0].position = sf::Vector2f(64.f * height, 64.f * width);
	quad[1].position = sf::Vector2f(64.f + 64.f * height, 64.f * width);
	quad[2].position = sf::Vector2f(64.f + 64.f * height, 64.f + 64.f * width);
	quad[3].position = sf::Vector2f(64.f * height, 64.f + 64.f * width);

	quad[0].texCoords = sf::Vector2f(0.f, 0.f);
	quad[1].texCoords = sf::Vector2f(64.f, 0.f);
	quad[2].texCoords = sf::Vector2f(64.f, 64.f);
	quad[3].texCoords = sf::Vector2f(0.f, 64.f);

	target.draw(quad, &this->getTexture());
}