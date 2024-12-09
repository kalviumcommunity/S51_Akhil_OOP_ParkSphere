#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FeeCalculator {
public:
    virtual double calculateFee(double hours) const = 0;
};

class RegularFeeCalculator : public FeeCalculator {
public:
    double calculateFee(double hours) const override {
        return hours * 5.0;
    }
};

class VIPFeeCalculator : public FeeCalculator {
public:
    double calculateFee(double hours) const override {
        return hours * 10.0;
    }
};

class EVFeeCalculator : public FeeCalculator {
private:
    double chargingRate;
public:
    EVFeeCalculator(double rate) : chargingRate(rate) {}
    double calculateFee(double hours) const override {
        return (hours * 8.0) + chargingRate;
    }
};

class ParkingLot {
protected:
    int lotID;
    int availableSpaces;
    FeeCalculator* feeCalculator;

public:
    ParkingLot(int id, int spaces, FeeCalculator* calculator)
        : lotID(id), availableSpaces(spaces), feeCalculator(calculator) {}

    virtual void display() const = 0;

    double calculateFee(double hours) const {
        return feeCalculator->calculateFee(hours);
    }

    int getAvailableSpaces() const { return availableSpaces; }
    void updateSpaces(int spaces) { availableSpaces = spaces; }
};

class VIPParkingLot : public ParkingLot {
private:
    string vipServices;

public:
    VIPParkingLot(int id, int spaces, FeeCalculator* calculator, string services)
        : ParkingLot(id, spaces, calculator), vipServices(services) {}

    void display() const override {
        cout << "Parking Lot ID: " << lotID << "\n"
             << "Available Spaces: " << availableSpaces << "\n"
             << "VIP Services: " << vipServices << "\n";
    }
};

class RegularParkingLot : public ParkingLot {
public:
    RegularParkingLot(int id, int spaces, FeeCalculator* calculator)
        : ParkingLot(id, spaces, calculator) {}

    void display() const override {
        cout << "Parking Lot ID: " << lotID << "\n"
             << "Available Spaces: " << availableSpaces << "\n";
    }
};

class EVParkingLot : public ParkingLot {
public:
    EVParkingLot(int id, int spaces, FeeCalculator* calculator)
        : ParkingLot(id, spaces, calculator) {}

    void display() const override {
        cout << "Parking Lot ID: " << lotID << "\n"
             << "Available Spaces: " << availableSpaces << "\n";
    }
};

class ParkingLotManager {
private:
    vector<ParkingLot*> parkingLots;

public:
    void addParkingLot(ParkingLot* lot) {
        parkingLots.push_back(lot);
    }

    void displayAllLots() const {
        for (const auto& lot : parkingLots) {
            lot->display();
            cout << endl;
        }
    }
};

int main() {
    RegularFeeCalculator regularCalculator;
    VIPFeeCalculator vipCalculator;
    EVFeeCalculator evCalculator(2.0);

    VIPParkingLot vipLot(101, 20, &vipCalculator, "Valet, Car Wash");
    RegularParkingLot regularLot(102, 50, &regularCalculator);
    EVParkingLot evLot(103, 10, &evCalculator);

    ParkingLotManager manager;
    manager.addParkingLot(&vipLot);
    manager.addParkingLot(&regularLot);
    manager.addParkingLot(&evLot);

    cout << "Displaying All Parking Lots:\n";
    manager.displayAllLots();

    cout << "VIP Parking Fee for 3 hours: " << vipLot.calculateFee(3) << "\n";
    cout << "Regular Parking Fee for 3 hours: " << regularLot.calculateFee(3) << "\n";
    cout << "EV Parking Fee for 3 hours: " << evLot.calculateFee(3) << "\n";

    return 0;
}
