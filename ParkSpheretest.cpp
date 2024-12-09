#include <iostream>
#include <string>
#include <memory>
using namespace std;

// Abstract Base Class for Parking Lot
class ParkingLot {
protected:
    int lotID;
    int availableSpaces;

public:
    ParkingLot(int id = 0, int spaces = 0) : lotID(id), availableSpaces(spaces) {}

    virtual void display() const = 0;

    virtual double calculateFee(double hours) const {
        return hours * 5.0; 
    }

    virtual ~ParkingLot() = default;
};

// Derived Class for VIP Parking Lot
class VIPParkingLot : public ParkingLot {
private:
    string vipServices;

public:
    VIPParkingLot(int id, int spaces, string services)
        : ParkingLot(id, spaces), vipServices(services) {}

    void display() const override {
        cout << "Parking Lot ID: " << lotID << "\n"
             << "Available Spaces: " << availableSpaces << "\n"
             << "VIP Services: " << vipServices << "\n";
    }

    double calculateFee(double hours) const override {
        return hours * 10.0; 
    }
};

// Derived Class for Regular Parking Lot
class RegularParkingLot : public ParkingLot {
public:
    RegularParkingLot(int id, int spaces) : ParkingLot(id, spaces) {}

    void display() const override {
        cout << "Parking Lot ID: " << lotID << "\n"
             << "Available Spaces: " << availableSpaces << "\n";
    }
};

// Derived Class for Electric Vehicle (EV) Parking Lot
class EVParkingLot : public ParkingLot {
private:
    double chargingRate;

public:
    EVParkingLot(int id, int spaces, double rate)
        : ParkingLot(id, spaces), chargingRate(rate) {}

    void display() const override {
        cout << "Parking Lot ID: " << lotID << "\n"
             << "Available Spaces: " << availableSpaces << "\n"
             << "Charging Rate: $" << chargingRate << " per hour\n";
    }

    double calculateFee(double hours) const override {
        return hours * chargingRate; 
    }
};

int main() {
    unique_ptr<ParkingLot> vipLot = make_unique<VIPParkingLot>(101, 20, "Valet, Car Wash");
    unique_ptr<ParkingLot> regularLot = make_unique<RegularParkingLot>(102, 50);
    unique_ptr<ParkingLot> evLot = make_unique<EVParkingLot>(103, 10, 7.5);

    cout << "VIP Parking Lot Details:\n";
    vipLot->display();
    cout << "Parking Fee for 3 hours: $" << vipLot->calculateFee(3) << "\n\n";

    cout << "Regular Parking Lot Details:\n";
    regularLot->display();
    cout << "Parking Fee for 3 hours: $" << regularLot->calculateFee(3) << "\n\n";

    cout << "EV Parking Lot Details:\n";
    evLot->display();
    cout << "Parking Fee for 3 hours: $" << evLot->calculateFee(3) << "\n";

    return 0;
}
