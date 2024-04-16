#ifndef CREATURE_H_
#define CREATURE_H_
#include <iostream>

class Creature {
protected:
	int health_stat;
public:
	Creature();
	virtual ~Creature(){};
	void hurtHealth(int num);
};

#endif /* CREATURE_H_ */
