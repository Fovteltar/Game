#include "operators.h"

std::ostream& operator<< (std::ostream& out, const Enemy& enemy) {
    out << "[ENEMY]"; 
    return out;
}

std::ostream& operator<< (std::ostream& out, const Player& player) {
    out << "[PLAYER]"; 
    return out;
}

std::ostream& operator<< (std::ostream& out, const Potion& potion) {
    out << "[POTION]"; 
    return out;
}