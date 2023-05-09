#include <iostream>
#include <clocale>
#include <string>
#include <vector>


class Car {
private:
    int id_car;
    string brand;
    string model;
    int year;
    string license_plates;
    int number_of_passengers;
    double car_mileage;
    string car_status;

public:
    Car(int id, string b, string mdl, int yr, string lcs, int pass, double mileage, string status)
        : id_car(id), brand(b), model(mdl), year(yr), license_plates(lcs), number_of_passengers(pass),car_mileage(mileage), car_status(status) {}

    int getId() const { return id_car; }
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    string getLicensePlates() const { return license_plates; }
    int getNumberOfPassengers() const { return number_of_passengers; }
    double getCarMileage() const { return car_mileage; }
    string getCarStatus() const { return car_status; }
    void showCar() {
        cout << id_car << " " << brand << " " << model << " " << license_plates << " " << number_of_passengers << " " << car_status;
    }
};
