#ifndef FIGHTER_H_
#define FIGHTER_H_
#include "Figure.h"

class Fighter: public Figure {
public:
	Fighter();
	int getMaxHealth() const override {return MaxHealth;};
	int getMaxHand() const override {return MaxHandSize;};
	virtual ~Fighter();
	void fight_troll(Set& set);
	void fight_ghost(Set& set);
	void fight_dragon(Set& set);
};

#endif /* FIGHTER_H_ */
