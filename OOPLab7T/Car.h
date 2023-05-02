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
    string color;
    int number_of_passengers;
    double car_mileage;
    string car_status;
public:
    Car(int id, string b, string mdl, int yr, string clr, int pass, double mileage, string status)
        : id_car(id), brand(b), model(mdl), year(yr), color(clr), number_of_passengers(pass),
        car_mileage(mileage), car_status(status) {}

    int getId() const { return id_car; }
    string getBrand() const { return brand; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    string getColor() const { return color; }
    int getNumberOfPassengers() const { return number_of_passengers; }
    double getCarMileage() const { return car_mileage; }
    string getCarStatus() const { return car_status; }
};
