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
    ParkingLot(int id = 0, int spaces = 0) : lotID(id), availableSpaces(spaces) {
        totalParkingLots++;
    }

    ~ParkingLot() {
        totalParkingLots--;
    }

    int getLotID() const { return lotID; }
    int getAvailableSpaces() const override { return availableSpaces; }

    void setLotID(int id) { lotID = id; }
    void setAvailableSpaces(int spaces) {
        availableSpaces = spaces;
    }

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
    VIPParkingLot(int id, int spaces, string services)
        : ParkingLot(id, spaces), vipServices(services) {}

    void display() const override {
        ParkingLot::display();
        cout << "VIP Services: " << vipServices << "\n";
    }
};

class ParkingManager {
public:
    static bool parkCar(ParkingLot& lot) {
        if (lot.getAvailableSpaces() > 0) {
            int spaces = lot.getAvailableSpaces() - 1;
            lot.setAvailableSpaces(spaces);
            return true;
        }
        return false;
    }
};

class Car {
private:
    int carID;
    string licensePlate;
    static int totalCars;

public:
    Car(int id, string plate) : carID(id), licensePlate(plate) {
        totalCars++;
    }

    Car(int id) : carID(id), licensePlate("Unknown") {
        totalCars++;
    }

    Car() : carID(0), licensePlate("Unknown") {
        totalCars++;
    }

    ~Car() {
        totalCars--;
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

class LuxuryCar : public Car {
private:
    string luxuryFeatures;

public:
    LuxuryCar(int id, string plate, string features)
        : Car(id, plate), luxuryFeatures(features) {}

    void display() const {
        Car::display();
        cout << "Luxury Features: " << luxuryFeatures << "\n";
    }
};

class ElectricLuxuryCar : public LuxuryCar {
private:
    int batteryCapacity;

public:
    ElectricLuxuryCar(int id, string plate, string features, int capacity)
        : LuxuryCar(id, plate, features), batteryCapacity(capacity) {}

    void display() const {
        LuxuryCar::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh\n";
    }
};

int main() {
    VIPParkingLot vipLot1(101, 50, "Valet, Car Wash");
    VIPParkingLot vipLot2(102, 30, "Valet, EV Charging");

    Car car1(1, "ABC-123");
    Car car2(2);
    Car car3;

    ElectricLuxuryCar electricCar1(3, "LMN-456", "Heated Seats", 85);

    cout << "VIP Parking Lot Details:\n";
    vipLot1.display();
    vipLot2.display();

    cout << "\nCar Details:\n";
    car1.display();
    car2.display();
    car3.display();

    cout << "\nElectric Luxury Car Details:\n";
    electricCar1.display();

    ParkingLot::displayTotalParkingInfo();
    Car::displayTotalCars();

    return 0;
}
