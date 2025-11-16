#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
using namespace std;

bool isKeyword(const string& word) {
    string keywords[] = {"int", "float", "if", "else", "while", "for", "return", "char", "double", "void" , "main"};
    int keywordCount = sizeof(keywords) / sizeof(keywords[0]);

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

    for (char ch : s) {
        if (!(isalnum(ch) || ch == '_'))
            return false;
    }

    return true;
}
bool isPunctuationChar(char ch) {
    string punct = ";,.(){}[]+-*/=%<>!";
    return punct.find(ch) != string::npos;
}
void tokenizeLine(const string& line, int ln) {
    cout << "Line " << ln << ": " << line << "\n";

    int i = 0, n = line.size();

    while (i < n) {

        if (isspace((unsigned char)line[i])) {
            i++;
            continue;
        }

        if (isalpha(line[i]) || line[i] == '_') {
            string token;
            while (i < n && (isalnum(line[i]) || line[i] == '_')) {
                token += line[i];
                i++;
            }

            if (isKeyword(token))
                cout << "  -> " << token << " is  KEYWORD\n";
            else
                cout << "  -> " << token << " is  IDENTIFIER\n";
        }

        else if (isPunctuationChar(line[i])) {
            cout << "  -> " << line[i] << " is  PUNCTUATION\n";
            i++;
        }
        else {

            cout << "  -> " << line[i] << " is  UNKNOWN\n";
            i++;
        }
    }
    cout << "\n";
}

int main() {
    ifstream file("demo.txt");
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    int ln = 1;
    while (getline(file, line)) {
        tokenizeLine(line, ln++);
    }

    file.close();
    return 0;
}
