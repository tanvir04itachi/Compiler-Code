#include <iostream>
#include <cctype>
#include <string>
using namespace std;

bool isKeyword(const string& word) {
    string keywords[] = {"int", "float", "if", "else", "while"};
    int keywordCount = 5;

    for (int i = 0; i < keywordCount; i++) {
        if (word == keywords[i])
            return true;
    }
    return false;
}

bool isIdentifier(const string& s) {
    if (s.empty()) return false;

    if (!(isalpha(s[0]) || s[0] == '_'))
        return false;

    for (int i = 1; i < s.size(); i++) {
        if (!(isalnum(s[i]) || s[i] == '_'))
            return false;
    }

    if (isKeyword(s))
        return false;

    return true;
}

int main4() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    if (isIdentifier(input))
        cout << input << " is a VALID identifier." << endl;
    else
        cout << input << " is NOT a valid identifier." << endl;

    return 0;
}
