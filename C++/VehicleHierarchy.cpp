/*
    This program demonstrates inheritance and polymorphism by defining a base class Vehicle
    and two derived classes Car and Motorcycle. The Vehicle class contains data members for
    manufacturer and year, along with methods to set and get these attributes. The Car class,
    derived from Vehicle, adds an additional attribute for the number of doors and overrides
    the displayInfo method to include this information. The Motorcycle class, also derived
    from Vehicle, adds an attribute to indicate if it's a sports bike and overrides the
    displayInfo method accordingly. The main function creates objects of both derived classes
    and demonstrates polymorphic behavior by accessing them through pointers to the base class.
*/

#include<iostream>
#include<string>
using namespace std;

class Vehicle{
protected:
    string manufacturer;
    int year;
public:
    Vehicle(int y, const string &i) {
        year = y;
        manufacturer = i;
    }
    Vehicle() {}

    Vehicle(const Vehicle &obj) {
        this->manufacturer = obj.get_manufacturer();
        this->year = obj.get_year();
    }

    void operator=(const Vehicle &obj) {
        this->manufacturer = obj.get_manufacturer();
        this->year = obj.get_year();
    }

    virtual void displayInfo() {
        cout<<"Manufacturer -> "<<manufacturer<<" and year -> "<<year<<endl;
    }

    ~Vehicle() {
        year = -1;
        manufacturer.clear();
    }

    void set_year(int y) {
        year = y;
    }

    void set_manufacturer(const string &n) {
        manufacturer = n;
    }

    int get_year() const {
        return year;
    }

    const string get_manufacturer() const {
        return manufacturer;
    }
};

class Car : public Vehicle {
private:
    int numDoors;
public:
    Car() {}

    Car(int y, int d , const string &a) : Vehicle(y , a) {
        numDoors = d;
    }

    Car(const Car& obj) {
        this->set_year(obj.get_year());
        this->set_manufacturer(obj.get_manufacturer());
        this->numDoors = obj.get_numDoors();
    }

    void operator=(const Car &obj) {
        this->set_year(obj.get_year());
        this->set_manufacturer(obj.get_manufacturer());
        this->numDoors = obj.get_numDoors();
    }

    int get_numDoors() const {
        return numDoors;
    }

    void set_numDoors(int a) {
        numDoors = a;
    }

    void displayInfo() {
        Vehicle::displayInfo();
        cout<<"Number of doors -> "<<numDoors<<endl;
    }

    ~Car() {
        numDoors = -1;
    }
};

class Motorcycle : public Vehicle {
private:
    bool isSports;
public:
    Motorcycle() {}

    Motorcycle(bool i , int y , const string &k) : Vehicle(y,k) {
        isSports = i;
    }

    Motorcycle(const Motorcycle &obj) {
        this->set_year(obj.get_year());
        this->set_manufacturer(obj.get_manufacturer());
        isSports = obj.get_isit();
    }

    void operator=(const Motorcycle &obj) {
        this->set_year(obj.get_year());
        this->set_manufacturer(obj.get_manufacturer());
        isSports = obj.get_isit();
    }

    bool get_isit() const {
        return isSports;
    }

    void set_isit(bool a) {
        isSports = a;
    }

    void displayInfo() {
        Vehicle::displayInfo();
        cout<<"Sporstcar -> "<<isSports<<endl;
    }

    ~Motorcycle() {
        isSports = false;
    }

};  

int main() {
    Car car1(4,4,"Mercedes");
    Motorcycle motor(true,98,"Kawazaki");
    Vehicle *first = &car1;
    Vehicle *second = &motor;
    first->displayInfo();
    second->displayInfo();
    return 0;
}
