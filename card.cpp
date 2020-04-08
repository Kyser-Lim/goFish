//
// Created by Daniel Masud on 4/8/2020.
//

#include "card.h"
#include <string>
#include <iostream>


Card::Card(){

    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Card::Suit s) {

    myRank = rank;
    mySuit = s;
}

string Card::toString() const {

    string rank = rankString(myRank);
    if(!(stoi(rank) > 1 && stoi(rank) < 11)){
        switch(stoi(rank)){
            case 1 : rank = "A";
            break;
            case 11 : rank = "J";
            break;
            case 12 : rank = "Q";
            break;
            case 13 : rank = "K";
            break;
        }
    }
    string suit = suitString(mySuit);
    string card = rank + suit;
    return card;
}

bool Card::sameSuitAs(const Card &c) const {

    if(mySuit == c.mySuit){
        return true;
    }

    return false;

}

int Card::getRank() const {
    return myRank;
}

string Card::getSuit() const {
    switch(int(mySuit)){

        case 0: return "s";

        case 1: return "h";

        case 2: return "d";

        case 3: return "c";
    }
}

string Card::suitString(Card::Suit s) const {

    switch(int(s)){

        case 0: return "s";

        case 1: return "h";

        case 2: return "d";

        case 3: return "c";
    }
}

string Card::rankString(int r) const {

    string rank = std::to_string(static_cast<long long> (r));
    return rank;

}

bool Card::operator==(const Card &rhs) const {

    if((myRank == rhs.getRank()) && (mySuit == rhs.mySuit)){
        return true;
    }

    return false;
}

bool Card::operator!=(const Card &rhs) const {

    if((myRank != rhs.getRank()) || (mySuit != rhs.mySuit)){
        return true;
    }
    return false;
}

ostream& operator << (ostream& out, const Card& c){

    string card = c.toString();

    out << " " << card;
    return out;
}
