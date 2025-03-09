#include <iostream>
#include <string>
#include <set>
#include <map>
#include <vector>

using namespace std;

//  Exercitiul 1

/*class NFA {
private:
    set<string> states;
    set<string> final_states;
    map<pair<string, char>, set<string>> transitions;
    set<string> current_states;

public:
    NFA() {
        states = { "q0", "q1", "q2", "q3", "q4" };
        final_states = { "q4" };

        transitions[{"q0", 'a'}] = { "q1", "q3" };
        transitions[{"q1", 'a'}] = { "q1", "q3", "q4" };
        transitions[{"q1", 'b'}] = { "q2", "q3", "q4" };
        transitions[{"q2", 'b'}] = { "q3", "q4" };
        transitions[{"q3", 'a'}] = { "q3", "q4" };
        transitions[{"q3", 'b'}] = { "q3", "q4" };

        current_states = { "q0" };
    }

    void transition(char input) {
        set<string> new_states;
        for (const string& state : current_states) {
            if (transitions.count({ state, input })) {
                new_states.insert(transitions[{state, input}].begin(), transitions[{state, input}].end());
            }
        }
        current_states = new_states;
    }

    bool is_accepting() {
        for (const string& state : current_states) {
            if (final_states.count(state)) {
                return true;
            }
        }
        return false;
    }

    void process_string(const string& input_string) {
        current_states = { "q0" };
        for (char c : input_string) {
            transition(c);
        }
        if (is_accepting()) {
            cout << "Cuvant acceptat!" << endl;
        }
        else {
            cout << "Cuvant respins!" << endl;
        }
    }
};

int main() {
    NFA automaton;
    string input_string;
    cout << "Introduceti un sir de intrare: ";
    cin >> input_string;
    automaton.process_string(input_string);
    return 0;
} */

//  Exercitiul 2

/* class MooreMachine {
private:
    string state;
public:
    MooreMachine() { state = "S1"; }

    string transition(char input_symbol) {
        if (state == "S1") {
            if (input_symbol == 'A') {
                state = "S1";
            }
            else if (input_symbol == 'B') {
                state = "S2";
            }
        }
        else if (state == "S2") {
            if (input_symbol == 'A') {
                state = "S1";
            }
            else if (input_symbol == 'B') {
                state = "S2";
            }
        }
        return (state == "S1") ? "O1" : "O2";
    }

    void process(const string& input_string) {
        string output_sequence = "";
        for (char symbol : input_string) {
            output_sequence += transition(symbol);
        }
        cout << "Intrare:  " << input_string << endl;
        cout << "Iesire:  " << output_sequence << endl;
    }
};

int main() {
    MooreMachine moore;
    string input_sequence = "ABABBA";
    moore.process(input_sequence);
    return 0;
} */

// Exerctiul 3

class MealyMachine {
private:
    string state;

public:
    MealyMachine() { state = "Q1"; }

    void transition(char input) {
        if (state == "Q1" && input == 'X') {
            state = "Q2";
            cout << "O1 ";
        }
        else if (state == "Q1" && input == 'Y') {
            state = "Q1";
            cout << "O1 ";
        }
        else if (state == "Q2" && input == 'X') {
            state = "Q1";
            cout << "O2 ";
        }
        else if (state == "Q2" && input == 'Y') {
            state = "Q2";
            cout << "O2 ";
        }
        else {
            cout << "Invalid input ";
        }
    }

    void processString(const string& input_string) {
        for (char c : input_string) {
            transition(c);
        }
        cout << endl;
    }
};

int main() {
    MealyMachine machine;
    string input_string;
    cout << "Introduceti un sir de intrare (X/Y): ";
    cin >> input_string;
    machine.processString(input_string);
    return 0;
}

