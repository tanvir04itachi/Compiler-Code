#include <iostream>
using namespace std;

int main5() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    double sum = 0;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    double avg = sum / n;
    cout << "Average value = " << avg << endl;

    return 0;
}

