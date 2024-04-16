#include "Creature.h"

Creature::Creature() {
	this->health_stat = 0;
}


void Creature::hurtHealth(int num){
	health_stat -= num;
}


