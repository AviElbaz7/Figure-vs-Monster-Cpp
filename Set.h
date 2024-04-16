#ifndef SET_H_
#define SET_H_
#include "Deck.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>


class Set: public Deck {
private:
	void removeCardsFromDeck();
public:
	Set();
	char getRank() const;
	bool isValidSet() const;
	std::vector<char> getSpecialSigns() const;
	virtual ~Set();
};

#endif /* SET_H_ */
