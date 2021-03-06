#ifndef GAME_STATS_H
#define GAME_STATS_H

#include <cstddef>

class GameStats {
private:
	size_t steps_amount;
	size_t kills_amount;
public:
	GameStats();
	const size_t& getSteps() const;
	const size_t& getKills() const;
	void setSteps(const size_t& steps_amount);
	void setKills(const size_t& kills_amount);
	void increaseSteps();
	void increaseKills();
};

#endif