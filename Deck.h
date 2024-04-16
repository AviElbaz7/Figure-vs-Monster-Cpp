#include <iostream>
using namespace std;
#include "Card.h"
#ifndef DECK_H_
#define DECK_H_

class Deck {
protected:

	int size;

public:
	Card* cards;
	Deck();
	Deck& operator+=(const Card& card);
	Deck& operator-=(int x);
	Card& operator[](int index);
	void printTopCards(int x) const;
	friend std::ostream& operator<<(std::ostream& os, const Deck& deck);
	int getSize() const;
	void removeCard(const Card& c);
	virtual ~Deck();
};

#endif /* DECK_H_ */
