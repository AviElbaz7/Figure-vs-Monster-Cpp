#ifndef HAND_H_
#define HAND_H_
#include "Deck.h"

class Hand: public Deck {
public:
	Hand();
	virtual ~Hand();
//	friend std::ostream& operator<<(std::ostream& os, const Hand& hand);
};

#endif /* HAND_H_ */
