#include <iostream>
#include <string>
using namespace std;

class ParkingLot {
protected:
    int lotID;
    int availableSpaces;

public:
    ParkingLot(int id = 0, int spaces = 0) : lotID(id), availableSpaces(spaces) {}

    virtual void display() const {
        cout << "Parking Lot ID: " << lotID << "\n"
             << "Available Spaces: " << availableSpaces << "\n";
    }

    double calculateFee(double hours) const {
        return hours * 5.0; 
    }

    double calculateFee(double hours, double discount) const {
        double fee = hours * 5.0;
        return fee - (fee * discount); 
    }
};

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

    double calculateFee(double hours) const override {
        return hours * 10.0; 
    }
};

int main() {
    ParkingLot lot1(101, 50);
    VIPParkingLot vipLot1(201, 20, "Valet, EV Charging");

    cout << "Parking Lot Details:\n";
    lot1.display();
    cout << "Parking Fee for 3 hours: " << lot1.calculateFee(3) << "\n";
    cout << "Parking Fee for 3 hours with 10% discount: " << lot1.calculateFee(3, 0.1) << "\n";

    cout << "\nVIP Parking Lot Details:\n";
    vipLot1.display();
    cout << "VIP Parking Fee for 3 hours: " << vipLot1.calculateFee(3) << "\n";

    return 0;
}
