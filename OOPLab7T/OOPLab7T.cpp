#include <iostream>
#include <clocale>
#include <string>
#include <vector>
#include "Pracivnyk.h"
#include "Car.h"
#include "Trip.h"




using namespace std;


class Race {
private:
    int id_race;
    int id_trip;
    int id_dyspetcher;
    int id_driver;
    int id_car;
    string race_status;
public:
    Race(int id, int trip_id, int dyspatcher_id, int driver_id, int car_id, string status)
        : id_race(id), id_trip(trip_id), id_dyspetcher(dyspatcher_id), id_driver(driver_id),
        id_car(car_id), race_status(status) {}

    int getId() const { return id_race; }
    int getTripId() const { return id_trip; }
    int getDyspetcherId() const { return id_dyspetcher; }
    int getDriverId() const { return id_driver; }
    int getCarId() const { return id_car; }
    string getRaceStatus() const { return race_status; }
};
/*
class Autobaza {
private:
    vector<Dyspetcher> dyspetchers;
    vector<Trip> trips;
    vector<Driver> drivers;
    vector<Car> cars;
    vector<Race> races;
public:
    // methods to add objects to the vectors
    void addDyspetcher(const Dyspetcher& d) { dyspetchers.push_back(d); }
    void addTrip(const Trip& t) { trips.push_back(t); }
    void addDriver(const Driver& d) { drivers.push_back(d); }
    void addCar(const Car& c) { cars.push_back(c); }
    void addRace(const Race& r) { races.push_back(r); }

    // method to get a driver by id
    Driver getDriverById(int id) const {
        for (const Driver& d : drivers) {
            if (d.getId() == id) {
                return d;
            }
        }
        throw runtime_error("Driver not found");
    }

    // method to get a car by id
    Car getCarById(int id) const {
        for (const Car& c : cars) {
            if (c.getId() == id) {
                return c;
            }
        }
        throw runtime_error("Car not found");
    }

    // method to find available cars
    vector<Car> getAvailableCars() const {
        vector<Car> available_cars;
        for (const Car& c : cars) {
            if (c.getCarStatus() == "Available") {
                available_cars.push_back(c);
            }
        }
        return available_cars;
    }

    // method to assign a driver and car to a race
    void assignDriverAndCarToRace(int race_id, int driver_id, int car_id) {
        for (Race& r : races) {
            if (r.getId() == race_id) {
                r = Race(r.getId(), r.getTripId(), r.getDyspetcherId(), driver_id, car_id, "Assigned");
                break;
            }
        }
    }

    // method for a driver to request a repair
    void requestRepair(int driver_id) {
        for (Driver& d : drivers) {
            if (d.getId() == driver_id) {
                d = Driver(d.getId(), d.getFirstName(), d.getLastName(), d.getSex(), d.getExperience(), "Repair Requested");
                break;
            }
        }
    }

    // method for a dispatcher to suspend a driver
    void suspendDriver(int driver_id) {
        for (Driver& d : drivers) {
            if (d.getId() == driver_id) {
                d = Driver(d.getId(), d.getFirstName(), d.getLastName(), d.getSex(), d.getExperience(), "Suspended");
                break;
            }
        }
    }

    // method for a driver to update the race status and car mileage
    void updateRaceStatusAndCarMileage(int driver_id, int race_id, string race_status, int car_mileage) {
        for (Race& r : races) {
            if (r.getId() == race_id && r.getDriverId() == driver_id) {
                // update race status
                r = Race(r.getId(), r.getTripId(), r.getDyspetcherId(), driver_id, r.getCarId(), race_status);
                // update car mileage
                for (Car& c : cars) {
                    if (c.getId() == r.getCarId()) {
                        c = Car(c.getId(), c.getMake(), c.getModel(), c.getYear(), c.getColor(),
                            c.getNumberOfPassangers(), car_mileage, c.getCarStatus());
                        break;
                    }
                }
                break;
            }
        }
    }
};
*/

int main()
{
    int  INDENT;
    cout << " Who are you ? : (Dispetch 1 / Driver 2)" << endl;
    cin >> INDENT;
    if (INDENT==1) {
        cout << "You are dispatch" << endl;
        Dyspetcher 
        
    }
    else if (INDENT==2) {
        cout << "You are driver" << endl;

    }


    return 0;
}