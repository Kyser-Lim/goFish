//
// Created by Kendrick Lim on 4/7/20.
//

#include "deck.h"
#include <vector>
#include <stdlib.h>

    Deck::Deck()
    {
        myIndex = 52;
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
        srand(time_t(NULL)); //random set of number

        for(int i = 0; i < myIndex; i++)
        {
            randIndex = rand() % myIndex; //gets a number within 0 and 52
            swap(i, randIndex);
        }
    }

    Card Deck::dealCard()
    {
        cout << "this is your index" << myIndex << endl;

        myIndex = myIndex - 1;
        cout << "this is your index2" << myIndex << endl;

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

    void Deck::display()
    {
        for(int i = 0; i<myIndex; i++)
        {
            cout << myCards[i] << endl;
        }
    }

