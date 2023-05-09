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
        void readDyspetchersFromFile(const string& filename) {
            ifstream file(filename);
            if (!file) {
                cout << "Unable to open file";
            }

            int id_dyspetcher;
            string first_name;
            string last_name;

            while (file >> id_dyspetcher >> first_name >> last_name) {
                dyspetchers.emplace_back(id_dyspetcher, first_name, last_name);
            }
        }

        void addDyspetcher(const Dyspetcher& dysp) { dyspetchers.push_back(dysp); }

        void showDyspetchers() const {
            for (const auto& dysp : dyspetchers) {
                cout << "Dyspetcher ID: " << dysp.getId() << endl;
                cout << "First Name: " << dysp.Worker::get_first_name() << endl;
                cout << "Last Name: " << dysp.Worker::get_last_name() << endl;
                cout << endl;
            }
        }

        /*
        Drivers
        */
        void readDriversFromFile(const string& filename) {
            ifstream file(filename);
            if (!file) {
                cout << "Unable to open file";
            }
            
            int id_driver;
            string first_name;
            string last_name;

            while (file >> id_driver >> first_name >> last_name) {
                drivers.emplace_back(id_driver, first_name, last_name);
            }
        }

        void addDriver(const Driver& driver) { drivers.push_back(driver); }

        void showDrivers() const {
            for (const auto& driver : drivers) {
                cout << "Driver ID: " << driver.getId() << endl;
                cout << "First Name: " << driver.Worker::get_first_name() << endl;
                cout << "Last Name: " << driver.Worker::get_last_name() << endl;
                cout << endl;
            }
        }

        /*
        Cars
       */
        void readCarsFromFile(const string& filename) {
            ifstream file(filename);
            if (!file) {
                cout << "Unable to open file";
            }

            int id_car;
            string brand;
            string model;
            int year;
            string license_plate;
            int number_of_passengers;
            double car_mileage;
            string car_status;

            while (file >> id_car >> brand >> model >> year >> license_plate >> number_of_passengers >> car_mileage >> car_status) {
                cars.emplace_back(id_car, brand, model, year, license_plate, number_of_passengers, car_mileage, car_status);
            }
        }

        void addCars(const Car& car) { cars.push_back(car); }

        void showCars() const {
            for (const auto& car : cars) {
                cout << "Car ID: " << car.getId() << endl;
                cout << "Brand: " << car.getBrand() << endl;
                cout << "Model: " << car.getModel() << endl;
                cout << "Year: " << car.getYear() << endl;
                cout << "License plates: " << car.getLicensePlates() << endl;
                cout << "Number of passengers: " << car.getNumberOfPassengers() << endl;
                cout << "Car milege: " << car.getCarMileage() << endl;
                cout << "Car status: " << car.getCarStatus() << endl;
                cout << endl;
            }
        }

        /*
        Trips
        */     
        void readTripFromFile(const string& filename) {
            ifstream file(filename);
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
                cout << "Trip ID: " << trip.getId() << endl;
                cout << "Departure point: " << trip.getDeparturePoint() << endl;
                cout << "Arrival point: " <<trip.getArrivalPoint() << endl;
                cout << "Departure time: " << trip.getDepartureTime() << endl;
                cout << "Arrival time: " << trip.getArrivalTime() << endl;
                cout << "Length of trip: " << trip.getLengthOfTrip() << endl;
                cout << "Cost of trip: " << trip.getCostOfTrip() << endl;
                cout << endl;
            }
        }
    };



int main()
{
    int  INDENT;
    cout << "Select your indentity: " << endl;
    cout << "1. Dispather\n" << "2. Driver" << endl;
    cin >> INDENT;

    switch (INDENT) {
    case 1: 
        string login_disp = "dispatcher1";
        string password_disp = "password1";

        string login = "";
        string password = "";
        
        while (login_disp != login && password_disp != password)
        {
            cout << "\nDispatcher login: " << endl;
            cout << "Enter your name: ";
            cin >> login;
            cout << "Enter your password: ";
            cin >> password;
        }

        cout << "\nYou are dispatcher" << endl;
        cout << login << " " << password << endl;

    }


/*
read
show
information from files
*/


        /*Autobaza autobaza;
        string dyspethcers_file = "..\\OOPLab7T\\Database\\dyspetchers.txt";
        string drivers_file = "..\\OOPLab7T\\Database\\drivers.txt";
        string cars_file = "..\\OOPLab7T\\Database\\cars.txt";
        string trips_file = "..\\OOPLab7T\\Database\\trips.txt";
        try {
            autobaza.readDyspetchersFromFile(dyspethcers_file);
            autobaza.readDriversFromFile(drivers_file);
            autobaza.readCarsFromFile(cars_file);
            autobaza.readTripFromFile(trips_file);
        }
        catch (runtime_error& e) {
            cout << e.what() << endl;
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
        autobaza.showTrips();*/

    return 0;
}