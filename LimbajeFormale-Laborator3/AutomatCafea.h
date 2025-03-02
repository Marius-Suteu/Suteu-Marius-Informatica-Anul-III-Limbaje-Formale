#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;
/*
enum Stare {
    q0, // Stare initiala
    q1, // Cafea selectata
    q2, // Ceai selectat
    q3, // Cappuccino selectat
    q4  // Bautura livrata
};

class AutomatCafea {
private:
    Stare stareCurenta; 

public:
    AutomatCafea() {
        stareCurenta = q0;
    }

    void selecteazaBautura(char input) {
        if (stareCurenta == q0) {
            switch (input) {
            case 'C':
                stareCurenta = q1;
                cout << "Ati selectat: Cafea.\n";
                break;
            case 'T':
                stareCurenta = q2;
                cout << "Ati selectat: Ceai.\n";
                break;
            case 'A':
                stareCurenta = q3;
                cout << "Ati selectat: Cappuccino.\n";
                break;
            case 'H':
                stareCurenta = q4; 
                cout << "Ati selectat: Ciocolata calda. Livram bautura...\n";
                resetAutomat();
                return;
            default:
                cout << "Selectie invalida! Alege C, T, A sau H.\n";
                return;
            }
        }
        else {
            cout << "Trebuie sa apesi Y pentru a confirma alegerea!\n";
        }
    }

    void confirmaSelectia() {
        if (stareCurenta == q1 || stareCurenta == q2 || stareCurenta == q3) {
            cout << "Bautura este pregatita. Livram...\n";
            stareCurenta = q4; 
        }
        else if (stareCurenta == q4) {
            cout << "Revenim la meniul principal...\n";
            resetAutomat();
        }
        else {
            cout << "Nu ai selectat nicio bautura!\n";
        }
    }
    void resetAutomat() {
        stareCurenta = q0;
        cout << "Alege o bautura: (C - Cafea, T - Ceai, A - Cappuccino, H - Ciocolata calda)\n";
    }
};

int main() {
    AutomatCafea automat;
    char optiune;

    cout << "*** Automat de cafea ***\n";
    automat.resetAutomat();

    while (true) {
        cout << "Introdu comanda: ";
        cin >> optiune;

        if (optiune == 'Q') {
            cout << "Oprire automat.\n";
            break;
        }
        else if (optiune == 'Y') {
            automat.confirmaSelectia();
        }
        else {
            automat.selecteazaBautura(optiune);
        }
    }

    return 0;
} */


// Exercitiul 2

/*class ParkingLot {
private:
    set<int> availableSpots;
    set<int> occupiedSpots;
    int capacity;

public:
    ParkingLot(int size) : capacity(size) {
        for (int i = 1; i <= size; i++) {
            availableSpots.insert(i);
        }
    }

    void displayStatus() {
        cout << "\nLocuri libere: ";
        for (int spot : availableSpots) {
            cout << spot << " ";
        }
        cout << "\nLocuri ocupate: ";
        for (int spot : occupiedSpots) {
            cout << spot << " ";
        }
        cout << endl;
    }

    bool parkCar() {
        if (availableSpots.empty()) {
            cout << "Parcarea este plina!\n";
            return false;
        }
        int spot = *availableSpots.begin();
        availableSpots.erase(spot);
        occupiedSpots.insert(spot);
        cout << "Masina a fost parcata pe locul " << spot << ".\n";
        return true;
    }

    bool leaveParking(int spotNumber) {
        if (occupiedSpots.find(spotNumber) == occupiedSpots.end()) {
            cout << "Locul " << spotNumber << " este deja liber sau invalid!\n";
            return false;
        }
        occupiedSpots.erase(spotNumber);
        availableSpots.insert(spotNumber);
        cout << "Masina a parasit locul " << spotNumber << ".\n";
        return true;
    }
};

int main() {
    int size;
    cout << "Introduceti numarul de locuri de parcare: ";
    cin >> size;
    ParkingLot lot(size);

    int choice, spot;
    do {
        cout << "\nMeniu:\n1. Vezi starea parcarii\n2. Parcheaza o masina\n3. Pleaca din parcare\n4. Iesire\nAlegeti o optiune: ";
        cin >> choice;

        switch (choice) {
        case 1:
            lot.displayStatus();
            break;
        case 2:
            lot.parkCar();
            break;
        case 3:
            cout << "Introduceti numarul locului din care plecati: ";
            cin >> spot;
            lot.leaveParking(spot);
            break;
        case 4:
            cout << "Iesire...\n";
            break;
        default:
            cout << "Optiune invalida!\n";
        }
    } while (choice != 4);

    return 0;
}*/


//Exercitiul 3


// Structura pentru NFA
struct NFA {
    set<int> states;
    set<char> alphabet;
    map<int, map<char, set<int>>> transitions;
    int startState;
    set<int> finalStates;
};

// Structura pentru DFA
struct DFA {
    set<set<int>> states;
    set<char> alphabet;
    map<set<int>, map<char, set<int>>> transitions;
    set<int> startState;
    set<set<int>> finalStates;
};

// Functie de conversie NFA -> DFA
DFA convertNFAtoDFA(NFA& nfa) {
    DFA dfa;
    dfa.alphabet = nfa.alphabet;
    queue<set<int>> stateQueue;
    set<set<int>> processedStates;

    set<int> startSet = { nfa.startState };
    dfa.startState = startSet;
    stateQueue.push(startSet);
    processedStates.insert(startSet);
    dfa.states.insert(startSet);

    while (!stateQueue.empty()) {
        set<int> currentState = stateQueue.front();
        stateQueue.pop();

        for (char symbol : nfa.alphabet) {
            set<int> newState;

            for (int state : currentState) {
                if (nfa.transitions[state].count(symbol)) {
                    newState.insert(nfa.transitions[state][symbol].begin(), nfa.transitions[state][symbol].end());
                }
            }

            if (!newState.empty()) {
                dfa.transitions[currentState][symbol] = newState;

                if (processedStates.find(newState) == processedStates.end()) {
                    processedStates.insert(newState);
                    stateQueue.push(newState);
                    dfa.states.insert(newState);
                }
            }
        }
    }

    for (auto& state : dfa.states) {
        for (int subState : state) {
            if (nfa.finalStates.count(subState)) {
                dfa.finalStates.insert(state);
                break;
            }
        }
    }

    return dfa;
}

// Functie de afisare a DFA-ului
void printDFA(DFA& dfa) {
    cout << "\nStarile DFA:\n";
    for (auto& state : dfa.states) {
        cout << "{";
        for (int s : state) cout << s << " ";
        cout << "} ";
    }
    cout << "\n\nTranzitii:\n";
    for (auto& trans : dfa.transitions) {
        for (auto& entry : trans.second) {
            cout << "{";
            for (int s : trans.first) cout << s << " ";
            cout << "} --" << entry.first << "--> {";
            for (int s : entry.second) cout << s << " ";
            cout << "}\n";
        }
    }
}

int main() {
    NFA nfa;
    nfa.states = { 0, 1, 2 };
    nfa.alphabet = { '0', '1', '2' };
    nfa.startState = 0;
    nfa.finalStates = { 2 };

    // Definim tranzitiile conform schemei NFA
    nfa.transitions[0]['0'] = { 0 };
    nfa.transitions[0]['1'] = { 0, 1 };
    nfa.transitions[0]['2'] = { 0, 1, 2 };
    nfa.transitions[1]['1'] = { 1 };
    nfa.transitions[1]['2'] = { 1, 2 };
    nfa.transitions[2]['2'] = { 2 };

    DFA dfa = convertNFAtoDFA(nfa);
    printDFA(dfa);

    return 0;
}

