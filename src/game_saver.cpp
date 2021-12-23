#include "game_saver.h"

GameSaver::GameSaver(Game* game) {
	GameField& game_field = *game->getGameField();
	GameStats& game_stats = *game->getGameStats();
	std::string log;
	const std::pair<size_t, size_t>& field_size = game_field.getFieldSize();
	Visitor visitor;

	log += ("[gf_size]" + std::to_string(field_size.first) + "x" + std::to_string(field_size.second) + "\n");
	log += ("[kills_rule]" + std::to_string(game_stats.getKills()) + "\n");
	log += ("[steps_rule]" + std::to_string(game_stats.getSteps()) + "\n");
	for (size_t x = 0; x < field_size.first; x++) {
		for (size_t y = 0; y < field_size.second; y++) {
			Cell& cell = game_field.getCell({x, y});
			
			cell.accept(visitor);
			std::string texture_name = visitor.getTextureName();
			std::string cell_tag = texture_name.substr(0, texture_name.find("."));
			log += ("[" + cell_tag + "]" + "[" + std::to_string(x) + ";" + std::to_string(y) + "]");

			GameObject* object = &cell.getObject();
			if (object != nullptr) {
				object->accept(visitor);
				std::string texture_name = visitor.getTextureName();
				std::string object_tag = texture_name.substr(0, texture_name.find("."));
				log += ("[" + object_tag + "]");

				Creature* creature = dynamic_cast<Creature*>(object);
				if (creature != nullptr) {
					log += ("[hp:" + std::to_string(creature->getHealth()) + "]" +
						"[armor:" + std::to_string(creature->getArmor()) + "]" +
						"[attack:" + std::to_string(creature->getAttack()) + "]\n");
				}
				else {
					log += "\n";
				}
			}
			else {
				log += "[no_object]\n";
			}	
		}
	}

	auto dir_iter = std::filesystem::directory_iterator("./saves");
	size_t file_count = 0;

	for (auto& entry : dir_iter) {
	    if (entry.is_regular_file()) {
	        file_count++;
	    }
	}


	std::ofstream fs("./saves/" + std::to_string(file_count) + ".txt"); 
    if(!fs)
    {
        std::cerr<<"Cannot create the output file!" << std::endl;
        return;
    }
    fs << log;
    fs.close();
}