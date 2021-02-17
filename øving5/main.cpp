#include "std_lib_facilities.h"
#include "card.h"
#include "CardDeck.h"
#include "BlackJack.h"

/*
	Oppgave 1e, Teori

	?????????????
*/



int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	int menuFunc = -1;
	while (true) {
		cout << "0) Exit\n";
		cout << "1) Play Blackjack\n";
		cout << "2) Test\n";

		cout << "Choose function: \n";
		cin >> menuFunc;

		switch (menuFunc) {
			case 0:
				return 0;
			case 1:{
				BlackJack j;
				break;
			}
			case 2: {
				CardDeck d;
				//d.shuffle();
				d.addDeck();
				d.print();
				d.printShort();
				Card c{Suit::spades, Rank::ace};
				cout << c.toString() << '\n';
				cout << c.toStringShort() << '\n';
				break;
			}
			default:
				cout << "Invalid input\n";
				break;
		}
	}
}
