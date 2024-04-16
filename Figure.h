#ifndef FIGURE_H_
#define FIGURE_H_
#include "Creature.h"
#include "Hand.h"
#include "Set.h"

class Figure: public Creature{
protected:
	int MaxHandSize;
	int MaxHealth;
	int mydamage;
	int enemydamage;
	int healingPoints;
	int startingHealingPoints;
public:
	Figure(int startingHealthVal, int maxHandSize);
	virtual ~Figure();
	void gainHealth(int num);
	int getMyDamage() const{return mydamage;};
	int getEnemyDamage() const{return enemydamage;};
	int getHealingPoints() const{return healingPoints;};
	int setHealingPoints(int num){return healingPoints = num;};
	int getStartingHealingPoints(){return startingHealingPoints;};
	int getCurrentHealth() const;
	virtual int getMaxHealth() const = 0;
	virtual int getMaxHand() const = 0;
	void calculateSpecialEffects(Set& set, int excludedPower);
	virtual void fight_troll(Set& set) = 0;
	virtual void fight_ghost(Set& set) = 0;
	virtual void fight_dragon(Set& set) = 0;
};

#endif /* FIGURE_H_ */
