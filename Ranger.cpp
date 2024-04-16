#include "Ranger.h"

Ranger::Ranger(): Figure(50, 7) {}

void Ranger::fight_troll(Set& set){
	this->calculateSpecialEffects(set, 3);
}

void Ranger::fight_ghost(Set& set){
	this->calculateSpecialEffects(set, 1);
}

void Ranger::fight_dragon(Set& set){
	this->calculateSpecialEffects(set, 2);
}

Ranger::~Ranger() {}

