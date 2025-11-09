#include <iostream>
#include <fstream>
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

bool isValid(const string& s) {
    if (s.empty()) return false;

    for (char ch : s) {
        if (!(isalpha(ch) || isdigit(ch) || ch == '_'))
            return false;
    }

    return true;
}

int main() {
    ifstream file("demo.txt");
    if (!file.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        if (isKeyword(line))
            cout << line << " is a KEYWORD" << endl;
        else if (isValid(line))
            cout << line << " is VALID" << endl;
        else
            cout << line << " is INVALID" << endl;
    }

    file.close();
    return 0;
}
