#include "std_lib_facilities.h"
#include "card.h"

/*
map<Suit, string> suitToString {
    {Suit::clubs, "Clubs"},
    {Suit::diamonds, "Diamonds"},
    {Suit::hearts, "Hearts"},
    {Suit::spades, "Spades"}
};
*/

string suitToString(Suit s) {
    map<Suit, string> suitMap {
    {Suit::clubs, "Clubs"},
    {Suit::diamonds, "Diamonds"},
    {Suit::hearts, "Hearts"},
    {Suit::spades, "Spades"}
    };
    string suit = suitMap[s];
    return suit;
}

string rankToString(Rank r) {
    map<Rank, string> rankMap {
    {Rank::two, "Two"},
    {Rank::three, "Three"},
    {Rank::four, "Four"},
    {Rank::five, "Five"},
    {Rank::six, "Six"},
    {Rank::seven, "Seven"},
    {Rank::eight, "Eight"},
    {Rank::nine, "nine"},
    {Rank::ten, "Ten"},
    {Rank::jack, "Jack"},
    {Rank::queen, "Queen"},
    {Rank::king, "King"},
    {Rank::ace, "Ace"},
    };
    string rank = rankMap[r];
    return rank;
}

Card::Card(Suit suit, Rank rank): s{suit}, r{rank}
{}
Suit Card::getSuit() {
    return Card::s;
}
Rank Card::getRank() {
    return Card::r;
}
string Card::toString() {
    Suit s = Card::getSuit();
    Rank r = Card::getRank();
    string suit = suitToString(s);
    string rank = rankToString(r);
    return (rank + " of " + suit);
}

string Card::toStringShort() {
    Suit s = Card::getSuit();
    Rank r = Card::getRank();
    string suit = suitToString(s);
    int rank = static_cast<int>(r);
    ostringstream os;
    os << suit[0] << rank;
    return os.str();
}
