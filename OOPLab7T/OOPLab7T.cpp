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

class Autobaza {
private:
    vector<Dyspetcher> dyspetchers;
    vector<Trip> trips;
    vector<Driver> drivers;
    vector<Car> cars;
    vector<Race> races;
public:
  
};


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