#ifndef ENEMY_H_
#define ENEMY_H_
#include "Creature.h"
#include "Set.h"
#include "Figure.h"

class Enemy: public Creature {
protected:
	int damage;
public:
	const int startingDamage;
	Enemy(int startingHealth, int damage);
	virtual ~Enemy() {};
	int getDamage() const;
	int setCurrentHealth(int num){return health_stat = num;};
	void setDamage(int newDamage);
	int getCurrentHealth() const{return health_stat;};
	virtual int getMaxHealth() const = 0;
	virtual void fight(Figure& figure, Set& set) = 0;
};

#endif /* ENEMY_H_ */
