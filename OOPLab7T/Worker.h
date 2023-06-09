#include <iostream>
#include <clocale>
#include <string>
#include <vector>

using namespace std;

class Worker {
protected:
    string first_name;
    string last_name;

public:

    string get_first_name() const { return first_name; }

    void set_first_name(const string& new_first_name) {
        first_name = new_first_name;
    }

    string get_last_name() const { return last_name; }

    void set_last_name(const string& new_last_name) {
        last_name = new_last_name;
    }

    Worker(string first_n, string last_n) :
    first_name(first_n), last_name(last_n) {}
};

class Dyspetcher : public Worker {
private:
    int id_dyspetcher;

public:
    Dyspetcher(int id_dyspetcher, string first_name, string last_name) 
        : id_dyspetcher(id_dyspetcher), Worker(first_name, last_name) {}

    void showDyspether() {
        cout << id_dyspetcher << " " << first_name << " " << last_name;
    }
    int getId() const { return id_dyspetcher; }
};

class Driver : public Worker {
private:
    int id_driver;
    string password;

public:
    Driver(int id_driver, string first_name, string last_name, string password)
        : id_driver(id_driver), Worker(first_name, last_name), password(password) {}

    void showDriver() {
        cout << id_driver << " " << first_name << " " << last_name;
    }
    int getId() const { return id_driver; }
    string get_password() const { return password; }
};
