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
#include <fstream>
#include <stdio.h>

using namespace std;

void dealHand(Deck &d, Player &p, int numCards);

int main()
{
    srand(time(NULL));    //seed time so that it is random

    ofstream myFile;
    myFile.clear();    //so that it is a clean result output each time
    myFile.open("gofish_results.txt");
    if(myFile.is_open())
    {
        cout << "success" << endl;
        myFile << "This is Go Fish!" << endl;
    }
    else{
        cout << "failed to open file" << endl;
    }

    int numCards = 7; //for a two player game
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

    if(p1.checkHandForBook(c1CheckTemp, c2CheckTemp))  //if start with a pair in hand
    {
        p1.bookCards(c1CheckTemp, c2CheckTemp);
        myFile << "\n" << p1.getName() << "'s books: " << endl;
        myFile << p1.showBooks() << endl;
    }

    if(p2.checkHandForBook(c1CheckTemp, c2CheckTemp))  //^^
    {
        p2.bookCards(c1CheckTemp, c2CheckTemp);
        myFile << p2.getName() <<"'s' books:" << endl;
        myFile << p2.showBooks() << endl;
    }


    //start game
    while(d.size() != 0 )
    {
        do //this is player 1's loop
        {
            if(p1.getHandSize() > 0) //to ensure that you do not draw from an empty hand
            {
                chosen = p1.chooseCardFromHand();    //chooses card in hand
                rank = chosen.getRank();
                myFile << p1.getName() << " asks - Do you have a " << chosen.rankString(rank) << endl; //asks a card in hand

                if (p2.cardInHand(chosen))  //cardInHand asks for the rank   //asks if other player has the card
                {
                    myFile << p2.getName() << " says - Yes. I have a " << chosen.rankString(rank) << endl;
                    p1.addCard(p2.removeCardFromHand(chosen));              //if other does, then give to asker
                    anotherTurn = true;
                }
                else  //other does not then go fish
                {
                    anotherTurn = false;
                    myFile << p2.getName() << " says - Go Fish!" << endl;
                }

                if (p1.checkHandForBook(c1CheckTemp, c2CheckTemp))   //if pair in hand after add. This will work if card is chosen correctly
                {
                    p1.bookCards(c1CheckTemp, c2CheckTemp);
                    myFile << "\n\n" << p1.getName() << "'s books: " << endl;
                    myFile << p1.showBooks() << endl;
                }
            }

            if(p1.getHandSize() == 0 && d.size() != 0) //if empty hand and there are still cards in deck, then draw at least 7
            {
                if(d.size() < numCards)    //draw 7 if there is >= 7 cards in deck else draw remaining
                {
                    newNumCards = d.size();
                }
                else
                {
                    newNumCards = numCards;
                }
                dealHand(d, p1, newNumCards);
            }
            if(p2.getHandSize() == 0 && d.size() == 0) //if both are empty, then game over
            {
                anotherTurn = false;
            }
        } while (anotherTurn);

        if(d.size() != 0) //fishing
        {
            p1.addCard(d.dealCard());   //go fish is a success
        }

        if (p1.checkHandForBook(c1CheckTemp, c2CheckTemp))   //if pair in hand after add
        {
            p1.bookCards(c1CheckTemp, c2CheckTemp);
            myFile << p1.getName() << "says - I got the fish!" << endl;
            myFile << "\n\n" << p1.getName() << "'s books: " << endl;
            myFile << p1.showBooks() << endl;
        }


        do //player 2
        {
            if(p2.getHandSize() > 0)
            {
                chosen = p2.chooseCardFromHand();
                rank = chosen.getRank();
                myFile << p2.getName() << " asks - Do you have a " << chosen.rankString(rank) << endl; //chooses a card in hand

                if (p1.cardInHand(chosen))                                   //asks if other player has the card
                {
                    myFile << p1.getName() << " says - Yes. I have a " << chosen.rankString(rank) << endl;
                    p2.addCard(p1.removeCardFromHand(chosen));              //if other does, then give to asker
                    anotherTurn = true;
                }
                else  //other does not then go fish
                {
                    anotherTurn = false;
                    myFile << p1.getName() << " says - Go Fish!" << endl;
                }

                if (p2.checkHandForBook(c1CheckTemp, c2CheckTemp))   //if pair in hand after add
                {
                    p2.bookCards(c1CheckTemp, c2CheckTemp);
                    myFile << p2.getName() << "'s' books:" << endl;
                    myFile << p2.showBooks() << endl;
                }
            }

            if(p2.getHandSize() == 0 && d.size() != 0)
            {

                if(d.size() < numCards)
                {
                    newNumCards = d.size();
                }
                else
                {
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

        if (p2.checkHandForBook(c1CheckTemp, c2CheckTemp))   //if pair in hand after add
        {
            p2.bookCards(c1CheckTemp, c2CheckTemp);
            myFile << p1.getName() << "says - I got the fish!" << endl;
            myFile << p2.getName() <<"'s books:" << endl;
            myFile << p2.showBooks() << endl;
        }
    }

    myFile << "Left in the deck: ";
    d.display();

    //empty deck, must continue asking. when no cards, keep asking until none left




    myFile << "\n\n" << p1.getName() << "'s books: " << endl;
    myFile << p1.showBooks() << endl;
    myFile << "Amount: " << p1.getBookSize() << "\n" << endl;

    myFile << p2.getName() <<"'s' books:" << endl;
    myFile << p2.showBooks() << endl;
    myFile << "Amount: " << p2.getBookSize() << endl;
/*
    cout << p1.getName() << "'s final hand:" << endl;
    cout << p1.showHand() << endl;
    cout << "This is " << p2.getName() << "'s hand:" << endl;
    cout << p2.showHand() << endl;
*/
    if(p1.getBookSize() < p2.getBookSize())
    {
        myFile << p2.getName() << " won!!!" << endl;
    }
    else if(p1.getBookSize() == p2.getBookSize())
    {
        myFile << p1.getName() << " and " << p2.getName() << " tied." << endl;
    }
    else
    {
        myFile << p1.getName() << " won!!!" << endl;
    }

    myFile.close();
    return 0;


}

void dealHand(Deck &d, Player &p, int numCards)
{
    for (int i=0; i < numCards; i++)
        p.addCard(d.dealCard());
}