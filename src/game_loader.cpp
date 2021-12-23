#include "game_loader.h"
#include "game.h"

GameLoader::GameLoader(Game* game) {
	const char zenityP[] = "/usr/bin/zenity";
	char call[2048];
	char c_path[2048] = {'0'};

	sprintf(call, "%s  --file-selection --modal --title=\"%s\" ", zenityP, "Select file");

	FILE *f = popen(call, "r");

	if(f == NULL) {
		std::cerr << "file_name_dialog()\n";  
		return;
	}

	fgets(c_path, 2048, f); 

	pclose(f);

	if (((std::string)c_path).size() - 1) {
		Cell*** field;
		new_game_field = new GameField();
		new_game_stats = new GameStats();

		std::string path = ((std::string)c_path).substr(0, ((std::string)c_path).size() - 1);

		std::string line;
		std::ifstream f_read(path);

		if (f_read.is_open()) {
			try {
				for (size_t line_number = 1; line_number <= 3 && getline(f_read, line); line_number++) {
					size_t tag_pos;
					tag_pos = line.find("]");
					if (!f_read.eof() && tag_pos == std::string::npos)
						throw NoTagException();
					
					std::string tag = line.substr(0, tag_pos + 1);

					// std::cout << tag << std::endl;

					switch(line_number) {
						case 1:
							if (tag == "[gf_size]") {
								size_t x_pos;
								x_pos = line.find("x", tag_pos);
								if (x_pos == std::string::npos) {
									throw GFSizeException();
								}

								int width;

								std::string string_width = line.substr(tag_pos + 1, x_pos - tag_pos + 1);
								std::stringstream sstream_width(string_width);
								sstream_width >> width;
								if (width <= 0) {
									throw GFSizeException();
								}

								int height;

								std::string string_height = line.substr(x_pos + 1);
								std::stringstream sstream_height(string_height);
								sstream_height >> height;
								if (height <= 0) {
									throw GFSizeException();
								}

								new_game_field->setFieldSize({(size_t)width, (size_t)height});
								field = new Cell**[(size_t)width];

								for (size_t x = 0; x < (size_t)width; x++) {
									field[x] = new Cell*[(size_t)height];
								}

								for (size_t x = 0; x < (size_t)width; x++) {
									for (size_t y = 0; y < (size_t)height; y++) {
										field[x][y] = nullptr;
									}
								}

								new_game_field->setField(field);
							}
							else {
								throw GFSizeException();
							}
							break;
						case 2:
							if (tag == "[kills_rule]") {
								int kills_amount;
								std::string string_kills = line.substr(tag_pos + 1);
								std::stringstream sstream_kills(string_kills);
								sstream_kills >> kills_amount;
								// std::cout << string_kills.size() << std::endl;
								if (kills_amount < 0 || string_kills.size() == 0) {
									throw KillsRuleException();
								}
								new_game_stats->setKills(kills_amount);
							}
							else {
								throw KillsRuleException();
							}
							break;
						case 3:
							if (tag == "[steps_rule]") {
								int steps_amount;
								
								std::string string_steps = line.substr(tag_pos + 1);
								std::stringstream sstream_steps(string_steps);
								sstream_steps >> steps_amount;
								if (steps_amount < 0) {
									throw StepsRuleException();
								}
								// std::cout << steps_amount << std::endl;

								new_game_stats->setSteps(steps_amount);
							}
							else {
								throw NoTagException();
							}
							break;
					}
				}
				size_t i = 0;
				for (;i < new_game_field->getFieldSize().first * new_game_field->getFieldSize().second && getline(f_read, line); i++) {
					size_t tag_prev_pos = 0;
					size_t tag_pos;
					tag_pos = line.find("]");
					if (!f_read.eof() && tag_pos == std::string::npos)
						throw NoTagException();
					while (tag_pos != std::string::npos) {
						std::string tag = line.substr(tag_prev_pos, tag_pos - tag_prev_pos + 1);

						if (tag == "[common_cell]" || tag == "[start_cell]" || tag == "[finish_cell]" || tag == "[wall_cell]") {
							size_t semicolon_pos = line.find(";", tag_pos);

							int width;
							std::string string_width = line.substr(tag_pos + 2, semicolon_pos - tag_pos + 1);
							std::stringstream sstream_width(string_width);
							sstream_width >> width;

							if (width < 0) {
								throw GOInitializationException();
							}

							int height;
							std::string string_height = line.substr(semicolon_pos + 1, line.find("]", tag_pos + 1) - semicolon_pos + 1);
							std::stringstream sstream_height(string_height);
							sstream_height >> height;

							if (height < 0) {
								throw GOInitializationException();
							}

							// std::cout << width << " " << height << std::endl;

							if (tag == "[common_cell]") {
								field[width][height] = new CommonCell();
							}
							else if (tag == "[start_cell]"){
								field[width][height] = new StartCell();
								new_game_field->setStartCoords({width, height});
							}
							else if (tag == "[finish_cell]"){
								field[width][height] = new FinishCell();
								new_game_field->setFinishCoords({width, height});
							}
							else if (tag == "[wall_cell]"){
								field[width][height] = new WallCell();
							}

							// std::cout << tag_pos << std::endl;
							tag_prev_pos = tag_pos + 1;
							tag_pos = line.find("]", tag_pos + 1);
							tag_prev_pos = tag_pos + 1;
							tag_pos = line.find("]", tag_pos + 1);
							// std::cout << tag_pos << std::endl;
							tag = line.substr(tag_prev_pos, tag_pos - tag_prev_pos + 1);
							// std::cout << tag << std::endl;

							if (tag == "[player]" || tag == "[shadow_warrior]" || tag == "[killer_ant]" || tag == "[spider]") { 
								if (tag == "[player]") {
									player = new Player({width, height}, *new_game_field);
									field[width][height]->setObject(player);
								}
								else if (tag == "[shadow_warrior]"){
									field[width][height]->setObject(new ShadowWarrior({width, height}, *new_game_field));
								}
								else if (tag == "[killer_ant]"){
									field[width][height]->setObject(new KillerAnt({width, height}, *new_game_field));
								}
								else if (tag == "[spider]"){
									field[width][height]->setObject(new Spider({width, height}, *new_game_field));
								}

								Creature& creature = dynamic_cast<Creature&>(field[width][height]->getObject());

								tag_prev_pos = tag_pos + 1;
								tag_pos = line.find("]", tag_pos + 1);
								tag = line.substr(tag_prev_pos, tag_pos - tag_prev_pos + 1);
								// std::cout << tag << std::endl;

								size_t colon_pos = tag.find(":");
								std::string string_health = tag.substr(colon_pos + 1, tag.size() - colon_pos - 2);
								std::stringstream sstream_health(string_health);
								int health;
								sstream_health >> health;
								if (health <= 0) {
									throw GOInitializationException();
								}

								creature.setHealth(health);
								// std::cout << string_health << std::endl;


								tag_prev_pos = tag_pos + 1;
								tag_pos = line.find("]", tag_pos + 1);
								tag = line.substr(tag_prev_pos, tag_pos - tag_prev_pos + 1);
								// std::cout << tag << std::endl;

								colon_pos = tag.find(":");
								std::string string_armor = tag.substr(colon_pos + 1, tag.size() - colon_pos - 2);
								std::stringstream sstream_armor(string_armor);
								int armor;
								sstream_armor >> armor;

								if (armor < 0) {
									throw GOInitializationException();
								}

								creature.setArmor(armor);
								// std::cout << armor << std::endl;
								

								tag_prev_pos = tag_pos + 1;
								tag_pos = line.find("]", tag_pos + 1);
								tag = line.substr(tag_prev_pos, tag_pos - tag_prev_pos + 1);
								// std::cout << tag << std::endl;

								colon_pos = tag.find(":");
								std::string string_attack = tag.substr(colon_pos + 1, tag.size() - colon_pos - 2);
								std::stringstream sstream_attack(string_attack);
								int attack;
								sstream_attack >> attack;

								if (attack < 0) {
									throw GOInitializationException();
								}

								creature.setAttack(attack);
								// std::cout << attack << std::endl;
							}
							else if(tag == "[healing_potion]" || tag == "[rage_potion]" || tag == "[ironskin_potion]") {
								if (tag == "[healing_potion]") {
									field[width][height]->setObject(new HealingPotion({width, height}));
								}
								else if (tag == "[rage_potion]"){
									field[width][height]->setObject(new RagePotion({width, height}));
								}
								else if (tag == "[ironskin_potion]"){
									field[width][height]->setObject(new IronskinPotion({width, height}));
								}
							}
							else if(tag == "[no_object]") {}
							else {
								// std::cout << tag << std::endl;
								// std::cout << "1" << std::endl;
								throw GOInitializationException();
							}

							tag_prev_pos = tag_pos + 1;
							tag_pos = line.find("]", tag_pos + 1);
						}
						else {
							// std::cout << "2" << std::endl;
							throw GOInitializationException();
						}
					}
				}
				if (i != new_game_field->getFieldSize().first * new_game_field->getFieldSize().second) {
					// std::cout << i << " " << new_game_field->getFieldSize().first * new_game_field->getFieldSize().second << std::endl;
					// std::cout << "3" << std::endl;
					throw GOInitializationException();
				}
				f_read.close();
				game->loadSave(new_game_field, player, new_game_stats);
			}
			catch(const std::exception& e) {
				std::cerr << e.what();
				delete new_game_field;
				delete new_game_stats;
				return;
			}
		}
	}
}