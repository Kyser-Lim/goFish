final: go_fish.o player.o deck.o card.o
	g++ -std=c++0x -o go_fish go_fish.o player.o deck.o card.o
driver: go_fish.cpp player.h deck.h card.h
	g++ -std=c++0x -c go_fish.cpp
player.o: player.cpp player.h
	g++ -std=c++0x -c player.cpp
deck.o: deck.cpp deck.h card.h
	g++ -std=c++0x -c deck.cpp
card.o: card.cpp card.h
	g++ -std=c++0x -c card.cpp