#include "std_lib_facilities.h"
#include "CardDeck.h"
#include "card.h"
#include "utilities.h"

CardDeck::CardDeck(): cards{}
{
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
    map<Suit, string> suitMap {
    {Suit::clubs, "Clubs"},
    {Suit::diamonds, "Diamonds"},
    {Suit::hearts, "Hearts"},
    {Suit::spades, "Spades"}
    };
    for(const auto& s:suitMap) {
        for(const auto& r:rankMap) {
            cards.push_back(Card {s.first, r.first});
        }
    }
}

void CardDeck::swap(int a,int b) {
    Card temp = cards[a];
    cards[a] = cards[b];
    cards[b] = temp;
}

void CardDeck::print() {
    for (int i = 0; i < cards.size(); i++) {
        cout << cards[i].toString() << endl;
    }
}
void CardDeck::printShort() {
    for (int i = 0; i < cards.size(); i++) {
        cout << cards[i].toStringShort() << endl;
    }
}

void CardDeck::shuffle() {
    for (int i = 0; i < cards.size()*5; i++) {
        CardDeck::swap(0, randomWithLimits(1, cards.size()-1));
    }
}

void CardDeck::addDeck() {
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
    map<Suit, string> suitMap {
    {Suit::clubs, "Clubs"},
    {Suit::diamonds, "Diamonds"},
    {Suit::hearts, "Hearts"},
    {Suit::spades, "Spades"}
    };
    for(const auto& s:suitMap) {
        for(const auto& r:rankMap) {
            cards.push_back(Card {s.first, r.first});
        }
    }
}

Card CardDeck::drawCard() {
    Card temp = cards.back();
    cards.pop_back();
    return temp;
}

int CardDeck::returnSize() {
    return cards.size();
}