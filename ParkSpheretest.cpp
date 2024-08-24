#include <iostream>
#include <string>

using namespace std;

class ParkingLot {
private:
    int lotID;
    int availableSpaces;

public:
    ParkingLot(int id = 0, int spaces = 0) : lotID(id), availableSpaces(spaces) {}

    void addSpaces(int spaces) {
        this->availableSpaces += spaces;
    }

    bool parkCar() {
        if (this->availableSpaces > 0) {
            this->availableSpaces--;
            return true;
        } else {
            return false;
        }
    }

    void display() const {
        cout << "Parking Lot ID: " << this->lotID << "\n"
             << "Available Spaces: " << this->availableSpaces << "\n";
    }

    int getAvailableSpaces() const {
        return this->availableSpaces;
    }
};

class Car {
private:
    int carID;
    string licensePlate;

public:
    Car(int id = 0, string plate = "") : carID(id), licensePlate(plate) {}

    void display() const {
        cout << "Car ID: " << this->carID << "\n"
             << "License Plate: " << this->licensePlate << "\n";
    }

    void updateLicensePlate(const string& newPlate) {
        this->licensePlate = newPlate;
    }
};

int main() {
    int numLots, numCars;
    cin >> numLots;
    
    // Dynamic memory allocation for ParkingLot objects
    ParkingLot* lots = new ParkingLot[numLots];

    for (int i = 0; i < numLots; ++i) {
        int lotID, initialSpaces;
        cin >> lotID >> initialSpaces;
        lots[i] = ParkingLot(lotID, initialSpaces);
    }

    cin >> numCars;

    // Dynamic memory allocation for Car objects
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

    // Deleting dynamically allocated memory
    
    delete[] lots;
    delete[] cars;

    return 0;
}
