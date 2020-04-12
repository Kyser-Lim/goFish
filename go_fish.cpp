//
// Created by Daniel Masud on 4/8/2020.
//

#include "card.h"
#include "deck.h"
#include "player.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS

using namespace std;

void dealHand(Deck &d, Player &p, int numCards);

int main()
{
    int numCards = 7;
    int whoseTurn = 0;
    Card c1CheckTemp;
    Card c2CheckTemp;
    Card chosen;
    bool anotherTurn = false;
    int rank;
    int newNumCards;

    Player p1("Joe");
    Player p2("Jane");

    Deck d;  //create a deck of cards
    d.shuffle();

    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);

    cout << p1.getName() <<" has : " << p1.showHand() << endl;
    cout << p2.getName() <<" has : " << p2.showHand() << endl;

    if(p1.checkHandForBook(c1CheckTemp, c2CheckTemp))  //if starts with a pair in hand
    {
        p1.bookCards(c1CheckTemp, c2CheckTemp);
        cout << "\n\n" << p1.getName() << "'s books: " << endl;
        cout << p1.showBooks() << endl;
    }
    if(p2.checkHandForBook(c1CheckTemp, c2CheckTemp))  //^^
    {
        p2.bookCards(c1CheckTemp, c2CheckTemp);
        cout << p2.getName() <<"'s' books:" << endl;
        cout << p2.showBooks() << endl;
    }
    //start loop
    //start with player 1
    while(d.size() != 0 )
    {
        do {

            chosen = p1.chooseCardFromHand();
            rank = chosen.getRank();
            cout << p1.getName() << " asks if " << p2.getName() << " has a " << chosen.rankString(rank) << endl; //chooses a card in hand
            if (p2.cardInHand(chosen))  //cardInHand asks for the rank   //asks if other player has the card
            {
                cout << p2.getName() << " says Yes" << endl;
                p1.addCard(p2.removeCardFromHand(chosen));              //if other does, then give to asker

                anotherTurn = true;
            } else  //other does not then go fish
            {
                anotherTurn = false;
                cout << p2.getName() << " says Go Fish!" << endl;
            }

            if (p1.checkHandForBook(c1CheckTemp, c2CheckTemp))   //if pair in hand after add
            {
                p1.bookCards(c1CheckTemp, c2CheckTemp);
                cout << "\n\n" << p1.getName() << "'s books: " << endl;
                cout << p1.showBooks() << endl;
            }

            if(p1.getHandSize() == 0 && d.size() != 0)
            {

                if(d.size() < numCards)
                {
                    newNumCards = d.size();
                } else{
                    newNumCards = numCards;
                }
                dealHand(d, p1, newNumCards);
            }
            if(p2.getHandSize() == 0 && d.size() == 0)
            {
                anotherTurn = false;
            }
        } while (anotherTurn);

        if(d.size() != 0) //fishinggggg
        {
            p1.addCard(d.dealCard());   //go fish is a success
        }

        if (p1.checkHandForBook(c1CheckTemp, c2CheckTemp))   //if pair in hand after add
        {
            p1.bookCards(c1CheckTemp, c2CheckTemp);

            cout << "\n\n" << p1.getName() << "'s books: " << endl;
            cout << p1.showBooks() << endl;
        }

        cout << "Joe's hand: " << p1.showHand() << endl;
        cout << "Jane's hand: " << p2.showHand() << endl;

        do //player 2
        {

            chosen = p2.chooseCardFromHand();
            rank = chosen.getRank();

            cout << p2.getName() << " asks if " << p1.getName() << " has a " << chosen.rankString(rank) << endl; //chooses a card in hand
            if (p1.cardInHand(chosen))                                   //asks if other player has the card
            {
                p2.addCard(p1.removeCardFromHand(chosen));              //if other does, then give to asker
                anotherTurn = true;
            } else  //other does not then go fish
            {
                anotherTurn = false;
                cout << p1.getName() << " says Go Fish!" << endl;
            }

            if (p2.checkHandForBook(c1CheckTemp, c2CheckTemp))   //if pair in hand after add
            {
                p2.bookCards(c1CheckTemp, c2CheckTemp);
                cout << p2.getName() <<"'s' books:" << endl;
                cout << p2.showBooks() << endl;
            }

            if(p2.getHandSize() == 0 && d.size() != 0)
            {

                if(d.size() < numCards)
                {
                    newNumCards = d.size();
                }else{
                    newNumCards = numCards;
                }
                dealHand(d, p2, newNumCards);
            }
            if(p2.getHandSize() == 0 && d.size() == 0)
            {
                anotherTurn = false;
            }
        } while (anotherTurn);

        if(d.size() != 0)
        {
            p2.addCard(d.dealCard());   //go fish is a success
        }
        cout << "Joe's hand: " << p1.showHand() << endl;
        cout << "Jane's hand: " << p2.showHand() << endl;

        if (p2.checkHandForBook(c1CheckTemp, c2CheckTemp))   //if pair in hand after add
        {
            p2.bookCards(c1CheckTemp, c2CheckTemp);
            cout << p2.getName() <<"'s books:" << endl;
            cout << p2.showBooks() << endl;
        }
    }

    cout << "Left in the deck: ";
    d.display();

    //empty deck, must continue asking. when no cards, keep asking until none left




    cout << "\n\n" << p1.getName() << "'s books: " << endl;
    cout << p1.showBooks() << endl;
    cout << "Amount: " << p1.getBookSize() << "\n" << endl;

    cout << p2.getName() <<"'s' books:" << endl;
    cout << p2.showBooks() << endl;
    cout << "Amount: " << p2.getBookSize() << endl;

    cout << p1.getName() << "'s final hand:" << endl;
    cout << p1.showHand() << endl;
    cout << "This is " << p2.getName() << "'s hand:" << endl;
    cout << p2.showHand() << endl;

    if(p1.getHandSize() < p2.getBookSize())
    {
        cout << p2.getName() << " won!!!" << endl;
    }
    else{
        cout << p1.getName() << " won!!!" << endl;
    }
    return 0;


}

void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}