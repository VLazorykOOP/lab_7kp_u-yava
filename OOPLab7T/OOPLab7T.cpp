#include <iostream>
#include <fstream>
#include <clocale>
#include <string>
#include <vector>
#include "Worker.h"
#include "Car.h"
#include "Trip.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

class Race {
private:
    int id_race;
    int id_trip;
    int id_driver;
    int id_car;
    string race_status;
public:
    Race(int id, int trip_id, int driver_id, int car_id, string status)
        : id_race(id), id_trip(trip_id), id_driver(driver_id),
        id_car(car_id), race_status(status) {}
    int getId() const { return id_race; }
    int getTripId() const { return id_trip; }
    int getDriverId() const { return id_driver; }
    int getCarId() const { return id_car; }
    string getRaceStatus() const { return race_status; }
    void writeToFile() {
        ofstream outputFile("C:\\oop\\lab_7kp_u-yava.git\\OOPLab7T\\Database\\races.txt", std::ios::app);
        if (!outputFile) {
            throw runtime_error("Error opening output file.");
        }     
        outputFile << id_race << " " << id_trip << " " << id_driver << " " << id_car << " " << race_status << endl;
        outputFile.close();
    }
    std::string toString() const {
        // Convert the race information to a string representation
        std::string raceString = "Race ID: " + std::to_string(id_race) + ", Driver ID: " + std::to_string(id_driver) + ", Status: " + race_status;
        return raceString;
    }

 
};

class Autobaza {
private:
    vector<Dyspetcher> dyspetchers;
    vector<Trip> trips;
    vector<Driver> drivers;
    vector<Car> cars;
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
            string password;

            while (file >> id_driver >> first_name >> last_name >> password) {
                drivers.emplace_back(id_driver, first_name, last_name, password);
            }
        }

        void addDriver(const Driver& driver) { drivers.push_back(driver); }

        void showDrivers() const {
            for (const auto& driver : drivers) {
                cout << "Driver ID: " << driver.getId() << endl;
                cout << "First Name: " << driver.Worker::get_first_name() << endl;
                cout << "Last Name: " << driver.Worker::get_last_name() << endl;
                cout << "Password: " << driver.get_password() << endl;
                cout << endl;
            }
        }

        const vector<Driver>& get_drivers() const {
            return drivers;
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

        /*
        getters
        */

        int getTripsSize() {
            return trips.size();
        }

        int getDriversSize() {
            return drivers.size();
        }

        int getCarsSize() {
            return cars.size();
        }

        void showRace(const std::string& race) {
            std::istringstream iss(race);
            std::string column;
            bool firstColumn = true;

            while (iss >> column) {
                std::cout << column;

                // Add additional whitespaces after each column except the last one
                if (iss.peek() != EOF) {
                    std::cout << "      | ";  // Adjust the number of tabs as needed
                }

                firstColumn = false;
            }

            std::cout << std::endl;
        }

        void filterRacesByDriverID(const std::vector<std::string>& races, int driverId) {
            for (const auto& race : races) {
                std::istringstream iss(race);
                std::string column;
                bool hasDriverID = false;

                for (int i = 0; i < 3; ++i) {
                    if (iss >> column) {
                        if (i == 2) {
                            // Check if the third column is equal to the target driver ID
                            if (!column.empty() && std::stoi(column) == driverId) {
                                hasDriverID = true;
                                break;
                            }
                        }
                    }
                    else {
                        // Handle error or invalid format
                        std::cout << "Error reading columns." << std::endl;
                        break;
                    }
                }

                if (hasDriverID) {
                    showRace(race);
                }
            }
        }

       

};


std::vector<std::string> readFileData(const std::string& filename) {
    std::vector<std::string> data;
    std::ifstream inputFile(filename);

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            data.push_back(line);
        }

        inputFile.close();
    }
    else {
        std::cout << "Failed to open the file." << std::endl;
    }

    return data;
}


void deleteRaceFromFile(const std::string& filename, int raceId) {
    std::ifstream inputFile(filename);
    std::vector<std::string> racesFromFile;

    if (inputFile.is_open()) {
        std::string race;
        while (std::getline(inputFile, race)) {
            racesFromFile.push_back(race);
        }
        inputFile.close();
    }
    else {
        std::cout << "Failed to open the file." << std::endl;
        return;
    }

    std::ofstream outputFile(filename, std::ios::out);
    if (outputFile.is_open()) {
        for (const auto& race : racesFromFile) {
            std::istringstream iss(race);
            std::string column;
            int currentRaceId = 0;
            if (iss >> column) {
                currentRaceId = std::stoi(column);
            }
            if (currentRaceId != raceId) {
                outputFile << race << std::endl;
            }
        }
        outputFile.close();
    }
    else {
        std::cout << "Failed to open the file for writing." << std::endl;
    }
}






int main()
{
    Autobaza autobaza;
    vector<Race> races;
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
    /*  cout << "\nDYSPETCHERS:" << endl;
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

    int  INDENT;
    cout << "Select your indentity: " << endl;
    cout << "1. Dispather\n" << "2. Driver" << endl;
    cin >> INDENT;

    switch (INDENT) {
        case 1: {
         string login_disp = "d1";
         string password_disp = "p1";
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
         cout << "\n Hello dispatcher" << endl;
         int count_of_trips = 0;
         int count_of_drivers = 0;
         int count_of_cars = 0;
         int id_race = 0;
         string status = "Active";
         while (count_of_cars < autobaza.getCarsSize() && count_of_drivers < autobaza.getDriversSize() && count_of_cars < autobaza.getCarsSize()) {
             cout << "Create trip:\n";
             int trip_id_driver = 0;
             int trip_id_car = 0;
             int trip_id_trip = 0;
             cout << "------------------------------\n";
             cout << "\nDRIVERS:" << endl;
             autobaza.showDrivers();
             cout << "Select id driver:";
             cin >> trip_id_driver;

             cout << "------------------------------\n";
             cout << "\nCARS:" << endl;
             autobaza.showCars();
             cout << "Select id car:";
             cin >> trip_id_car;

             cout << "------------------------------\n";
             cout << "\nTrips:" << endl;
             cout << "Select id trip:";
             autobaza.showTrips();
             cin >> trip_id_trip;
             id_race ++;
             count_of_trips ++;
             count_of_drivers ++;
             count_of_cars ++;
             races.push_back(Race(id_race, trip_id_trip, trip_id_driver, trip_id_car, status));
             races.back().writeToFile();

         }
         break;
        }

        case 2: {
         string login_driver = "Mykola";
         string password_driver = "pass2";
         bool login_successful = false;
         int driverId = 0;
         while (!login_successful)
         {
            cout << "\nDriver login: " << endl;
            //cout << "Enter your name: ";
            //cin >> login_driver;
            //cout << "Enter your password: ";
            //cin >> password_driver;

            for (const auto& driver : autobaza.get_drivers()) {
                if (driver.get_first_name() == login_driver && driver.get_password() == password_driver) {
                    login_successful = true;
                    driverId = driver.getId();
                    cout << "\nYou are "<<driverId <<" driver" << endl;
                    break;
                }
            }
            if (!login_successful) {
                cout << "\nInvalid login or password. Please try again.\n";
            }
         }
         std::string filename = "C:\\oop\\lab_7kp_u-yava.git\\OOPLab7T\\Database\\races.txt";
         std::vector<std::string> racesFromFile = readFileData(filename);
         std::cout << "Your races:\n";
         std::cout << "\nraceID  tripID   driverID  carID    raceStatus\n";
         autobaza.filterRacesByDriverID(racesFromFile, driverId);
         int raceIdDelete = 0;

         /*
         delete race
         */
         char done;
         while (true) {
             std::cout << "Have you done the race? (Y/N): ";
             cin >> done;
             if (done == 'Y' || done == 'y') {
                 int raceIdDelete;
                 cout << "Enter the race ID you want to delete: ";
                 cin >> raceIdDelete;
                 deleteRaceFromFile(filename, raceIdDelete);

                 racesFromFile = readFileData(filename);
                 autobaza.filterRacesByDriverID(racesFromFile, driverId);
             }
             else if (done == 'N' || done == 'n') {
                 break;
             }
             else {
                 cout << "Invalid input. Please enter Y or N." << endl;
             }
         }
         /*
         repair bus request
         */
         cout<<"What bus to repair?"
         int busIdRepair;
         cin >> busIdRepair;

         //треба знайти у фалі cars.txt рядок з busIdRepair у першій колонці і змінити OK у останній колонці на Repair
         break;
        }
    }
    return 0;
}