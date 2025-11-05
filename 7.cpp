#include <iostream>
using namespace std;

int main7() {
    string firstName, lastName;
    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;

    string fullName = firstName + " " + lastName;
    cout << "Full name = " << fullName << endl;

    return 0;
}

