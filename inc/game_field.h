#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include <SFML/Graphics.hpp>
#include <cstddef>
#include <utility>
#include "common_cell.h"
#include "wall_cell.h"
#include "start_cell.h"
#include "finish_cell.h"
#include <cstring>

class GameField: public sf::Drawable {
private:
	Cell*** field = nullptr;
	std::pair<size_t, size_t> field_size = {0, 0};
	std::pair<size_t, size_t> start_coords;
	std::pair<size_t, size_t> finish_coords;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	void setStartCoords(const std::pair<size_t, size_t>& start_coords);
	const std::pair<size_t, size_t>& getStartCoords() const;
	void setFinishCoords(const std::pair<size_t, size_t>& finish_coords);
	const std::pair<size_t, size_t>& getFinishCoords() const;

	void setFieldSize(const std::pair<size_t, size_t>& field_size);
	const std::pair<size_t, size_t>& getFieldSize() const;
	Cell& getCell(const std::pair<size_t, size_t>& cell_coords);
	void setCell(Cell* new_cell, const std::pair<size_t, size_t>& cell_coords);
	void setField(Cell*** field);

	void changeObjectCoords(const std::pair<size_t, size_t>& old_coords,
		const std::pair<size_t, size_t>& new_coords);

	GameField& operator=(const GameField& obj);
	GameField& operator=(GameField&& obj) noexcept;
	GameField() = default;
	GameField(const GameField &obj);
	GameField(GameField &&movable);
	~GameField();
};

#endif