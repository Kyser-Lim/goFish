//
// Created by Kendrick Lim on 4/7/20.
//

#include "deck.h"
#include <vector>
#include <stdlib.h>
#include <time.h>

    Deck::Deck()
    {
        myIndex = 52;    //this initializes a deck
        int rank = 1;

        for(int i = 0; i < 13; i++)
        {
            myCards[i] = Card(rank, Card::spades);
            rank++;
        }

        rank = 1;

        for(int i = 13; i < 26; i++)
        {
            myCards[i] = Card(rank, Card::hearts);
            rank++;
        }
        rank = 1;

        for(int i = 26; i < 39; i++)
        {
            myCards[i] = Card(rank, Card::diamonds);
            rank++;
        }

        rank = 1;

        for(int i = 39; i < 52; i++)
        {
            myCards[i] = Card(rank, Card::clubs);
            rank++;
        }
    }

    void Deck::shuffle()
    {
        int randIndex;
        for(int i = 0; i < myIndex; i++)
        {
            randIndex = rand() % myIndex; //gets a number within 0 and 52
            swap(i, randIndex);
        }
    }

    Card Deck::dealCard()
    {
        myIndex = myIndex - 1;
        return myCards[myIndex];
    }

    int Deck::size() const
    {
        return myIndex;
    }

    void Deck::swap(int index1, int index2)
    {
        Card temp = Card();
        temp = myCards[index1];
        myCards[index1] = myCards[index2];
        myCards[index2] = temp;
    }

    void Deck::display() //extra function to display deck... debugging purpose
    {
        int x = 1;

        for(int i = 0; i< myIndex; i++)
        {
            cout << x << myCards[i] << endl;
            x++;
        }
    }

