#include "Card.h"
#include <iostream>
using namespace std;

Card::Card(char rank, char symbol): rank(rank), symbol(symbol){
	switch(rank){
		case '2':
			value = 2;
			break;
		case '3':
			value = 3;
			break;
		case '4':
			value = 4;
			break;
		case '5':
			value = 5;
			break;
		case '6':
			value = 6;
			break;
		case '7':
			value = 7;
			break;
		case '8':
			value = 8;
			break;
		case '9':
			value = 9;
			break;
		case 'T':
		case 'J':
			value = 10;
			break;
		case 'Q':
			value = 15;
			break;
		case 'K':
			value = 20;
			break;
		case 'A':
			value = 1;
			break;
		default:
			value = -1;
			break;
	}
}

Card::Card(const Card& other): rank(other.rank), symbol(other.symbol), value(other.value){}

// helper function
int Card::getOrderSymbol(char symbol) const{
	switch(symbol){
		case 'C': return 3;
		case 'S': return 2;
		case 'H':return 1;
		case 'D': return 0;
		default: return -1;
	}
}


bool Card::operator==(const Card& other) const{
	return rank == other.rank && getOrderSymbol(symbol) == getOrderSymbol(other.symbol);
}

bool Card::operator!=(const Card& other) const{
	return !(*this == other);
}

bool Card::operator>(const Card& other) const{
	if(rank == other.rank){
		return getOrderSymbol(symbol) > getOrderSymbol(other.symbol);
	}
    if(rank == 'J' && other.rank == 'T') {
        // 'J' is considered greater than 'T'
        return true;
    }
    if(rank == 'T' && other.rank == 'J') {
        // 'T' is not considered greater than 'J'
        return false;
    }
	return value > other.value;
}

bool Card::operator>=(const Card& other) const{
	return (*this > other) || (*this == other);
}

bool Card::operator<(const Card& other) const{
	return !(*this>=other);
}

bool Card::operator<=(const Card& other) const{
	return !(*this > other);
}

Card& Card::operator=(const Card& other){
	if(*this != other){
		rank = other.rank;
		symbol = other.symbol;
		value = other.value;
	}
	return *this;
}

char Card::getRank() const{
	return rank;
}

char Card::getSymbol() const{
	return symbol;
}

int Card::getValue() const{
	return value;
}

std::ostream& operator<<(std::ostream& os, const Card& card){
	os << card.rank;
	os << card.symbol;
	return os;
}

Card::~Card() {
	// TODO Auto-generated destructor stub
}

