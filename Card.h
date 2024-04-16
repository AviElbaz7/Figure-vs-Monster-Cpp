#include <iostream>
using namespace std;
#ifndef CARD_H_
#define CARD_H_

class Card {
private:
	char rank;
	char symbol;
	int value;

public:
	Card(char rank = '\0', char symbol = '\0');
	Card(const Card& other); // copy construction

	// helper function
	int getOrderSymbol(char symbol) const;

	bool operator==(const Card& other) const;
	bool operator!=(const Card& other) const;
	bool operator>(const Card& other) const;
	bool operator>=(const Card& other) const;
	bool operator<(const Card& other) const;
	bool operator<=(const Card& other) const;
	Card& operator=(const Card& other);
	friend std::ostream& operator<<(std::ostream& os, const Card& card);
	char getRank() const;
	char getSymbol() const;
	int getValue() const;
	virtual ~Card();
};

#endif /* CARD_H_ */
