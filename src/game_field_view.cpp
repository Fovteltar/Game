#include "game_field_view.h"

void GameFieldView::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	const std::pair<size_t, size_t>& field_size = game_field.getFieldSize(); 
	size_t width = field_size.first;
	size_t height = field_size.second;
	sf::VertexArray quad(sf::Quads, 4);
	for (size_t x = 0; x < width; x++) {
		for (size_t y = 0; y < height; y++) {
			quad[0].position = sf::Vector2f(64.f * y, 64.f * x);
			quad[1].position = sf::Vector2f(64.f + 64.f * y, 64.f * x);
			quad[2].position = sf::Vector2f(64.f + 64.f * y, 64.f + 64.f * x);
			quad[3].position = sf::Vector2f(64.f * y, 64.f + 64.f * x);

			quad[0].texCoords = sf::Vector2f(0.f, 0.f);
			quad[1].texCoords = sf::Vector2f(64.f, 0.f);
			quad[2].texCoords = sf::Vector2f(64.f, 64.f);
			quad[3].texCoords = sf::Vector2f(0.f, 64.f);

			Cell& cell = game_field.getCell({x, y});
			GameObject& game_object = cell.getObject();

			cell.accept(*visitor);
			target.draw(quad, &textures.getTexture(visitor->getTextureName()));

			if (&game_object != nullptr) {
				game_object.accept(*visitor);
				target.draw(quad, &textures.getTexture(visitor->getTextureName()));
			}
		}
	}
}

GameFieldView::GameFieldView(GameField& game_field, const Textures& textures):
game_field(game_field), textures(textures) {
	visitor = new Visitor();
}

GameFieldView::~GameFieldView() {
	delete visitor;
}