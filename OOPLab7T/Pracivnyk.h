#include <iostream>
#include <clocale>
#include <string>
#include <vector>

using namespace std;

class Pracivnyk {
protected:
    string first_name;
    string last_name;
    string sex;
    int experience;

public:

    string get_first_name() const {
        return first_name;
    }


    void set_first_name(const string& new_first_name) {
        first_name = new_first_name;
    }


    string get_last_name() const {
        return last_name;
    }


    void set_last_name(const string& new_last_name) {
        last_name = new_last_name;
    }

    string get_sex() const {
        return sex;
    }

    void set_sex(const string& new_sex) {
        sex = new_sex;
    }

    int get_experience() const {
        return experience;
    }

    void set_experience(int new_experience) {
        experience = new_experience;
    }


};

class Dyspetcher : protected Pracivnyk {
private:
    int id_dyspetcher;

public:
    Dyspetcher(int id, string first, string last) : id_dyspetcher(id), first_name(first), last_name(last) {}

    int getId() const { return id_dyspetcher; }
  
};

class Driver : protected Pracivnyk {
private:
    int id_driver;

public:
    Driver(int id, string first, string last, string s, int exp)
        : id_driver(id), first_name(first), last_name(last), sex(s), experience(exp) {}

    int getId() const { return id_driver; }
  
};
