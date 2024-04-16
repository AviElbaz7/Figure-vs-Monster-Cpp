#include "Figure.h"

Figure::Figure(int startingHealthVal, int maxHandSize) : MaxHandSize(maxHandSize), startingHealingPoints(0){
	health_stat = startingHealthVal;
	MaxHealth = startingHealthVal;
	mydamage = 0;
	enemydamage = 0;
	healingPoints = 0;
}

void Figure::calculateSpecialEffects(Set& set, int excludedPower){
	this->enemydamage = 0;
    std::vector<char> specialSigns = set.getSpecialSigns();
    int totalValue = 0;
    for (int i = 0; i < set.getSize(); i++) {
        totalValue += set.cards[i].getValue();
    }
    bool hasLeaf = std::find(specialSigns.begin(), specialSigns.end(), 'S') != specialSigns.end();
    bool hasClover = std::find(specialSigns.begin(), specialSigns.end(), 'C') != specialSigns.end();
    if ((hasClover && hasLeaf) && excludedPower!=3) {
        totalValue *= 2;
        this->mydamage = totalValue;
    }
    if(!hasLeaf || !hasClover){
    	this->mydamage = totalValue;
    }
    if(excludedPower == 3){
    	this->mydamage = totalValue;
    }
    for (char sign : specialSigns) {
        if (excludedPower != 1 && sign == 'D') {
            this->enemydamage = totalValue;
        }
        if (excludedPower != 2 && sign == 'H') {
            this->healingPoints = totalValue;
        }
    }
}

void Figure::gainHealth(int num){
	if(health_stat != getMaxHealth()){
		health_stat = std::min(getMaxHealth(), health_stat + num);
	}
}


int Figure::getCurrentHealth() const{
	return health_stat;
}


Figure::~Figure() {}

