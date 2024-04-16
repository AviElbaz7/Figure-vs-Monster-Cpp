#include "Set.h"

Set::Set() : Deck() {}

char Set::getRank() const{
	if(this->getSize() > 0){
		return cards[0].getRank();
	}
	else{
		return '\0';
	}
}

bool Set::isValidSet() const {
    if (this->getSize() < 1) {
        return false;
    }

    // Variables to track rank, total value, and number of Aces
    char rank = cards[0].getRank();
    if(rank == 'A' && (this->getSize() > 1)){
    	rank = cards[1].getRank();
    }
    int totalValue = 0;
    int aceCount = 0;
    if(getSize() > 1){
		for (int i = 0; i < this->getSize(); i++) {
			if (cards[i].getRank() != rank && cards[i].getRank() != 'A') {
				return false;
			}
			totalValue += cards[i].getValue();
			if (this->cards[i].getRank() == 'A') {
				aceCount++;
			}
		}
		if(aceCount == 2 && this->getSize() == 2){
			return true;
		}
		// If more than one Ace is found, set is invalid
		if (aceCount > 1) {
			return false;
		}
		if(aceCount == 0){
			return totalValue <= 10;
		}
		if(aceCount == 1 && this->getSize() > 2){
			return (totalValue - 1) <= 10;
		}
		return true;
    }
    else{
    	return true;
    }
}

void Set::removeCardsFromDeck(){
	for(int i = 0; i < getSize(); i++){
		Deck::removeCard(cards[i]);
	}
}


std::vector<char> Set::getSpecialSigns() const{
	std::vector<char> specialSigns;
	for(int i = 0; i < getSize(); i++){
		char symbol = cards[i].getSymbol();
		if(symbol == 'D' || symbol == 'C' || symbol == 'S' || symbol == 'H'){
			if(std::find(specialSigns.begin(), specialSigns.end(), symbol) == specialSigns.end()){
				specialSigns.push_back(symbol);
			}
		}
	}
	return specialSigns;
}


Set::~Set() {}

