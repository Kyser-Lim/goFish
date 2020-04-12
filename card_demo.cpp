/*
// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{
    int numCards = 5;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;


    return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}




     srand(time_t(NULL)); //random set of number

    Card :: Suit s = Card::hearts ;
    Deck deck;
    deck.display();
    deck.shuffle();
    cout << "\n\n\n" << endl;
    deck.display();
    Player player1("Bro");
    Player player2;

    for(int i = 0; i < 7; i++){
        Card card1 = deck.dealCard();
        Card card2 = deck.dealCard();
        player1.addCard(card1);
        player2.addCard(card2);
    }


    cout << "Bro's hand size " << player1.getHandSize() << endl;
    cout << "Jane's hand size " << player2.getHandSize() << endl;

    cout << "Bro's hand " << player1.showHand() << endl;
    cout << "Jane's hand " << player2.showHand() << endl;
    Card card1;
    Card card2;
    if(player1.checkHandForBook(card1, card2)){
        cout << "Player1 can Book" << endl;
        player1.bookCards(card1, card2);
        player1.removeCardFromHand(card1);
        player1.removeCardFromHand(card2);
    }
    else{
        cout << "no book for 1" << endl;
    }
    cout << "Player1 amount of Books, " << player1.getBookSize() << endl;
    cout << "Player1 hand size, " << player1.getHandSize() << endl;

    if(player2.checkHandForBook(card1, card2)){
        cout << "Player2 can Book" << endl;
        player2.bookCards(card1, card2);
        player2.removeCardFromHand(card1);
        player2.removeCardFromHand(card2);
    }
    else{
        cout << "no Book for 2" << endl;
    }
    cout << "Player2 Cards " << player2.showHand() << endl;
    cout << "Player2 Books, " << player2.getBookSize() << endl;
    cout << "Player2 Hand size, " << player2.getHandSize() << endl;

    for(int i = 0; i < 8; i++){
        cout << "Player1 chose this card" << player1.chooseCardFromHand() << endl;
        cout << "Player2 chose this card" << player2.chooseCardFromHand() << endl;
        cout << "\n" << endl;
    }
    int deckSize = deck.size();
    for(int i = 0; i < deckSize; i++){
        player1.addCard(deck.dealCard());
    }
    cout << deck.size() << endl;
    deck.display();
    while(player1.checkHandForBook(card1, card2)){
        player1.bookCards(card1, card2);
    }
    deck.display();

    cout << "Player1's books:\n " << endl;
    cout << player1.showBooks() << endl;
    cout << "Amount: " << player1.getBookSize() << endl;
    cout << "Player1's final hand:" << endl;
    cout << player1.showHand() << endl;
    cout << "this is Player2's hand:" << endl;
    cout << player2.showHand() << endl;
    cout << "player2 books:" << endl;
    cout << player2.showBooks() << endl;


*/