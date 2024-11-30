#include <iostream>
#include <string>
using namespace std;

class BaseParkingLot {
public:
    virtual void display() const = 0;
    virtual int getAvailableSpaces() const = 0;
    virtual ~BaseParkingLot() = default;
};

class ParkingLot : public BaseParkingLot {
private:
    int lotID;
    int availableSpaces;
    static int totalParkingLots;

public:
    ParkingLot() : lotID(0), availableSpaces(0) {
        totalParkingLots++;
        cout << "Default Constructor called for ParkingLot\n";
    }

    ParkingLot(int id, int spaces) : lotID(id), availableSpaces(spaces) {
        totalParkingLots++;
        cout << "Parameterized Constructor called for ParkingLot\n";
    }

    ~ParkingLot() {
        totalParkingLots--;
        cout << "Destructor called for ParkingLot ID: " << lotID << "\n";
    }

    int getLotID() const { return lotID; }
    int getAvailableSpaces() const override { return availableSpaces; }
    void setLotID(int id) { lotID = id; }
    void setAvailableSpaces(int spaces) { availableSpaces = spaces; }
    void display() const override {
        cout << "Parking Lot ID: " << lotID << "\n"
             << "Available Spaces: " << availableSpaces << "\n";
    }
    static void displayTotalParkingInfo() {
        cout << "Total Parking Lots: " << totalParkingLots << "\n";
    }
};

int ParkingLot::totalParkingLots = 0;

class VIPParkingLot : public ParkingLot {
private:
    string vipServices;

public:
    VIPParkingLot() : ParkingLot(), vipServices("None") {
        cout << "Default Constructor called for VIPParkingLot\n";
    }

    VIPParkingLot(int id, int spaces, string services)
        : ParkingLot(id, spaces), vipServices(services) {
        cout << "Parameterized Constructor called for VIPParkingLot\n";
    }

    ~VIPParkingLot() {
        cout << "Destructor called for VIPParkingLot\n";
    }

    void display() const override {
        ParkingLot::display();
        cout << "VIP Services: " << vipServices << "\n";
    }
};

class Car {
private:
    int carID;
    string licensePlate;
    static int totalCars;

public:
    Car() : carID(0), licensePlate("Unknown") {
        totalCars++;
        cout << "Default Constructor called for Car\n";
    }

    Car(int id, string plate) : carID(id), licensePlate(plate) {
        totalCars++;
        cout << "Parameterized Constructor called for Car\n";
    }

    ~Car() {
        totalCars--;
        cout << "Destructor called for Car ID: " << carID << "\n";
    }

    int getCarID() const { return carID; }
    string getLicensePlate() const { return licensePlate; }
    void setCarID(int id) { carID = id; }
    void setLicensePlate(const string& plate) { licensePlate = plate; }
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
    ParkingLot lot1;
    ParkingLot lot2(102, 30);

    VIPParkingLot vipLot1;
    VIPParkingLot vipLot2(201, 20, "Valet Service");

    Car car1;
    Car car2(1, "XYZ-123");

    lot1.display();
    lot2.display();
    vipLot1.display();
    vipLot2.display();
    car1.display();
    car2.display();

    ParkingLot::displayTotalParkingInfo();
    Car::displayTotalCars();

    lot1.~ParkingLot();
    vipLot1.~VIPParkingLot();
    car1.~Car();

    return 0;
}
