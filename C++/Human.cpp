/*
 * Description: This program defines a base class called Human with data members for name, citizen ID, weight, and height.
 *              It then creates a derived class Woman from the Human base class, adding a private data member for gender.
 *              The program demonstrates inheritance and encapsulation principles, showing how to access member variables
 *              and create objects of the derived class.
 */
#include <iostream>
#include <string>
using namespace std;

class Human {
public:
    string name;
    int citizenID;
    int weight;
    int height;

    Human(string n = "", int id = 0, int w = 0, int h = 0)
        : name(n), citizenID(id), weight(w), height(h) {}

    ~Human() {
        cout << "Destructor of Human called for " << name << endl;
    }
};

class Woman : public Human {
protected:
    string gender;
public:
    Woman(string n = "", int id = 0, int w = 0, int h = 0)
        : Human(n, id, w, h), gender("Female") {}

    string getGender() const {
        return gender;
    }

    ~Woman() {
        cout << "Destructor of Woman called for " << name << endl;
    }
};

int main() {
    Woman woman("Salma Rahmani", 10000001, 56, 162);
    cout << "Woman Information:" << endl;
    cout << "Name: " << woman.name << endl;
    cout << "Citizen ID: " << woman.citizenID << endl;
    cout << "Weight: " << woman.weight << " kg" << endl;
    cout << "Height: " << woman.height << " cm" << endl;
    cout << "Gender: " << woman.getGender() << endl;
    return 0;
}
