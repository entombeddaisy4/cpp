#include "std_lib_facilities.h"
#include "card.h"
#include "CardDeck.h"

class Player {
private:
    vector<Card> hand;
    string name;
public:
    Player(string n);
    void addCard(Card a);
    string getName();
    int getValue();
    void printHand();
    void printDealer();
    string status = "playing";
    void clearHand();
};


class BlackJack {
private:
    vector<Player> players;
    CardDeck deck;
    int playing = 0;
    int winValue = 0;
    string winPlayer;
public:
    BlackJack();
};
