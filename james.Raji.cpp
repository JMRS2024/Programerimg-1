#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Artikel {
    int artikelnummer;
    string namn;
    int antal;
    double pris;
};
void skrivUtLagerLista(const vector<Artikel>& lager);
void sokArtikel(const vector<Artikel>& lager);
void redigeraArtikel(vector<Artikel>& lager);

int main() {
    vector<Artikel> lager = {
        {1, "Hammare", 50, 129.99},
        {2, "Spiklåda", 200, 89.50},
        {3, "Skruvmejsel", 75, 79.00}
    };

    int val;
    do {
    
        cout << "\n--- Laghanteringsprogram ---\n";
        cout << endl;
        cout <<"Vänligen välja en av följande val"<<endl;
        cout << endl;
        cout << "1. Skriv ut lagerlista\n";
        cout << endl;
        cout << "2. Sök artikel\n";
        cout << endl;
        cout << "3. Redigera artikel\n";
        cout << endl;
        cout << "4. Avsluta programmet\n";
        cout << endl;
        cout << "Välj ett alternativ: ";
        cout << endl;
        cin >> val;

    
        switch (val) {
        case 1:
            skrivUtLagerLista(lager);
            break;
        case 2:
            sokArtikel(lager);
            break;
        case 3:
            redigeraArtikel(lager);
            break;
        case 4:
            cout << "Avslutar programmet...\n";
            break;
        default:
            cout << "Ogiltigt val, försök igen.\n";
        }
    } while (val != 4);

    return 0;
}


void skrivUtLagerLista(const vector<Artikel>& lager) {
    cout << "\n--- Lagerlista ---\n";
    for (const auto& artikel : lager) {
        cout << "Artikelnummer: " << artikel.artikelnummer
             << ", Namn: " << artikel.namn
             << ", Antal: " << artikel.antal
             << ", Pris: " << artikel.pris << " SEK\n";
    }
}


void sokArtikel(const vector<Artikel>& lager) {
    int sokNummer;
    cout << "\nAnge artikelnummer att söka efter: ";
    cin >> sokNummer;

    bool hittad = false;
    for (const auto& artikel : lager) {
        if (artikel.artikelnummer == sokNummer) {
            cout << "Hittad artikel:\n";
            cout << "Artikelnummer: " << artikel.artikelnummer
                 << ", Namn: " << artikel.namn
                 << ", Antal: " << artikel.antal
                 << ", Pris: " << artikel.pris << " SEK\n";
            hittad = true;
            break;
        }
    }

    if (!hittad) {
        cout << "Ingen artikel med artikelnummer " << sokNummer << " hittades.\n";
    }
}


void redigeraArtikel(vector<Artikel>& lager) {
    int redigeraNummer;
    cout << "\nAnge artikelnummer att redigera: ";
    cin >> redigeraNummer;

    for (auto& artikel : lager) {
        if (artikel.artikelnummer == redigeraNummer) {
            cout << "Redigera artikel:\n";
            cout << "Nuvarande namn: " << artikel.namn << ", nytt namn: ";
            cin.ignore();
            getline(cin, artikel.namn);

            cout << "Nuvarande antal: " << artikel.antal << ", nytt antal: ";
            cin >> artikel.antal;

            cout << "Nuvarande pris: " << artikel.pris << " SEK, nytt pris: ";
            cin >> artikel.pris;

            cout << "Artikeln har uppdaterats.\n";
            return;
        }
    }

    cout << "Ingen artikel med artikelnummer " << redigeraNummer << " hittades.\n";
}
