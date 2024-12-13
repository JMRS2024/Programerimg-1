#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Funktion som visar regler för spelet
void visaRegler() {
    cout << "\n____Välkommen till 'Stensaxpåse'!____" << endl;
    cout << "\nDu Spelar med JMR" << endl;
    cout << "Spelets regler:" << endl;
    cout << "1. Välj mellan sten, sax och påse." << endl;
    cout << "2. JMR kommer att göra sitt val." << endl;
    cout << "3. Regler: Sten slår sax, sax slår påse, påse slår sten." << endl;
    cout << "4. Den som vinner flest omgångar vinner spelet." << endl;
    cout << "Lycka till!\n" << endl;
}

// Funktion som genererar JMRs val
string JMRVal() {
    int val = rand() % 3; // Slumpar mellan 0, 1 och 2
    if (val == 0) return "sten";
    if (val == 1) return "sax";
    return "påse";
}

// Funktion som avgör vinnaren
string avgörVinnare(string spelare, string JMR) {
    if (spelare == JMR) return "oavgjort";
    if ((spelare == "sten" && JMR == "sax") ||
        (spelare == "sax" && JMR == "påse") ||
        (spelare == "påse" && JMR == "sten")) {
        return "spelare";
    }
    return "JMR";
}

// Huvudprogram
int main() {
    srand(static_cast<unsigned int>(time(0))); // Initierar slumpgenerator

    visaRegler(); // Visa regler för spelaren

    int spelarePoäng = 0;
    int JMRPoäng = 0;
    char spelaIgen;

    do {
        string spelareVal;
        cout << "\nVälj sten, sax eller påse: ";
        cin >> spelareVal;

        // Kontrollera giltigt val
        while (spelareVal != "sten" && spelareVal != "sax" && spelareVal != "påse") {
            cout << "Ogiltigt val. Välj sten, sax eller påse: ";
            cin >> spelareVal;
        }

        string JMRsVal = JMRVal();
        cout << "JMR valde: " << JMRsVal << endl;

        string vinnare = avgörVinnare(spelareVal, JMRsVal);
        if (vinnare == "spelare") {
            cout << "Du vann denna omgång!" << endl;
            spelarePoäng++;
        } else if (vinnare == "JMR") {
            cout << "JMR vann denna omgång." << endl;
            JMRPoäng++;
        } else {
            cout << "Det blev oavgjort!" << endl;
        }

        cout << "Ställning: Du " << spelarePoäng << " - " << JMRPoäng << " JMR" << endl;

        cout << "Vill du spela igen? (j/n): ";
        cin >> spelaIgen;
    while (spelaIgen != 'j' && spelaIgen != 'J' && spelaIgen != 'n' && spelaIgen != 'N')           {cout << "Ogiltigt val. Vänligen ange 'j' för ja eller 'n' för nej:";
         cin >> spelaIgen; }
            
    } while (spelaIgen == 'j' || spelaIgen == 'J');

    cout << "\nSlutresultat: Du " << spelarePoäng << " - " << JMRPoäng << " JMR" << endl;
    if (spelarePoäng > JMRPoäng) {
        cout << "Grattis! Du vann spelet!" << endl;
    } else if (JMRPoäng > spelarePoäng) {
        cout << "JMR vann spelet. Bättre lycka nästa gång!" << endl;
    } else {
        cout << "Spelet slutade oavgjort." << endl;
    }

    return 0;
}
