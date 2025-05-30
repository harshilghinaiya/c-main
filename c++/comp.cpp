#include <iostream>
using namespace std;

class DiamondCompany {
    int id, staff, import_raw, export_ready;
    float revenue;
    string name, ceo;

public:
    DiamondCompany(int i, string n, int s, float r, int ir, int er, string c) {
        id = i; name = n; staff = s;
        revenue = r; import_raw = ir;
        export_ready = er; ceo = c;
    }

    void display() {
        cout << "\nID: " << id
             << "\nName: " << name
             << "\nStaff: " << staff
             << "\nRevenue: " << revenue
             << "\nImport: " << import_raw
             << "\nExport: " << export_ready
             << "\nCEO: " << ceo << endl;
    }
};

int main() {
    int n;
    cout << "Enter number of companies: ";
    cin >> n;

    DiamondCompany* arr[n];

    for (int i = 0; i < n; i++) {
        int id, staff, imp, exp;
        float rev;
        string name, ceo;

        cout << "\nEnter ID, Name, Staff, Revenue, Import, Export, CEO (all single-word):\n";
        cin >> id >> name >> staff >> rev >> imp >> exp >> ceo;

        arr[i] = new DiamondCompany(id, name, staff, rev, imp, exp, ceo);
    }

    cout << "\n--- Company Details ---";
    for (int i = 0; i < n; i++) arr[i]->display();

    return 0;
}
