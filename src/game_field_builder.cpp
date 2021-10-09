#include "game_field_builder.h"

void GameFieldBuilder::buildSE() {
	size_t width = game_field->getFieldSize().first;
	size_t height = game_field->getFieldSize().second;

	std::pair<size_t, size_t> start;
	std::pair<size_t, size_t> finish;

	std::srand(std::time(nullptr));

	while(true) {
		start = {std::rand() % width, std::rand() % height};
		finish = {std::rand() % width, std::rand() % height};
		if ((std::abs((int)start.first - (int)finish.first) <= 1) || 
			(std::abs((int)start.second - (int)finish.second) <= 1)) {
			continue;
		}
		else {
			break;
		}
	}

	game_field->setCell(new StartCell(), {start.first, start.second});
	game_field->setCell(new FinishCell(), {finish.first, finish.second});
}

void GameFieldBuilder::buildField() {
	size_t width = game_field->getFieldSize().first;
	size_t height = game_field->getFieldSize().second;
	ICell*** field = new ICell**[width];
	this->game_field->setField(field);

	for (size_t x = 0; x < width; x++) {
		field[x] = new ICell*[height];
	}

	this->buildSE();

	std::srand(std::time(NULL));

	for (size_t x = 0; x < width; x++) {
		for (size_t y = 0; y < height; y++) {
			// 10% chance to create wall
			if (field[x][y] == nullptr) {
				if (rand()%10) {
					field[x][y] = new CommonCell();
				}
				else {
					field[x][y] = new WallCell();
				}
			}
		}
	}
}

GameFieldBuilder::GameFieldBuilder(std::pair<size_t, size_t> field_size) {
	reset();
	game_field->setFieldSize(field_size);
}

GameFieldBuilder::~GameFieldBuilder() {
	delete game_field;
}

void GameFieldBuilder::reset() {
	game_field = new GameField();
}

GameField* GameFieldBuilder::getGameField() {
	GameField* result = this->game_field;
	this->reset();
	return result;
}
