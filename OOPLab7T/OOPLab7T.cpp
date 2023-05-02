#include <iostream>
#include <fstream>
#include <clocale>
#include <string>
#include <vector>
#include "Worker.h"
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
        /*
        Dyspetchers
        */
        void readDyspetchersFromFile(const std::string& filename) {
            std::ifstream file(filename);
            if (!file) {
                cout << "Unable to open file";
            }

            int id_dyspetcher;
            std::string first_name;
            std::string last_name;

            while (file >> id_dyspetcher >> first_name >> last_name) {
                dyspetchers.emplace_back(id_dyspetcher, first_name, last_name);
            }
        }

        void addDyspetcher(const Dyspetcher& dysp) { dyspetchers.push_back(dysp); }

        void showDyspetchers() const {
            for (const auto& dysp : dyspetchers) {
                std::cout << "Dyspetcher ID: " << dysp.getId() << std::endl;
                std::cout << "First Name: " << dysp.Worker::get_first_name() << std::endl;
                std::cout << "Last Name: " << dysp.Worker::get_last_name() << std::endl;
                std::cout << endl;
            }
        }

        /*
        Drivers
        */
        void readDriversFromFile(const std::string& filename) {
            std::ifstream file(filename);
            if (!file) {
                cout << "Unable to open file";
            }
            
            int id_driver;
            std::string first_name;
            std::string last_name;

            while (file >> id_driver >> first_name >> last_name) {
                drivers.emplace_back(id_driver, first_name, last_name);
            }
        }

        void addDriver(const Driver& driver) { drivers.push_back(driver); }

        void showDrivers() const {
            for (const auto& driver : drivers) {
                std::cout << "Driver ID: " << driver.getId() << std::endl;
                std::cout << "First Name: " << driver.Worker::get_first_name() << std::endl;
                std::cout << "Last Name: " << driver.Worker::get_last_name() << std::endl;
                std::cout << endl;
            }
        }
        /*
        Cars
       */
        void readCarsFromFile(const std::string& filename) {
            std::ifstream file(filename);
            if (!file) {
                cout << "Unable to open file";
            }

            int id_car;
            std::string brand;
            std::string model;
            int year;
            std::string license_plate;
            int number_of_passengers;
            double car_mileage;
            std::string car_status;

            while (file >> id_car >> brand >> model >> year >> license_plate >> number_of_passengers >> car_mileage >> car_status) {
                cars.emplace_back(id_car, brand, model, year, license_plate, number_of_passengers, car_mileage, car_status);
            }
        }

        void addCars(const Car& car) { cars.push_back(car); }

        void showCars() const {
            for (const auto& car : cars) {
                std::cout << "Car ID: " << car.getId() << std::endl;
                std::cout << "Brand: " << car.getBrand() << std::endl;
                std::cout << "Model: " << car.getModel() << std::endl;
                std::cout << "Year: " << car.getYear() << std::endl;
                std::cout << "License plates: " << car.getLicensePlates() << std::endl;
                std::cout << "Number of passengers: " << car.getNumberOfPassengers() << std::endl;
                std::cout << "Car milege: " << car.getCarMileage() << std::endl;
                std::cout << "Car status: " << car.getCarStatus() << std::endl;
                std::cout << endl;
            }
        }
        /*
        Trips
        */     
        void readTripFromFile(const std::string& filename) {
            std::ifstream file(filename);
            if (!file) {
                cout << "Unable to open file";
            }

            int id_trip;
            string departure_point;
            string arrival_point;
            string departure_time;
            string arrival_time;
            double length_of_trip;
            double cost_of_trip;


            while (file >> id_trip >> departure_point >> arrival_point >> departure_time >> arrival_time >> length_of_trip >> cost_of_trip) {
                trips.emplace_back(id_trip, departure_point, arrival_point, departure_time, arrival_time, length_of_trip, cost_of_trip);
            }
        }

        void addTrip(const Trip& trip) { trips.push_back(trip); }

        void showTrips() const {
            for (const auto& trip : trips) {
                
              
                double length_of_trip;
                double cost_of_trip;
                std::cout << "Trip ID: " << trip.getId() << std::endl;
                std::cout << "Departure point: " << trip.getDeparturePoint() << std::endl;
                std::cout << "Arrival point: " <<trip.getArrivalPoint() << std::endl;
                std::cout << "Departure time: " << trip.getDepartureTime() << std::endl;
                std::cout << "Arrival time: " << trip.getArrivalTime() << std::endl;
                std::cout << "Length of trip: " << trip.getLengthOfTrip() << std::endl;
                std::cout << "Cost of trip: " << trip.getCostOfTrip() << std::endl;
                std::cout << endl;
            }
        }
    };



int main()
{
    //int  INDENT;
    //cout << " Who are you ? : (Dispetch 1 / Driver 2)" << endl;
    //cin >> INDENT;
    //if (INDENT==1) {
    //    cout << "You are dispatch" << endl;
    //    Dyspetcher 
    //    
    //}
    //else if (INDENT==2) {
    //    cout << "You are driver" << endl;

    //}

/*
read
show
information from files
*/
        Autobaza autobaza;
        std::string dyspethcers_file = "..\\OOPLab7T\\Database\\dyspetchers.txt";
        std::string drivers_file = "..\\OOPLab7T\\Database\\drivers.txt";
        std::string cars_file = "..\\OOPLab7T\\Database\\cars.txt";
        string trips_file = "..\\OOPLab7T\\Database\\trips.txt";
        try {
            autobaza.readDyspetchersFromFile(dyspethcers_file);
            autobaza.readDriversFromFile(drivers_file);
            autobaza.readCarsFromFile(cars_file);
            autobaza.readTripFromFile(trips_file);
        }
        catch (std::runtime_error& e) {
            std::cout << e.what() << std::endl;
        }
        cout << "\nDYSPETCHERS:" << endl;
        autobaza.showDyspetchers();
        cout << "------------------------------\n";
        cout << "\nDRIVER:" << endl;
        autobaza.showDrivers();
        cout << "------------------------------\n";
        cout << "\nCARS:" << endl;
        autobaza.showCars();
        cout << "------------------------------\n";
        cout << "\nTrips:" << endl;
        autobaza.showTrips();

    return 0;
}