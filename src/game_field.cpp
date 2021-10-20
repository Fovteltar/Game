#include "game_field.h"

GameField::~GameField() {
	for (size_t x = 0; x < field_size.first; x++) {
		for (size_t y = 0; y < field_size.second; y++)  {
			delete field[x][y];
		}
		delete[] field[x];
	}
	delete[] field;
}

GameField::GameField(const GameField &obj) {
	this->field_size = obj.field_size;
	this->start_coords = obj.start_coords;
	this->finish_coords = obj.finish_coords;

	size_t width = this->field_size.first;
	size_t height = this->field_size.second;

	Cell*** new_cell_field = new Cell**[width];
	this->field = new_cell_field;
	for (size_t x = 0; x < width; x++) {
		new_cell_field[x] = new Cell*[height];
		for (size_t y = 0; y < height; y++) {
			new_cell_field[x][y] = dynamic_cast<Cell*>(obj.field[x][y]->clone());
		}
	}
}

void GameField::setStartCoords(const std::pair<size_t, size_t>& start_coords) {
	this->start_coords = start_coords;
}

const std::pair<size_t, size_t>& GameField::getStartCoords() const {
	return start_coords;
}

void GameField::setFinishCoords(const std::pair<size_t, size_t>& finish_coords) {
	this->finish_coords = finish_coords;
}
const std::pair<size_t, size_t>& GameField::getFinishCoords() const {
	return this->finish_coords;
}

void GameField::setFieldSize(const std::pair<size_t, size_t>& field_size) {
	this->field_size = field_size;
}

void GameField::setField(Cell*** field) {
	this->field = field;
}

const std::pair<size_t, size_t>& GameField::getFieldSize() const {
	return field_size;
}

Cell& GameField::getCell(const std::pair<size_t, size_t>& cell_coords){
	return *this->field[cell_coords.first][cell_coords.second];
}

void GameField::setCell(Cell* new_cell, const std::pair<size_t, size_t>& cell_coords) {
	delete this->field[cell_coords.first][cell_coords.second];
	this->field[cell_coords.first][cell_coords.second] = new_cell;
}

void GameField::changeObjectCoords(const std::pair<size_t, size_t>& old_coords,
	const std::pair<size_t, size_t>& new_coords) {
	if (old_coords != new_coords) {
		field[new_coords.first][new_coords.second]->setObject(
			&field[old_coords.first][old_coords.second]->getObject());
		field[old_coords.first][old_coords.second]->setObject(nullptr);
	}
}

void GameField::draw(sf::RenderTarget& target, sf::RenderStates states) const {
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

			target.draw(quad, &this->field[x][y]->getTexture());
			if (&this->field[x][y]->getObject() != nullptr) {
				target.draw(this->field[x][y]->getObject());
			}
		}
	}
}

GameField::GameField(GameField &&movable_obj) {
	this->field = std::move(movable_obj.field);
	this->field_size = std::move(movable_obj.field_size);
}

GameField& GameField::operator=(const GameField& obj) {
	return *this = GameField(obj);
}

GameField& GameField::operator=(GameField&& obj) noexcept{
	std::swap(this->field, obj.field);
	std::swap(this->field_size, obj.field_size);
	return *this;
}