#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*class StringManipulator {
public:

    static string concatenare(const string& s1, const string& s2) {
        return s1 + s2;
    }

    static string invers(const string& s) {
        return string(s.rbegin(), s.rend());
    }

    static string substitutie(string s, char a, char b) {
        for (char& c : s) {
            if (c == a) {
                c = b;
            }
        }
        return s;
    }

    static size_t lungime(const string& s) {
        return s.length();
    }
};

int main() {
    string s1 = "abc";
    string s2 = "xyz";
    string s3 = "123";

    cout << "Concatenare: " << StringManipulator::concatenare(s1, s2) << endl;
    cout << "Inversare: " << StringManipulator::invers(s1) << endl;
    cout << "Substituire: " << StringManipulator::substitutie(s1, 'a', 'x') << endl;
    cout << "Lungime: " << StringManipulator::lungime(s3) << endl;

    return 0;
}*/

// Exercitiul 2:

/*class StringManipulator {
public:
    
    static string concatenare(const string& s1, const string& s2) {
        return s1 + s2;
    }

    static string repetare(const string& s, int n) {
        string result;
        for (int i = 0; i < n; ++i) {
            result += s;
        }
        return result;
    }

    static string inversare(const string& s) {
        return string(s.rbegin(), s.rend());
    }

    static string extractie(const string& s, size_t i, size_t j) {
        if (i >= s.length() || j >= s.length() || i > j) 
            return "";
        return s.substr(i, j - i + 1);
    }

    static string inlocuire(string s, const string& sub, const string& new_sub) {
        size_t pos = s.find(sub);
        if (pos != string::npos) {
            s.replace(pos, sub.length(), new_sub);
        }
        return s;
    }
};

int main() {
   string word = "abc123";

    cout << "Concatenare: " << StringManipulator::concatenare(word, "xyz") << endl;
    cout << "Repetare: " << StringManipulator::repetare(word, 3) << endl;
    cout << "Inversare: " << StringManipulator::inversare(word) << endl;
    cout << "Extractie: " << StringManipulator::extractie(word, 1, 4) << endl;
    cout << "Inlocuire: " << StringManipulator::inlocuire(word, "abc", "xyz") << endl;

    return 0;
}*/

//Exercitiul 3:

/*class StringManipulator {
public:

    static string concatenate(const string& s1, const string& s2) {
        return s1 + s2;
    }

    static string repetare(const string& s, int n) {
        string result;
        for (int i = 0; i < n; ++i) {
            result += s;
        }
        return result;
    }

    static string inversare(const string& s) {
        return string(s.rbegin(), s.rend());
    }

    static string extract(const string& s, size_t i, size_t j) {
        if (i >= s.length() || j >= s.length() || i > j) return "";
        return s.substr(i, j - i + 1);
    }

    static string inlocuire(string s, const string& sub, const string& new_sub) {
        size_t pos = s.find(sub);
        if (pos != string::npos) {
            s.replace(pos, sub.length(), new_sub);
        }
        return s;
    }
};

void generatePalindrom(const string& alphabet, int length, string current) {
    if (current.size() == length) {
        if (current == StringManipulator::inversare(current)) {
            cout << current << endl;
        }
        return;
    }
    for (char c : alphabet) {
        generatePalindrom(alphabet, length, current + c);
    }
}

void displayPalindrom() {
    string alfabet = "012";
    for (int len = 1; len <= 5; ++len) {
        cout << "Palindroame de lungime " << len << ":" << endl;
        generatePalindrom(alfabet, len, "");
        cout << endl;
    }
}

int main() {
    displayPalindrom();
    return 0;
}*/

//Exercitiul 4:

class StringManipulator {
public:
    
    static string concatenare(const string& s1, const string& s2) {
        return s1 + s2;
    }

    static string repetare(const string& s, int n) {
        string result;
        for (int i = 0; i < n; ++i) {
            result += s;
        }
        return result;
    }

    static string inversare(const string& s) {
        return string(s.rbegin(), s.rend());
    }

    static string extractie(const string& s, size_t i, size_t j) {
        if (i >= s.length() || j >= s.length() || i > j) return "";
        return s.substr(i, j - i + 1);
    }

    static string inlocuire(string s, const string& sub, const string& new_sub) {
        size_t pos = s.find(sub);
        if (pos != string::npos) {
            s.replace(pos, sub.length(), new_sub);
        }
        return s;
    }
};

void generateLanguage(const string& prefix, int a_count, int b_count) {
    if (a_count == 0 && b_count == 0) {
        cout << prefix << endl;
        return;
    }
    if (a_count > 0) {
        generateLanguage(prefix + "a", a_count - 1, b_count);
    }
    if (b_count > 0) {
        generateLanguage(prefix + "b", a_count, b_count - 1);
    }
}

void displayGeneratedLanguage(int max_length) {
    cout << "Limbaj generat:" << endl;
    for (int len = 0; len <= max_length; ++len) {
        for (int a_count = 0; a_count <= len; ++a_count) {
            int b_count = len - a_count;
            generateLanguage("", a_count, b_count);
        }
    }
}

int main() {
    displayGeneratedLanguage(4);
    return 0;
}


