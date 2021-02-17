#ifndef CARDDECK_H
#define CARDDECK_H

#include "std_lib_facilities.h"
#include "card.h"


class CardDeck {
private:
    vector<Card> cards;
public:
    CardDeck();
    void swap(int a, int b);
    void print();
    void printShort();
    void shuffle();
    void addDeck();
    Card drawCard();
    int returnSize();
};

#endif