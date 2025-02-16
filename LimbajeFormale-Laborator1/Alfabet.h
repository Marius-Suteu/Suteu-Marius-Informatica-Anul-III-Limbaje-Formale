#include <iostream>
#include <string>

class StringManipulator {
public:
    
    static std::string concatenate(const std::string& s1, const std::string& s2) {
        return s1 + s2;
    }

    static std::string invers(const std::string& s) {
        return std::string(s.rbegin(), s.rend());
    }

    static std::string substituie(std::string s, char a, char b) {
        for (char& c : s) {
            if (c == a) {
                c = b;
            }
        }
        return s;
    }

    static size_t lungime(const std::string& s) {
        return s.length();
    }
};

int main() {
    std::string s1 = "abc";
    std::string s2 = "xyz";
    std::string s3 = "123";

    std::cout << "Concatenare: " << StringManipulator::concatenate(s1, s2) << std::endl;

    std::cout << "Inversare: " << StringManipulator::invers(s1) << std::endl;

    std::cout << "Substituire: " << StringManipulator::substituie(s1, 'a', 'x') << std::endl;

    std::cout << "Lungime: " << StringManipulator::lungime(s3) << std::endl;

    return 0;
}
