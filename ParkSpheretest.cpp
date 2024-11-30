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
};

class ParkingManager {
protected:
    string managerName;

public:
    ParkingManager(string name) : managerName(name) {}

    void displayManager() const {
        cout << "Manager Name: " << managerName << "\n";
    }
};

class ManagedVIPParkingLot : public VIPParkingLot, public ParkingManager {
public:
    ManagedVIPParkingLot(int id, int spaces, string services, string manager)
        : VIPParkingLot(id, spaces, services), ParkingManager(manager) {}

    void display() const {
        VIPParkingLot::display();
        displayManager();
    }
};

int main() {
    ParkingLot lot1(101, 50);
    VIPParkingLot vipLot1(201, 20, "Valet, EV Charging");
    ManagedVIPParkingLot managedLot1(301, 10, "Private Lounge", "John Doe");

    cout << "Parking Lot Details:\n";
    lot1.display();
    cout << "\nVIP Parking Lot Details:\n";
    vipLot1.display();
    cout << "\nManaged VIP Parking Lot Details:\n";
    managedLot1.display();

    return 0;
}
