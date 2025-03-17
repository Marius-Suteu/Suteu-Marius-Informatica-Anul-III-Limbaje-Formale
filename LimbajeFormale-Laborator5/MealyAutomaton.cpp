#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;

/*class MealyAutomaton {
private:
    enum State { S0, S1 }; 
    State currentState;

public:
    MealyAutomaton() {
        currentState = S0; // Starea initiala este S0
    }

    int transition(int A, int B) {
        int output = 0; // Semnalul de iesire

        // Tranzitii si iesiri conform tabelului
        switch (currentState) {
        case S0:
            if (A == 0 && B == 0) {
                currentState = S0;
                output = 0;
            }
            else if (A == 0 && B == 1) {
                currentState = S1;
                output = 1;
            }
            else if (A == 1 && B == 0) {
                currentState = S0;
                output = 0;
            }
            else if (A == 1 && B == 1) {
                currentState = S1;
                output = 1;
            }
            break;

        case S1:
            if (A == 0 && B == 0) {
                currentState = S1;
                output = 1;
            }
            else if (A == 0 && B == 1) {
                currentState = S1;
                output = 1;
            }
            else if (A == 1 && B == 0) {
                currentState = S0;
                output = 0;
            }
            else if (A == 1 && B == 1) {
                currentState = S0;
                output = 0;
            }
            break;
        }
        return output;
    }
};

int main() {
    MealyAutomaton automaton;
    vector<pair<int, int>> inputs = { {0, 0}, {0, 1}, {1, 0}, {1, 1}, {0, 0}, {0, 1}, {1, 0} };

    cout << "Simulare automat Mealy:" << endl;
    for (auto input : inputs) {
        int output = automaton.transition(input.first, input.second);
        cout << "Intrare: (" << input.first << ", " << input.second << ") -> Iesire: " << output << endl;
    }

    return 0;
} */


// Exercitiul 2

/*class MooreAutomaton {
private:
    enum State { S0_prime, S1_prime }; // Definim starile
    State currentState;

public:
    MooreAutomaton() {
        currentState = S0_prime; // Starea initiala
    }

    void transition(int A, int B) {
        // Iesirea este determinata de stare
        int output = (currentState == S0_prime) ? 0 : 1;
        cout << "Stare: " << (currentState == S0_prime ? "S0'" : "S1'")
            << " -> Iesire: " << output << endl;

        // Tranzitiile conform tabelului
        switch (currentState) {
        case S0_prime:
            if (A == 0 && B == 1) currentState = S1_prime;
            if (A == 1 && B == 1) currentState = S1_prime;
            break;
        case S1_prime:
            if (A == 1 && B == 0) currentState = S0_prime;
            if (A == 1 && B == 1) currentState = S0_prime;
            break;
        }
    }
};

int main() {
    MooreAutomaton automaton;
    vector<pair<int, int>> inputs = { {0, 0}, {0, 1}, {1, 0}, {1, 1}, {0, 0}, {0, 1}, {1, 0} };

    cout << "Simulare automat Moore:" << endl;
    for (auto input : inputs) {
        automaton.transition(input.first, input.second);
    }

    return 0;
} */


//Exercitiul 3

/*class NFA {
private:
    unordered_map<int, unordered_map<char, unordered_set<int>>> transitions;
    unordered_set<int> finalStates;
    int startState;

public:
    NFA() {
        startState = 0;

        // Definim tranzitiile conform diagramei
        transitions[0]['?'].insert(1); // ?-tranzitie catre q1
        transitions[0]['?'].insert(3); // ?-tranzitie catre q3

        transitions[1]['a'].insert(2); // q1 -a-> q2
        finalStates.insert(2); // q2 este stare finala

        transitions[3]['b'].insert(4); // q3 -b-> q4
        transitions[4]['a'].insert(5); // q4 -a-> q5
        transitions[4]['b'].insert(5); // q4 -b-> q5
        transitions[5]['a'].insert(5); // q5 -a-> q5 
        transitions[5]['b'].insert(5); // q5 -b-> q5 
        finalStates.insert(5); // q5 este stare finala
    }

    void simulate(const string& input) {
        unordered_set<int> currentStates = { startState };
        applyEpsilonClosure(currentStates);

        for (char c : input) {
            unordered_set<int> nextStates;
            for (int state : currentStates) {
                if (transitions[state].find(c) != transitions[state].end()) {
                    nextStates.insert(transitions[state][c].begin(), transitions[state][c].end());
                }
            }
            currentStates = nextStates;
            applyEpsilonClosure(currentStates);
        }

        bool accepted = false;
        for (int state : currentStates) {
            if (finalStates.count(state)) {
                accepted = true;
                break;
            }
        }

        cout << "Cuvantul \"" << input << "\" " << (accepted ? "este acceptat" : "nu este acceptat") << endl;
    }

private:
    void applyEpsilonClosure(unordered_set<int>& states) {
        unordered_set<int> closure = states;
        vector<int> stack(states.begin(), states.end());

        while (!stack.empty()) {
            int state = stack.back();
            stack.pop_back();

            if (transitions[state].find('?') != transitions[state].end()) {
                for (int next : transitions[state]['?']) {
                    if (!closure.count(next)) {
                        closure.insert(next);
                        stack.push_back(next);
                    }
                }
            }
        }
        states = closure;
    }
};

int main() {
    NFA automaton;
    vector<string> testWords = { "a", "ba", "bb", "baa", "baba", "ab", "bbba" };

    cout << "Testare NFA-?:" << endl;
    for (const string& word : testWords) {
        automaton.simulate(word);
    }

    return 0;
} */


// Exercitiul 4

// Functie pt a genera cuvinte din expresia regulata (aproximare)
void generateWords(set<string> &words, string current, int maxLength, bool firstPart) {
    if (current.length() > maxLength) return;
    if (!current.empty()) words.insert(current);

    if (firstPart) {
        // Generare prima parte a expresiei
        generateWords(words, current + "1", maxLength, firstPart);
        generateWords(words, current + "00", maxLength, firstPart);
    } else {
        // Generare partea repetitiva
        generateWords(words, current + "0", maxLength, firstPart);
        generateWords(words, current + "10", maxLength, firstPart);
    }
}

int main() {
    set<string> leftExpr, rightExpr;
    int maxLength = 6;

    // Generare cuvinte pt ambele expresii
    generateWords(leftExpr, "", maxLength, true);
    generateWords(leftExpr, "1", maxLength, false);
    generateWords(rightExpr, "0", maxLength, false);
    generateWords(rightExpr, "1", maxLength, false);

    // Compara limbajele generate
    if (leftExpr == rightExpr) {
        cout << "Expresiile sunt echivalente!" << endl;
    } else {
        cout << "Expresiile NU sunt echivalente!" << endl;
    }

    return 0;
}

