#include <iostream>
#include <string>
using namespace std;

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
};

int main() {
    VIPParkingLot vipLot(101, 20, "Valet, Car Wash");
    RegularParkingLot regularLot(102, 50);

    cout << "VIP Parking Lot Details:\n";
    vipLot.display();
    cout << "Parking Fee for 3 hours: " << vipLot.calculateFee(3) << "\n";

    cout << "\nRegular Parking Lot Details:\n";
    regularLot.display();
    cout << "Parking Fee for 3 hours: " << regularLot.calculateFee(3) << "\n";

    return 0;
}
