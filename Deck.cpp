#include "Deck.h"
#include "Card.h"
#include <iostream>

Deck::Deck(): size(0){cards = nullptr;}


Deck& Deck::operator+=(const Card& card){
	Card* temp = new (std::nothrow) Card[this->size+1];
	if(temp == nullptr){
		throw bad_alloc();
	}
	for(int i=0; i<this->size; i++){
		temp[i] = this->cards[i];
	}
	temp[this->size] = card;
	delete[] this->cards;
	this->cards = temp;
	++size;
	return *this;
}

Deck& Deck::operator-=(int x){
	if(x > size){
		delete[] cards;
		cards = nullptr;
		size = 0;
	}
	else{
		size -= x;
		Card* temp = new (std::nothrow) Card[size];
		if(temp == nullptr){
			throw bad_alloc();
		}
		for(int i = 0; i < size; i++){
			temp[i] = cards[i+x];
		}
		delete[] cards;
		cards = temp;
	}
	return *this;
}

Card& Deck::operator[](int index){
    if(index < 0 || index >= size){
        std::cout << "Invalid index" << std::endl;
        // Return a reference to a default Card object in case of an invalid index
        return cards[0]; // Or any other appropriate default behavior
    }
    return cards[size - 1 - index];
}


void Deck::printTopCards(int x) const{
	if(x > size){
		x = size;
	}
	for(int i=0; i < x; i++){
		std::cout << cards[i] << " ";
	}
}

std::ostream& operator<<(std::ostream& os, const Deck& deck){
	for(int i=deck.size-1; i>=0; --i){
		os << deck.cards[i];
		if(i>0){
			os << " ";
		}
	}
	return os;
}

int Deck::getSize() const{
	return size;
}


void Deck::removeCard(const Card& c){
    int index = -1;
    // Find the index of the card to be removed
    for(int i = 0; i < size; i++){
        if(cards[i] == c){
            index = i;
            break;
        }
    }
    if(index != -1){
        // Shift the cards after the removed card
        for(int i = index; i < size - 1; i++){
            cards[i] = cards[i+1];
        }
        size--;
        // Allocate new memory for the resized deck
        Card* temp = new (std::nothrow) Card[size];
        if(temp == nullptr){
        	throw bad_alloc();
        }
        // Copy the remaining cards to the new array
        for(int i = 0; i < size; i++){
            temp[i] = cards[i];
        }
        // Deallocate the old memory and update the cards pointer
        delete[] cards;
        cards = temp;
    }
}

Deck::~Deck() {
	delete[] cards;
}

