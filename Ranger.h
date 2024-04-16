#ifndef RANGER_H_
#define RANGER_H_
#include "Figure.h"

class Ranger: public Figure {
public:
	Ranger();
	int getMaxHealth() const override {return MaxHealth;};
	int getMaxHand() const override {return MaxHandSize;};
	virtual ~Ranger();
	void fight_troll(Set& set);
	void fight_ghost(Set& set);
	void fight_dragon(Set& set);
};

#endif /* RANGER_H_ */
