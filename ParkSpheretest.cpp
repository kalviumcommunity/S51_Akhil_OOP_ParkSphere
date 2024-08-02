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
    Car(int id, string plate) : carID(id), licensePlate(plate) {}

    void display() const {
        cout << "Car ID: " << this->carID << "\n"
             << "License Plate: " << this->licensePlate << "\n";
    }

    void updateLicensePlate(const string& newPlate) {
        this->licensePlate = newPlate;
    }
};

int main() {
    int lotID, initialSpaces;
    int carID;
    string licensePlate;

    cin >> lotID >> initialSpaces;
    ParkingLot* lot1 = new ParkingLot(lotID, initialSpaces);

    cin >> carID;
    cin.ignore();
    getline(cin, licensePlate);
    Car* car1 = new Car(carID, licensePlate);

    bool parked = lot1->parkCar();

    lot1->display();
    car1->display();
    cout << "Remaining Spaces: " << lot1->getAvailableSpaces() << "\n";

    string newPlate;
    cout << "Enter new license plate: ";
    getline(cin, newPlate);
    car1->updateLicensePlate(newPlate);
    car1->display();

    delete lot1;
    delete car1;

    return 0;
}
