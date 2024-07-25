#include <iostream>
#include <string>

using namespace std;

class ParkingLot {
private:
    int lotID;
    int availableSpaces;

public:
    ParkingLot(int id, int spaces) : lotID(id), availableSpaces(spaces) {}

    void addSpaces(int spaces) {
        availableSpaces += spaces;
    }

    bool parkCar() {
        if (availableSpaces > 0) {
            availableSpaces--;
            return true;
        } else {
            return false;
        }
    }

    void display() const {
        cout << "Parking Lot ID: " << lotID << "\n"
             << "Available Spaces: " << availableSpaces << "\n";
    }

    int getAvailableSpaces() const {
        return availableSpaces;
    }
};

class Car {
private:
    int carID;
    string licensePlate;

public:
    Car(int id, string plate) : carID(id), licensePlate(plate) {}

    void display() const {
        cout << "Car ID: " << carID << "\n"
             << "License Plate: " << licensePlate << "\n";
    }

    void updateLicensePlate(const string& newPlate) {
        licensePlate = newPlate;
    }
};

int main() {
    int lotID, initialSpaces;
    int carID;
    string licensePlate;

    cin >> lotID >> initialSpaces;  
    ParkingLot lot1(lotID, initialSpaces);

    cin >> carID;            
    cin.ignore();                
    getline(cin, licensePlate);     
    Car car1(carID, licensePlate);

    bool parked = lot1.parkCar();

    lot1.display();
    car1.display();
    cout << "Remaining Spaces: " << lot1.getAvailableSpaces() << "\n";

    return 0;
}
