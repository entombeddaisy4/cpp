#include "std_lib_facilities.h"
#include "card.h"
#include "CardDeck.h"
#include "BlackJack.h"

Player::Player(string n): name{n}
{}
void Player::addCard(Card a){
    hand.push_back(a);
}
string Player::getName(){
    return name;
}
void Player::printHand(){
    for(int i = 0; i < hand.size(); i++) {
        cout << hand[i].toString() << endl;
    }
}

void Player::printDealer(){
    cout << "Dealer's card: " << hand[0].toString() << endl;
}

int Player::getValue(){
    int value = 0;
    for(int i = 0; i < hand.size(); i++) {
        value += static_cast<int>(hand[i].getRank());
    }
    if (value > 21) {
        for(int i = 0; i < hand.size(); i++) {
            if (hand[i].getRank() == Rank::ace) {
                value -= 10;
            }
        }
    }
    return value;
}

void Player::clearHand() {
    hand.clear();
    status = "playing";
}




BlackJack::BlackJack() {
    int nPlayers;
    int nDecks;
    cout << "How many players? ";
    cin >> nPlayers;
    cout << "How many decks?";
    cin >> nDecks;

    for (int i = 1; i <= nPlayers; i++) {
        string playerName;
        cout << "Enter name of Player " << i << ": ";
        cin >> playerName;
        players.push_back(Player(playerName));
    }
    CardDeck deck;
    for (int i = 1; i< nDecks; i++) {
        deck.addDeck();
    }
    deck.shuffle();
    Player dealer{"dealer"};


    while (true) {
        for (int i = 0; i <= players.size()-1; i++) {
            players[i].addCard(deck.drawCard());
        }
        dealer.addCard(deck.drawCard());
        for (int i = 0; i <= players.size()-1; i++) {
            players[i].addCard(deck.drawCard());
        }
        dealer.addCard(deck.drawCard());
        
        dealer.printDealer();

        while (true) {
            for (int i = 0; i < players.size(); i++) {
                cout << players[i].getName() << "'s turn!" << endl;
                cout << "Hand:" << endl;
                players[i].printHand();
                cout << "Value: " << players[i].getValue() << endl;
                if (players[i].getValue() > 21) {
                    cout << players[i].getName() << " lost!" << endl;
                    players[i].status = "lost";
                } else if (players[i].status == "holding" or players[i].status == "lost") {
                    cout << players[i].getName() << ": " << players[i].status << endl;
                    if (winValue < players[i].getValue() and players[i].getValue() <= 21) {
                        winValue = players[i].getValue();
                        winPlayer = players[i].getName();
                    }
                } else if (players[i].getValue() < 21) {
                    char choice = 'n';
                    cout << "Would you like to draw another card? (y/n, default n)";
                    cin >> choice;
                    playing = 1;
                    switch (choice)
                    {
                    case 'y':
                        players[i].addCard(deck.drawCard());
                        if (winValue < players[i].getValue() and players[i].getValue() <= 21) {
                            winValue = players[i].getValue();
                            winPlayer = players[i].getName();
                        }
                        break;
                    
                    default:
                        players[i].status = "holding";
                        break;
                    }
                }
            }
            cout << "Dealers hand: " << endl;
            dealer.printHand();
            cout << "Value: " << dealer.getValue() << endl;
            if (dealer.getValue() < 17) {
                playing = 1;
                dealer.addCard(deck.drawCard());
                cout << "Dealer drew a card." << endl;
            }
            if (winValue <= dealer.getValue() and dealer.getValue() < 21) {
                        winValue = dealer.getValue();
                        winPlayer = "Dealer";
                    }
            if (playing == 0) {
                cout << "\" \033[;32m " << winPlayer << " won! \033[0m\n" << endl;
                for (int i = 0; i < players.size(); i++) {
                    players[i].clearHand();
                }
                dealer.clearHand();
                break;
            }
            playing = 0;
        }
        if (deck.returnSize() < 20) {
            cout << "The game is over." << endl;
            break;
        } else {
            cout <<  "New game starting" << endl;
        }
    }
}