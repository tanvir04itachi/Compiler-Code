#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    cout << "Enter a single line: ";
    getline(cin, line);
    if (line.size() == 0) getline(cin, line);

    // remove leading spaces (simple)
    int p = 0;
    while (p < (int)line.size() && (line[p]==' ' || line[p]=='\t')) p++;
    string t = line.substr(p);

    if (t.size() >= 2 && t[0]=='/' && t[1]=='/') {
        cout << "single line comment\n";
    } else if (t.size() >= 2 && t[0]=='/' && t[1]=='*') {
        // check if same-line closing
        bool closed = false;
        for (int i = 2; i < (int)t.size()-1; i++) {
            if (t[i]=='*' && t[i+1]=='/') { closed = true; break; }
        }
        if (closed) cout << "multiple line comment (closed on same line)\n";
        else cout << "start of multiple line comment\n";
    } else {
        cout << "not a comment line\n";
    }
    return 0;
}

