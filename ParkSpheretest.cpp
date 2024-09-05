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

    // Accessor
    int getLotID() const {
        return lotID;
    }

    // Mutator
    void setLotID(int id) {
        lotID = id;
    }

    // Accessor
    int getAvailableSpaces() const {
        return availableSpaces;
    }

    // Mutator 
    void setAvailableSpaces(int spaces) {
        totalSpacesAvailable -= availableSpaces;
        availableSpaces = spaces;
        totalSpacesAvailable += availableSpaces; 
    }

    void addSpaces(int spaces) {
        availableSpaces += spaces;
        totalSpacesAvailable += spaces;
    }

    bool parkCar() {
        if (availableSpaces > 0) {
            availableSpaces--;
            totalSpacesAvailable--;
            return true;
        } else {
            return false;
        }
    }

    void display() const {
        cout << "Parking Lot ID: " << lotID << "\n"
             << "Available Spaces: " << availableSpaces << "\n";
    }

    static void displayTotalParkingInfo() {
        cout << "Total Parking Lots: " << totalParkingLots << "\n"
             << "Total Available Spaces: " << totalSpacesAvailable << "\n";
    }

    // Static accessor 
    static int getTotalParkingLots() {
        return totalParkingLots;
    }
};

int ParkingLot::totalParkingLots = 0;
int ParkingLot::totalSpacesAvailable = 0;

class Car {
private:
    int carID;
    string licensePlate;
    static int totalCars;

public:
    Car(int id = 0, string plate = "") : carID(id), licensePlate(plate) {
        totalCars++;
    }

    ~Car() {
        totalCars--;
    }

    // Accessor
    int getCarID() const {
        return carID;
    }

    // Mutator
    void setCarID(int id) {
        carID = id;
    }

    // Accessor
    string getLicensePlate() const {
        return licensePlate;
    }

    // Mutator
    void setLicensePlate(const string &plate) {
        licensePlate = plate;
    }

    void display() const {
        cout << "Car ID: " << carID << "\n"
             << "License Plate: " << licensePlate << "\n";
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
        lots[i].setLotID(lotID);
        lots[i].setAvailableSpaces(initialSpaces);
    }

    cin >> numCars;
    Car* cars = new Car[numCars];

    for (int i = 0; i < numCars; ++i) {
        int carID;
        string licensePlate;
        cin >> carID;
        cin.ignore(5);
        getline(cin, licensePlate);
        cars[i].setCarID(carID);
        cars[i].setLicensePlate(licensePlate);
    }

    for (int i = 0; i < numLots; ++i) {
        cout << "Parking Lot " << (i + 1) << " details:\n";
        lots[i].display();
    }

    for (int i = 0; i < numCars; ++i) {
        cout << "Car " << (i + 1) << " details:\n";
        cars[i].display();
    }

    ParkingLot::displayTotalParkingInfo();
    Car::displayTotalCars();

    cout << "The total number of parking lots is: " << ParkingLot::getTotalParkingLots() << endl;

    delete[] lots;
    delete[] cars;

    return 0;
}
