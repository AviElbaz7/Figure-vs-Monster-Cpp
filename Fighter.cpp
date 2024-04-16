#include "Fighter.h"

Fighter::Fighter(): Figure(60, 6) {}

void Fighter::fight_troll(Set& set){
	this->calculateSpecialEffects(set, 2);
}

void Fighter::fight_ghost(Set& set){
	this->calculateSpecialEffects(set, 3);
}

void Fighter::fight_dragon(Set& set){
	this->calculateSpecialEffects(set, 1);
}


Fighter::~Fighter() {}

