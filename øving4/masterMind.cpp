#include "masterMind.h"
#include "utilities.h"
#include "tests.h"

void playMastermind() {
    constexpr int size = 4;
    constexpr int letters = 6;
    int maxGuesses = 5;
    int currentGuesses = 0;
    int correctChars = 0;
    int correctPos = 0;
    string code = randomizeString(size, 'A', 'A'+letters-1);
    while (true) {
        string guess = readInputToString(size, 'A', 'A'+letters-1);
        correctChars = checkCharacters(guess, code);
        correctPos = checkCharactersAndPosition(guess, code);
        if (correctPos == size) {
            cout << "You won!" << endl;
            return;
        }
        cout << "You guessed " << correctChars << " letters correctly. " << correctPos << " of them were in the correct position." << endl;
        currentGuesses++;
        if (currentGuesses == maxGuesses) {
            cout << "You lost" << endl;
            return;
        }
    }
}

int checkCharactersAndPosition(string guess, string code) {
    int correct = 0;
    for (int i = 0; i < guess.length(); i++) {
        if (guess[i] == code[i]) {
            correct++;
        }
    }
    return correct;
}

int checkCharacters(string guess, string code) {
    int correct = 0;
    for (int i = 0; i < guess.length(); i++) {
        for (int j = 0; j < code.length(); j++) {
            if (code[j] == guess[i]) {
                code[j] = '0';
                correct++;
                break;
            }
        }
    }
    return correct;
}