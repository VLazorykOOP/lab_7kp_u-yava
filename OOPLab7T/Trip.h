#include <iostream>
#include <clocale>
#include <string>
#include <vector>


class Trip {
private:
    int id_trip;
    string departure_point;
    string arrival_point;
    string departure_time;
    string arrival_time;
    double length_of_trip;
    double cost_of_trip;

public:
    Trip(int id, string dep, string arr, string dep_time, string arr_time, double length, double cost)
        : id_trip(id), departure_point(dep), arrival_point(arr), departure_time(dep_time),
        arrival_time(arr_time), length_of_trip(length), cost_of_trip(cost) {}

    int getId() const { return id_trip; }
    string getDeparturePoint() const { return departure_point; }
    string getArrivalPoint() const { return arrival_point; }
    string getDepartureTime() const { return departure_time; }
    string getArrivalTime() const { return arrival_time; }
    double getLengthOfTrip() const { return length_of_trip; }
    double getCostOfTrip() const { return cost_of_trip; }
};