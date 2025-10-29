#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    cout << "Enter an expression: ";
    getline(cin, line);
    if (line.size() == 0) getline(cin, line); // handle leftover newline

    bool found = false;
    for (int i = 0; i < (int)line.size(); i++) {
        char c = line[i];
        if (c=='+' || c=='-' || c=='*' || c=='/' || c=='%' || c=='=') {
            found = true;
            cout << c << "\n";
        }
    }
    if (!found) cout << "No arithmetic operators found\n";
    return 0;
}

