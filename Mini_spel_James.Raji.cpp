#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main() {
    int highScore = 0;
    ifstream inFile("score.txt");
    if (inFile) inFile >> highScore; // Ladda tidigare högsta poäng
    inFile.close();

    cout << "Välkommen till Gissa Numret-spelet! Högsta poäng: " << highScore << endl;

    int oddNumbers[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int numberToGuess = oddNumbers[rand() % 8];
    int guess, attempts = 0;

    cout << "Gissa det udda numret mellan 1 och 15: ";
    while (cin >> guess) {
        attempts++;
        if (guess == numberToGuess) {
            cout << "Rätt! Du gissade på " << attempts << " försök." << endl;
            int score = 100 - attempts * 10;
            if (score > highScore) {
                ofstream outFile("score.txt");
                outFile << score; // Spara ny högsta poäng
                outFile.close();
                cout << "Ny högsta poäng: " << score << endl;
            }
            break;
        } else if (guess < numberToGuess) {
            cout << "För lågt! Försök igen: ";
        } else {
            cout << "För högt! Försök igen: ";
        }
    }

    cout << "Tack för att du spelade!" << endl;
    return 0;
}
