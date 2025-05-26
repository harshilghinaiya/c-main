#include <iostream>
using namespace std;

int main() {
    int s, e;

    cout << "Enter the first number: ";
    cin >> s;

    cout << "Enter the second number: ";
    cin >> e;

    cout << "The array is: "<<endl;

    for (int year = s; year <= e; year++) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            cout << year << endl;
        }
    }

}

