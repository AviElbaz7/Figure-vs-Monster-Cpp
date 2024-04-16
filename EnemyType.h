#ifndef GHOST_H_
#define GHOST_H_
#include "Enemy.h"

class Ghost: public Enemy {
public:
	Ghost();
	int getMaxHealth() const override {return 50;};
	virtual ~Ghost();
	void fight(Figure& figure, Set& set) {figure.fight_ghost(set);}
};

#endif /* GHOST_H_ */


#ifndef DRAGON_H_
#define DRAGON_H_

class Dragon: public Enemy {

public:
	Dragon();
	int getMaxHealth() const override {return 75;};
	virtual ~Dragon();
	void fight(Figure& figure, Set& set) {figure.fight_dragon(set);}
};

#endif /* DRAGON_H_ */

#ifndef TROLL_H_
#define TROLL_H_

class Troll: public Enemy{
public:
	Troll();
	int getMaxHealth() const override {return 100;};
	virtual ~Troll();
	void fight(Figure& figure, Set& set) {figure.fight_troll(set);}
};

#endif /* TROLL_H_ */

