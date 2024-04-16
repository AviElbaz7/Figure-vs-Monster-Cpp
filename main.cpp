#include "Deck.h"
#include "Set.h"
#include "Hand.h"
#include "Fighter.h"
#include "Sorcerer.h"
#include "Ranger.h"
#include "EnemyType.h"
#include <string.h>
#include <string>
#include <memory>
#include <iostream>
using namespace std;

Deck& loadDeck(Deck& deck){
	cout << "Initialize deck" << endl;
	std::string input;
	while(true){
		std::cin >> input;
		if(input == "00"){
			break;
		}
		deck += Card(input[0], input[1]);
	}
	return deck;
}

Figure* chooseFigure(){
	int choice;
	cout << "Choose player character:" << endl;
	cout << "(1) Fighter (2) Sorcerer (3) Ranger" << endl;
	std::cin >> choice;
	Figure* figure = nullptr;
	switch(choice){
		case 1:
			figure = new Fighter();
			break;
		case 2:
			figure = new Sorcerer();
			break;
		case 3:
			figure = new Ranger();
			break;
	}
	return figure;
}

Enemy* chooseEnemy(){
	int choice;
	cout << "Choose enemy character:" << endl;
	cout << "(1) Troll (2) Ghost (3) Dragon" << endl;
	std::cin >> choice;
	cin.ignore();
	Enemy* enemy = nullptr;
	switch(choice){
		case 1:
			enemy = new Troll();
			break;
		case 2:
			enemy = new Ghost();
			break;
		case 3:
			enemy = new Dragon();
			break;
	}
	return enemy;
}


void startGame(Figure* figure, Enemy* enemy, Deck& deck, Set& set, Hand& hand){
    char temp[300]; // Temporary buffer for input
    bool game = true;
    int iter = 0;
    int currentNumHand = 0;
    while(game){
    	int numRemoveCardFromSet = 0;
    	int numCardsRemoved = 0;
        cout << "Player health: " << figure->getCurrentHealth() << endl;
        cout << "Enemy health: " << enemy->getCurrentHealth() << endl;
        int j = 0;
        if(iter == 0){
        	for(int i = 0; i < figure->getMaxHand(); i++){
        		hand += deck.cards[i];
        		numCardsRemoved++;
        		j++;
        	}
        	iter++;
        }
        else{
        	for(int i = 0; i < std::min(2, (figure->getMaxHand() - currentNumHand)); i++){
        		hand += deck.cards[i];
        		numCardsRemoved++;
        		j++;
        	}
        }
        currentNumHand += j;
        deck -= numCardsRemoved;
		Hand temp_hand;
		for(int i = 0; i < hand.getSize(); i++){
			temp_hand += hand[i];
		}
    	cout << "Player hand" << endl;
    	cout << hand << " " << endl;
    	flag:
		bool isIn = false;
		bool toCheck = true;
        cout << "Insert card set to play" << endl;
        cin.getline(temp, 300);
        if(strcmp(temp, "exit") == 0){
            game = false;
            break;
        }
        // Parse input string to extract card set
        char* token = strtok(temp, " ");
        // Loop through each token (card) in the input string
        while(token != nullptr){
            Card temp_card = Card(token[0], token[1]);
            // Check if the card is in the player's hand
            for(int i = 0; i < hand.getSize(); i++){
                if(hand[i] == temp_card){
                	isIn = true;
                    set += temp_card; // Add card to the set
                    numRemoveCardFromSet++;
                    hand.removeCard(temp_card); // Remove card from the player's hand
                    currentNumHand--;
                    break; // Exit the loop once the card is found
                }
            }
            if(!isIn){
            	toCheck = false;
            	break;
            }
            isIn = false;

            token = strtok(nullptr, " "); // Move to the next token
        }
        bool setValid = set.isValidSet();
        if(strcmp(temp, "exit") != 0){
        	// Check if the set is valid
			if(setValid && toCheck){
				enemy->fight(*figure, set);
				enemy->hurtHealth(figure->getMyDamage());
				if(enemy->getCurrentHealth() < 0){
					enemy->setCurrentHealth(0);
				}
				enemy->setDamage(enemy->getDamage() - figure->getEnemyDamage());
				if(enemy->getDamage() < 0){
					enemy->setDamage(0);
				}
				int HealingCheck = 0;
				if(figure->getHealingPoints() > 0){
					HealingCheck = figure->getCurrentHealth() + figure->getHealingPoints();
				}
				if(figure->getHealingPoints() > 0 && (HealingCheck > figure->getMaxHealth())){
					figure->setHealingPoints(figure->getHealingPoints() - (HealingCheck - figure->getMaxHealth()));
				}
				figure->gainHealth(figure->getHealingPoints());
				figure->hurtHealth(enemy->getDamage());

				if(enemy->getCurrentHealth() <= 0){
					game = false;
					cout << "Player dealt " <<  figure->getMyDamage() << " points of damage"  << endl;
					cout << "Player won" << endl;
					break;
				}
				else if(figure->getCurrentHealth() <= 0){
					game = false;
					cout << "Player dealt " <<  figure->getMyDamage() << " points of damage"  << endl;
					if(figure->getHealingPoints() > 0){
						cout << "Player healed " << figure->getHealingPoints() << " points of damage" << endl;
					}
					cout << "Player took " <<  enemy->getDamage() << " points of damage"  << endl;
					cout << "Player lost" << endl;
					break;
				}
				else{
					cout << "Player dealt " << figure->getMyDamage() << " points of damage" << endl;
					if(figure->getHealingPoints() > 0){
						cout << "Player healed " << figure->getHealingPoints() << " points of damage" << endl;
					}
					cout << "Player took " << enemy->getDamage() << " points of damage" << endl;
				}
				bool shouldBreak = false;
				if(set.getSize() > deck.getSize() && deck.getSize() > std::min(2, (figure->getMaxHand() - currentNumHand))){
					game = false;
					cout << "Deck ran out" << endl;
					shouldBreak = true;
				}
				set -= numRemoveCardFromSet;
				if(shouldBreak){
					break;
				}
				if(deck.getSize() == 0){
					game = false;
					cout << "Deck ran out" << endl;
					break;
				}
				enemy->setDamage(enemy->startingDamage);
				figure->setHealingPoints(figure->getStartingHealingPoints());

			}
			else {
				hand -= hand.getSize();
				for(int i = 0; i < temp_hand.getSize(); i++){
					hand += temp_hand[i];
				}
				currentNumHand += set.getSize();
				cout << "Card set is not valid" << endl;
				set -= set.getSize();
				goto flag;
			}
        }
    }
}


int main() {
	try{
		Hand hand;
		Set set;
		Deck deck;
		loadDeck(deck);
		unique_ptr<Figure> figure(chooseFigure());
		unique_ptr<Enemy> enemy(chooseEnemy());
		if(figure.get() == nullptr || enemy.get() == nullptr){
			throw bad_alloc();
		}
		bool canStart = true;
		if(deck.getSize() < figure->getMaxHand()){
			canStart = false;
			cout << "Deck ran out" << endl;
		}
		if(canStart){
			startGame(figure.get(), enemy.get(), deck, set, hand);
		}
	}
	catch(const std::bad_alloc& e){
		cout << "Memory Error" << endl;
	}

	return 0;
}
