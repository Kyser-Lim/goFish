//
// Created by Kendrick Lim on 4/7/20.
//

#include "player.h"

    Player::Player()
    {
        myName = "Jane";
    }

    void Player::addCard(Card c)
    {
        myHand.push_back(c);
    }

    void Player::bookCards(Card c1, Card c2)
    {
        myBook.push_back(c1);
        myBook.push_back(c2);
        removeCardFromHand(c1);
        removeCardFromHand(c2);

    }

    bool Player::checkHandForBook(Card &c1, Card &c2)
    {
        for (int i = 0; i < myHand.size(); i++) {
            for (int j = i + 1; j < myHand.size(); j++) {

                if(myHand[j] == myHand[i]){
                    c1 = myHand[j];
                    c2 = myHand[i];
                    return true;
                }
            }
        }
        return false;
    }

 //   bool Player::rankInHand(Card c) const
 //   {

//    }

    Card Player::chooseCardFromHand() const
    {
        int randCard = rand() % myHand.size();
        Card chosenCard = myHand[randCard];
        return chosenCard;

    }

    bool Player::cardInHand(Card c) const
    {
        for(int i = 0; i < myHand.size(); i++){
            if(c == myHand[i]){
                return true;
            }
        }
        return false;
    }

    Card Player::removeCardFromHand(Card c)
    {
        for(int i = 0; i < myHand.size(); i++){
            if((c == myHand[i]) && (c.getSuit() == myHand[i].getSuit()))
            {
                swap(myHand[i], myHand.back());
            }
        }
        myHand.pop_back();
    }

    string Player::showHand() const
    {
        string hand = "";
        for (int i = 0; i < myHand.size(); ++i) {
            hand = hand + myHand[i].toString() + " ";
        }

        return hand;

    }

    string Player::showBooks() const
    {
        string book = "";
        for(int i = 0; i < myBook.size(); i++){
            book = book + myBook[i].toString() + " ";
            if(i % 2 == 1){
                book = book + "\n";
            }
        }
        return book;
    }

    int Player::getHandSize() const
    {
        return myHand.size();
    }

    int Player::getBookSize() const
    {
        return myBook.size()/2;
    }

    bool Player::checkHandForPair(Card &c1, Card &c2)
    {}

    bool Player::sameRankInHand(Card c) const
    {}