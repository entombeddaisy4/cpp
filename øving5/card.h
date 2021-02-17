#ifndef CARD_H
#define CARD_H
#include "std_lib_facilities.h"


enum class Suit {
    clubs,
    diamonds,
    hearts,
    spades
};

enum class Rank {
    two=2,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack=10,
    queen=10,
    king=10,
    ace=11
};

class Card {
private:
    Suit s;
    Rank r;
public:
    Card(Suit suit, Rank rank);
    Suit getSuit();
    Rank getRank();
    string toString();
    string toStringShort();
};

string suitToString(Suit s);
string rankToString(Rank r);

#endif