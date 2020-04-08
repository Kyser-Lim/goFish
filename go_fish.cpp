//
// Created by Daniel Masud on 4/8/2020.
//
#include "card.h"
int main()
{
    Card::Suit s = Card::hearts;
    Card::Suit s2 = Card::clubs;
    Card card1;
    Card card2(12, s);
    Card card3(12,s2);
    Card card4(12, s);
    string card = card1.toString();

    cout << "this is your card1 " << card << endl;
    cout << "this is your card2" << card2 << endl;
    if(card2 != card3){
        cout << "Card2 is different from card3" << endl;
    }
    if(card2 == card4){
        cout << "Card2 is the same as Card4" << endl;
    }


    return 0;


}