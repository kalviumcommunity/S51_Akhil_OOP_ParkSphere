#include <iostream>
#include <string>
#include <memory>
using namespace std;

class ParkingLot {
protected:
    int lotID;
    int availableSpaces;

public:
    ParkingLot(int id = 0, int spaces = 0) : lotID(id), availableSpaces(spaces) {}

    virtual void display() const = 0;

    virtual double calculateFee(double hours) const = 0;

    virtual ~ParkingLot() {}
};

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

class RegularParkingLot : public ParkingLot {
public:
    RegularParkingLot(int id, int spaces) : ParkingLot(id, spaces) {}

    void display() const override {
        cout << "Parking Lot ID: " << lotID << "\n"
             << "Available Spaces: " << availableSpaces << "\n";
    }

    double calculateFee(double hours) const override {
        return hours * 5.0; 
    }
};

// New class added for Electric Vehicle Parking Lot
class EVParkingLot : public ParkingLot {
private:
    double chargingRate;

public:
    EVParkingLot(int id, int spaces, double rate)
        : ParkingLot(id, spaces), chargingRate(rate) {}

    void display() const override {
        cout << "Parking Lot ID: " << lotID << "\n"
             << "Available Spaces: " << availableSpaces << "\n"
             << "Charging Rate: $" << chargingRate << " per kWh\n";
    }

    double calculateFee(double hours) const override {
        return hours * 8.0 + chargingRate; 
    }
};

int main() {
    unique_ptr<ParkingLot> vipLot = make_unique<VIPParkingLot>(101, 20, "Valet, Car Wash");
    unique_ptr<ParkingLot> regularLot = make_unique<RegularParkingLot>(102, 50);
    unique_ptr<ParkingLot> evLot = make_unique<EVParkingLot>(103, 10, 2.5);

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
