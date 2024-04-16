#ifndef SORCERER_H_
#define SORCERER_H_
#include "Figure.h"

class Sorcerer: public Figure{
public:
	Sorcerer();
	int getMaxHealth() const override {return MaxHealth;};
	int getMaxHand() const override {return MaxHandSize;};
	virtual ~Sorcerer();
	void fight_troll(Set& set);
	void fight_ghost(Set& set);
	void fight_dragon(Set& set);
};

#endif /* SORCERER_H_ */
