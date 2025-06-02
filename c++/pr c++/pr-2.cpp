#include <iostream>
using namespace std;

int trainNumbers[100];
char trainNames[100];        // One character only!
char sources[100];
char destinations[100];
char times[100];
int totalTrains = 0;

void addTrain() {
    cout << "Train No: "; cin >> trainNumbers[totalTrains];
    cout << "Name : "; cin >> trainNames[totalTrains];
    cout << "Source : "; cin >> sources[totalTrains];
    cout << "Dest : "; cin >> destinations[totalTrains];
    cout << "Time : "; cin >> times[totalTrains];
    totalTrains++;
}

void showTrains() {
    for (int i = 0; i < totalTrains; i++) {
        cout << "\nNo: " << trainNumbers[i]
             << ", Name: " << trainNames[i]
             << ", From: " << sources[i]
             << ", To: " << destinations[i]
             << ", Time: " << times[i] << endl;
    }
}

void searchTrain() {
    int num;
    cout << "Enter Train No: "; cin >> num;
    for (int i = 0; i < totalTrains; i++) {
        if (trainNumbers[i] == num) {
            cout << "Found: " << trainNames[i]
                 << ", From: " << sources[i]
                 << ", To: " << destinations[i]
                 << ", Time: " << times[i] << endl;
            return;
        }
    }
    cout << "Train not found!\n";
}

int main() {
    int ch;
    do {
        cout << "\n1.Add 2.Show 3.Search 4.Exit\nChoice: ";
        cin >> ch;
        switch (ch) {
            case 1: addTrain(); break;
            case 2: showTrains(); break;
            case 3: searchTrain(); break;
            case 4: cout << "Goodbye!\n"; break;
            default: cout << "Invalid\n";
        }
    } while (ch != 4);
    return 0;
}
