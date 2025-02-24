#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//Exercitiul 1

/*class DFA {
private:
    unordered_map<string, unordered_map<char, string>> transitie;
    string initialState;
    string currentState;
    string finalState;

public:
    DFA() {
        transitie["q0"]['0'] = "q1";
        transitie["q0"]['1'] = "q0";
        transitie["q1"]['0'] = "q3";
        transitie["q1"]['1'] = "q0";
        transitie["q2"]['0'] = "q3";
        transitie["q2"]['1'] = "q1";
        transitie["q3"]['0'] = "q3";
        transitie["q3"]['1'] = "q3";

        // Setarea starii initiale si finale
        initialState = "q0";
        finalState = "q3";
        currentState = initialState;
    }

    void reset() {
        currentState = initialState;
    }

    bool process(string input) {
        reset();  // Reseteaza automatul la starea initiala
        for (char c : input) {
            if (transitie[currentState].find(c) != transitie[currentState].end()) {
                currentState = transitie[currentState][c];
            }
            else {
                return false;  // Simbol invalid
            }
        }
        return (currentState == finalState);  // Verifica daca s-a ajuns in starea finala
    }
};

int main() {
    DFA dfa;
    string testStrings[] = { "00", "01", "10", "110", "000", "101" };

    for (const string& s : testStrings) {
        cout << "Cuvant: " << s << " -> "
            << (dfa.process(s) ? "Acceptat" : "Respins") << endl;
    }

    return 0;
} */

// Exercitiul 2

/*bool contineCat(const string& text)
{
    int state = 0;
    for (char ch : text) {
        switch (state) {

        case 0: //Stare initiala q0
            if (ch == 'c') state = 1;  //Tranzitia spre q1
            else state = 0;
            break;

        case 1:
            if (ch == 'a') state = 2;  //Tranzitia spre q2
            else if (ch == 'c') state = 1;
            else state = 0;
            break;

        case 2:
            if (ch == 't') return true;
            else if (ch == 'c') state = 1;
            else state = 0;
            break;

        }
    }
    return false; //Cuvantul dat "cat" nu a fost gasit 
}
int main() {
    string text;
    cout << "Introduceti textul:" << endl;
    getline(cin, text);

    if (contineCat(text)) {
        cout << "Cuvantul **cat** cautat a fost gasit in text." << endl;
    }
    else {
        cout << "Cuvantul **cat** cautat nu a fost gasit in text." << endl;
    }
    return 0;
}*/

//Exercitiul 3

class DFA {
private:
    unordered_map<string, unordered_map<char, string>> transitie;
    string currentState;
    string finalState;

public:
    DFA() {
        transitie["q0"] = { {'a', "q1"}, {'b', "q0"}, {'c', "q0"}, {'d', "q0"} };
        transitie["q1"] = { {'a', "q1"}, {'b', "q2"}, {'c', "q1"}, {'d', "q1"} };
        transitie["q2"] = { {'a', "q2"}, {'b', "q2"}, {'c', "q2"}, {'d', "q3"} };
        transitie["q3"] = { {'a', "q3"}, {'b', "q3"}, {'c', "q3"}, {'d', "q3"} };

        currentState = "q0";
        finalState = "q3";
    }

    void reset() {
        currentState = "q0";
    }

    bool process(string input) {
        reset();  // Reset la starea initiala
        for (char c : input) {
            if (transitie[currentState].find(c) != transitie[currentState].end()) {
                currentState = transitie[currentState][c];
            }
            else {
                return false;  // Simbol invalid
            }
        }
        return (currentState == finalState); 
    }
};

int main() {
    DFA dfa;
    string testStrings[] = { "aabbcc", "bbaacc", "ccddee", "abcdab", "aabbc" };

    for (const string& s : testStrings) {
        cout << "Cuvant: " << s << " -> "
            << (dfa.process(s) ? "Acceptat" : "Respins") << endl;
    }

    return 0;
}

