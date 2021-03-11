#include "std_lib_facilities.h"
#include "Animal.h"
#include "Graph.h"
#include "Simple_window.h"
#include "Emoji.h"
//------------------------------------------------------------------------------
//
// Protected fungerer som private medlemsvariabler, men kan arves til andre klasser
// Private kan bare kalles av medlemsfunksjoner og konstruktører
// Public kan kalles og endres fra utenfor klassen og kan arves
//
//------------------------------------------------------------------------------
void testAnimal() {
	//Animal beethoven("Ludwig", 251);
	Dog mozart("Wolfgang", 265);
	Cat bach("Johan Sebastian", 336);

	Graph_lib::Vector_ref<Animal> Animals;
	//Animals.push_back(beethoven);
	Animals.push_back(mozart);
	Animals.push_back(bach);

	for (int i = 0; i < Animals.size(); i++) {
		cout << Animals[i].toString() << endl;
	}
}

//emoji_main


//------------------------------------------------------------------------------
int main()
{
	constexpr int xmax = 1000;
	constexpr int ymax = 600;
	constexpr int emojiRadius = 50;

	testAnimal();
	using namespace Graph_lib;

	const Point tl{100, 100};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};

	/* TODO:
	 *  - initialize emojis
	 *  - connect emojis to window
	 **/

	Smiley hore{tl, emojiRadius};
	hore.attach_to(win);
	win.wait_for_button();  
}

//------------------------------------------------------------------------------
