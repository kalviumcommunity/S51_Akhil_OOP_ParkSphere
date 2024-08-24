#include <iostream>
#include <string>

using namespace std;

class ParkingLot {
private:
    int lotID;
    int availableSpaces;
    static int totalParkingLots;    
    static int totalSpacesAvailable;   

public:
    ParkingLot(int id = 0, int spaces = 0) : lotID(id), availableSpaces(spaces) {
        totalParkingLots++;
        totalSpacesAvailable += spaces;
    }

    ~ParkingLot() {
        totalParkingLots--;
        totalSpacesAvailable -= availableSpaces;
    }

    void addSpaces(int spaces) {
        this->availableSpaces += spaces;
        totalSpacesAvailable += spaces;
    }

    bool parkCar() {
        if (this->availableSpaces > 0) {
            this->availableSpaces--;
            totalSpacesAvailable--;
            return true;
        } else {
            return false;
        }
    }

    void display() const {
        cout << "Parking Lot ID: " << this->lotID << "\n"
             << "Available Spaces: " << this->availableSpaces << "\n";
    }

    static void displayTotalParkingInfo() {
        cout << "Total Parking Lots: " << totalParkingLots << "\n"
             << "Total Available Spaces: " << totalSpacesAvailable << "\n";
    }
};

int ParkingLot::totalParkingLots = 0;   
int ParkingLot::totalSpacesAvailable = 0; 

class Car {
private:
    int carID;
    string licensePlate;
    static int totalCars;  // Static variable to track total number of Car objects

public:
    Car(int id = 0, string plate = "") : carID(id), licensePlate(plate) {
        totalCars++;
    }

    ~Car() {
        totalCars--;
    }

    void display() const {
        cout << "Car ID: " << this->carID << "\n"
             << "License Plate: " << this->licensePlate << "\n";
    }

    static void displayTotalCars() {
        cout << "Total Cars: " << totalCars << "\n";
    }
};

int Car::totalCars = 0; 

int main() {
    int numLots, numCars;
    cin >> numLots;

    ParkingLot* lots = new ParkingLot[numLots];

    for (int i = 0; i < numLots; ++i) {
        int lotID, initialSpaces;
        cin >> lotID >> initialSpaces;
        lots[i] = ParkingLot(lotID, initialSpaces);
    }

    cin >> numCars;

    Car* cars = new Car[numCars];

    for (int i = 0; i < numCars; ++i) {
        int carID;
        string licensePlate;
        cin >> carID;
        cin.ignore();
        getline(cin, licensePlate);
        cars[i] = Car(carID, licensePlate);
    }

    for (int i = 0; i < numLots; ++i) {
        cout << "Parking Lot " << (i + 1) << " details:\n";
        lots[i].display();
    }

    for (int i = 0; i < numCars; ++i) {
        cout << "Car " << (i + 1) << " details:\n";
        cars[i].display();
    }

    // Display static information
    ParkingLot::displayTotalParkingInfo();
    Car::displayTotalCars();

    delete[] lots;
    delete[] cars;

    return 0;
}
