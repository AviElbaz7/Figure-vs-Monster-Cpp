#include "Sorcerer.h"

Sorcerer::Sorcerer(): Figure(40, 8) {}

void Sorcerer::fight_troll(Set& set){
	this->calculateSpecialEffects(set, 1);
}

void Sorcerer::fight_ghost(Set& set){
	this->calculateSpecialEffects(set, 2);
}

void Sorcerer::fight_dragon(Set& set){
	this->calculateSpecialEffects(set, 3);
}

Sorcerer::~Sorcerer() {}

