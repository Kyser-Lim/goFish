//
// Created by Kendrick Lim on 4/7/20.
//

#include "deck.h"
#include <vector>
#include <stdlib.h>

    Deck::Deck()
    {
        int myIndex = 52;
        int rank = 1;

        for(int i = 0; i < 13; i++)
        {
            myCards[i] = Card(rank, Card::spades);
        }

        rank = 0;

        for(int i = 13; i < 26; i++)
        {
            myCards[i] = Card(rank, Card::hearts);
        }
        rank = 0;

        for(int i = 26; i < 39; i++)
        {
            myCards[i] = Card(rank, Card::diamonds);
        }

        rank = 0;

        for(int i = 39; i < 52; i++)
        {
            myCards[i] = Card(rank, Card::clubs);
        }
    }

    void Deck::shuffle()
    {
        int randIndex;
        srand(time_t(NULL)); //random set of number

        for(int i = 0; i < 52; i++)
        {
            randIndex = rand() % 52; //gets a number within 0 and 52
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
        return 52;
    }

    void Deck::swap(int index1, int index2)
    {
        Card temp = Card();
        temp = myCards[index1];
        myCards[index1] = myCards[index2];
        myCards[index2] = temp;
    }

    