#include "Enemy.h"

Enemy::Enemy(int startingHealth, int damage): damage(damage), startingDamage(damage) {
	health_stat = startingHealth;
}

int Enemy::getDamage() const{
	return damage;
}

void Enemy::setDamage(int newDamage){
	damage = newDamage;
}



