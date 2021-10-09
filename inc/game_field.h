#ifndef GAME_FIELD_H
#define GAME_FIELD_H

#include <cstddef>
#include <utility>
#include "common_cell.h"
#include "wall_cell.h"
#include "start_cell.h"
#include "finish_cell.h"
#include <cstring>
#include <map>

class GameField: public sf::Drawable {
private:
	ICell*** field = nullptr;
	std::pair <size_t, size_t> field_size = {0, 0};
protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:
	void setFieldSize(std::pair<size_t, size_t> field_size);
	void setField(ICell*** field);
	const std::pair<size_t, size_t> getFieldSize() const;
	ICell* getCell(std::pair<size_t, size_t> cell_coords) const;
	void setCell(ICell* new_cell, std::pair<size_t, size_t> cell_coords);
	GameField& operator=(const GameField& obj);
	GameField& operator=(GameField&& obj) noexcept;
	GameField() = default;
	GameField(const GameField &obj);
	GameField(GameField &&movable);
	~GameField();
};

#endif