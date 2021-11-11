#ifndef GAME_FIELD_VIEW_H
#define GAME_FIELD_VIEW_H

#include "SFML/Graphics.hpp"
#include "textures.h"
#include "game_field.h"
#include <string>

#include "visitor.h"

class GameFieldView: public sf::Drawable {
private:
	Visitor* visitor;
	GameField& game_field;
	const Textures& textures;
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;	
public:
	GameFieldView(GameField& game_field, const Textures& textures);
	~GameFieldView();
};

#endif