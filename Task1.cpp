#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;
    cout << "Enter input: ";
    cin >> s;

    if (s.size() == 0) { cout << "not numeric\n"; return 0; }

    int i = 0;
    if (s[0] == '+' || s[0] == '-') {
        if (s.size() == 1) { cout << "not numeric\n"; return 0; }
        i = 1;
    }

    bool ok = true;
    for (; i < (int)s.size(); i++) {
        if (!isdigit((unsigned char)s[i])) { ok = false; break; }
    }

    if (ok) cout << "numeric constant\n";
    else cout << "not numeric\n";
    return 0;
}
