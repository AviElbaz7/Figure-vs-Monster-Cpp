Decks_game:Card.o Deck.o Creature.o Figure.o Enemy.o EnemyType.o Ranger.o Sorcerer.o Fighter.o Set.o Hand.o main.o
	g++ Card.o Deck.o Creature.o Figure.o Enemy.o EnemyType.o Ranger.o Sorcerer.o Fighter.o Set.o Hand.o main.o -o Decks_game
Card.o: Card.cpp Card.h
	g++ -c Card.cpp
Deck.o: Deck.cpp Deck.h Card.h
	g++ -c Deck.cpp
Creature.o: Creature.cpp Creature.h
	g++ -c Creature.cpp
Figure.o: Figure.cpp Figure.h Creature.h Hand.h Deck.h Card.h Set.h
	g++ -c Figure.cpp
Enemy.o: Enemy.cpp Enemy.h Creature.h Set.h Deck.h Card.h Figure.h Hand.h
	g++ -c Enemy.cpp
EnemyType.o: EnemyType.cpp EnemyType.h Enemy.h Creature.h Set.h Deck.h Card.h Figure.h Hand.h
	g++ -c EnemyType.cpp
Ranger.o: Ranger.cpp Ranger.h Figure.h Creature.h Hand.h Deck.h Card.h Set.h
	g++ -c Ranger.cpp
Sorcerer.o: Sorcerer.cpp Sorcerer.h Figure.h Creature.h Hand.h Deck.h Card.h Set.h
	g++ -c Sorcerer.cpp
Fighter.o: Fighter.cpp Fighter.h Figure.h Creature.h Hand.h Deck.h Card.h Set.h
	g++ -c Fighter.cpp
Set.o: Set.cpp Set.h Deck.h Card.h
	g++ -c Set.cpp
Hand.o: Hand.cpp Hand.h Deck.h Card.h
	g++ -c Hand.cpp
main.o: main.cpp Deck.h Card.h Set.h Hand.h Fighter.h Figure.h Creature.h Sorcerer.h Ranger.h EnemyType.h Enemy.h
	g++ -c main.cpp
clean: 
	rm -f *.o Decks_game
