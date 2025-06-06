#include <iostream>
#include <string.h>
using namespace std;

class Aircraft 
{
public:
    int flightrange;
    Aircraft() 
    {
        
    }
};

class Vehicle 
{
public:
    char vehicleID[50];
    char manufacturer[50];
    int model;
    int year;

    Vehicle() 
    {
        
    }

    void vehicledetails() 
    {
        cout << "Enter Vehicle ID: ";
        cin >> vehicleID;
        cout << "Enter Manufacturer: ";
        cin >> manufacturer;
        cout << "Enter Model: ";
        cin >> model;
        cout << "Enter Year: ";
        cin >> year;
    }

    void display() 
    {
        cout << "Vehicle ID: " << vehicleID;
        cout << "\nManufacturer: " << manufacturer;
        cout << "\nModel: " << model;
        cout << "\nYear: " << year;
    }
};

class Car : public Vehicle 
{
public:
    void display() 
    {
        cout << "\nCar Details:\n";
        Vehicle::display();
        cout << endl;
    }
};

class ev : public Car 
{
public:
    int batterycapacity;

    ev() 
    {
        
    }

    void vehicledetails() 
    {
        Vehicle::vehicledetails();
        cout << "Enter Battery Capacity (kWh): ";
        cin >> batterycapacity;
    }

    void display() 
    {
        cout << "\n ev Details:\n";
        Vehicle::display();
        cout << "\nBattery Capacity: " << batterycapacity << " kWh" << endl;
    }
};

class Flyingcar : public Car, public Aircraft 
{
public:
    void vehicledetails() 
    {
        Vehicle::vehicledetails();
        cout << "Enter Flight Range (km): ";
        cin >> flightrange;
    }

    void display() 
    {
        cout << "\nFlyingcar Details:\n";
        Vehicle::display();
        cout << "\nFlight Range: " << flightrange << " km" << endl;
    }
};

class Sportscar : public Car 
{
public:
    int topspeed;
    Sportscar() 
    {
        
    }

    void vehicledetails() 
    {
        Vehicle::vehicledetails();
        cout << "Enter Top Speed (km/h): ";
        cin >> topspeed;
    }

    void display() 
    {
        cout << "\nSportscar Details:\n";
        Vehicle::display();
        cout << "\nTop Speed: " << topspeed << " km/h" << endl;
    }
};

class Sedan : public Car 
{
public:
    void display() 
    {
        cout << "\nSedan Details:\n";
        Vehicle::display();
        cout << endl;
    }
};

class SUV : public Car 
{
public:
    void display() 
    {
        cout << "\nSUV Details:\n";
        Vehicle::display();
        cout << endl;
    }
};

class Vehiclesystem 
{
public:
    Car cars[100];
    ev evs[100];
    Flyingcar flyingCars[100];
    Sportscar sportsCars[100];
    Sedan sedans[100];
    SUV suvs[100];
    int totalcars;
    int totalev;
    int totalflyingcars;
    int totalsportscars;
    int totalsedans;
    int totalsuvs;

    Vehiclesystem() 
    {
        totalcars = 0;
        totalev = 0;
        totalflyingcars = 0;
        totalsportscars = 0;
        totalsedans = 0;
        totalsuvs = 0;
    }

    void add() 
    {
        int type;
        cout << "Vehicle Type (1-Car, 2-Electric Car, 3-Flying Car, 4-Sports Car, 5-Sedan, 6-SUV): ";
        cin >> type;

        if (type == 1 && totalcars < 100) 
        {
            cars[totalcars].vehicledetails();
            totalcars++;
        } 
        else if (type == 2 && totalev < 100) 
        {
            evs[totalev].vehicledetails();
            totalev++;
        } 
        else if (type == 3 && totalflyingcars < 100) 
        {
            flyingCars[totalflyingcars].vehicledetails();
            totalflyingcars++;
        } 
        else if (type == 4 && totalsportscars < 100) 
        {
            sportsCars[totalsportscars].vehicledetails();
            totalsportscars++;
        } 
        else if (type == 5 && totalsedans < 100) 
        {
            sedans[totalsedans].vehicledetails();
            totalsedans++;
        } 
        else if (type == 6 && totalsuvs < 100)
        {
            suvs[totalsuvs].vehicledetails();
            totalsuvs++;
        } 
        else 
        {
            cout << "Vehicle limit reached or invalid type.\n";
        }
    }

    void displayallvehicles() 
    {
        if (totalcars == 0 && totalev == 0 && totalflyingcars == 0 && totalsportscars == 0 && totalsedans == 0 && totalsuvs == 0) 
        {
            cout << "No vehicles available.\n";
        } 
        else 
        {
            for (int i = 0; i < totalcars; i++) 
            {
                cout << "\nVehicle " << (i + 1) << ":";
                cars[i].display();
            }
            for (int i = 0; i < totalev; i++) 
            {
                cout << "\nVehicle " << (i + 1 + totalcars) << ":";
                evs[i].display();
            }
            for (int i = 0; i < totalflyingcars; i++) 
            {
                cout << "\nVehicle " << (i + 1 + totalcars + totalev) << ":";
                flyingCars[i].display();
            }
            for (int i = 0; i < totalsportscars; i++) 
            {
                cout << "\nVehicle " << (i + 1 + totalcars + totalev + totalflyingcars) << ":";
                sportsCars[i].display();
            }
            for (int i = 0; i < totalsedans; i++) 
            {
                cout << "\nVehicle " << (i + 1 + totalcars + totalev + totalflyingcars + totalsportscars) << ":";
                sedans[i].display();
            }
            for (int i = 0; i < totalsuvs; i++)
            {
                cout << "\nVehicle " << (i + 1 + totalcars + totalev + totalflyingcars + totalsportscars + totalsedans) << ":";
                suvs[i].display();
            }
        }
    }

    void search(char id[50]) 
    {
        for (int i = 0; i < totalcars; i++) 
        {
            if (strcmp(cars[i].vehicleID, id) == 0) 
            {
                cout << "\nVehicle found:\n";
                cars[i].display();
            }
        }
        for (int i = 0; i < totalev; i++) 
        {
            if (strcmp(evs[i].vehicleID, id) == 0) 
            {
                cout << "\nVehicle found:\n";
                evs[i].display();
            }
        }
        for (int i = 0; i < totalflyingcars; i++) 
        {
            if (strcmp(flyingCars[i].vehicleID, id) == 0) 
            {
                cout << "\nVehicle found:\n";
                flyingCars[i].display();
            }
        }
        for (int i = 0; i < totalsportscars; i++) 
        {
            if (strcmp(sportsCars[i].vehicleID, id) == 0) 
            {
                cout << "\nVehicle found:\n";
                sportsCars[i].display();
            }
        }
        for (int i = 0; i < totalsedans; i++) 
        {
            if (strcmp(sedans[i].vehicleID, id) == 0) 
            {
                cout << "\nVehicle found:\n";
                sedans[i].display();
            }
        }
        for (int i = 0; i < totalsuvs; i++)
        {
            if (strcmp(suvs[i].vehicleID, id) == 0) 
            {
                cout << "\nVehicle found:\n";
                suvs[i].display();
            }
        }
			cout << "Vehicle with ID " << id << " not found.\n";
    }
};

int main() 
{
    Vehiclesystem v1;
    int ch;
    char id[50];

    while (ch != 4) 
    {
        cout << "\n--- Vehicle System Menu ---";
        cout << "\n1. Add New Vehicle Record";
        cout << "\n2. Display All Vehicles Records";
        cout << "\n3. Search Vehicle by ID";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) 
        {
            case 1:
                v1.add();
                break;
            case 2:
                v1.displayallvehicles();
                break;
            case 3:
                cout << "Enter Vehicle ID to Search: ";
                cin >> id;
                v1.search(id);
                break;
            case 4:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }
    }
}


/*

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 1
Vehicle Type (1-Car, 2-Electric Car, 3-Flying Car, 4-Sports Car, 5-Sedan, 6-SUV): 1
Enter Vehicle ID: 12
Enter Manufacturer: ford
Enter Model: 12
Enter Year: 2002

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 1
Vehicle Type (1-Car, 2-Electric Car, 3-Flying Car, 4-Sports Car, 5-Sedan, 6-SUV): 2
Enter Vehicle ID: 13
Enter Manufacturer: ford
Enter Model: 1213
Enter Year: 2004
Enter Battery Capacity (kWh): 123

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 1
Vehicle Type (1-Car, 2-Electric Car, 3-Flying Car, 4-Sports Car, 5-Sedan, 6-SUV): 3
Enter Vehicle ID: 14
Enter Manufacturer: ford
Enter Model: 1234
Enter Year: 2004
Enter Flight Range (km): 123

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 1
Vehicle Type (1-Car, 2-Electric Car, 3-Flying Car, 4-Sports Car, 5-Sedan, 6-SUV): 4
Enter Vehicle ID: 15
Enter Manufacturer: ford
Enter Model: 67
Enter Year: 2007
Enter Top Speed (km/h): 300

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 1
Vehicle Type (1-Car, 2-Electric Car, 3-Flying Car, 4-Sports Car, 5-Sedan, 6-SUV): 5
Enter Vehicle ID: 16
Enter Manufacturer: ford
Enter Model: 234
Enter Year: 2018

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 1
Vehicle Type (1-Car, 2-Electric Car, 3-Flying Car, 4-Sports Car, 5-Sedan, 6-SUV): 6
Enter Vehicle ID: 17
Enter Manufacturer: ford
Enter Model: 678
Enter Year: 2017

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 2

Vehicle 1:
Car Details:
Vehicle ID: 12
Manufacturer: ford
Model: 123
Year: 2002

Vehicle 2:
Electric car Details:
Vehicle ID: 13
Manufacturer: ford
Model: 123
Year: 2004
Battery Capacity: 123 kWh

Vehicle 3:
Flyingcar Details:
Vehicle ID: 14
Manufacturer: ford
Model: 123
Year: 2004
Flight Range: 123 km

Vehicle 4:
Sportscar Details:
Vehicle ID: 15
Manufacturer: ford
Model: 67
Year: 2007
Top Speed: 300 km/h

Vehicle 5:
Sedan Details:
Vehicle ID: 16
Manufacturer: ford
Model: 23
Year: 2018

Vehicle 6:
SUV Details:
Vehicle ID: 17
Manufacturer: ford
Model: 678
Year: 2017

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 3
Enter Vehicle ID to Search: 17

Vehicle found:

SUV Details:
Vehicle ID: 17
Manufacturer: ford
Model: 678
Year: 2017

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 3
Enter Vehicle ID to Search: 18
Vehicle with ID 18 not found.

--- Vehicle System Menu ---
1. Add New Vehicle Record
2. Display All Vehicles Records
3. Search Vehicle by ID
4. Exit
Enter your choice: 4
Goodbye!
*/