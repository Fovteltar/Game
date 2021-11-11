#ifndef OPERATORS_H
#define OPERATORS_H

#include <iostream>

class Enemy;
class Player;
class Potion;

std::ostream& operator<< (std::ostream& out, const Enemy& enemy);
std::ostream& operator<< (std::ostream& out, const Player& player);
std::ostream& operator<< (std::ostream& out, const Potion& potion);

#endif