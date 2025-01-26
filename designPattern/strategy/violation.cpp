#include <iostream>
#include <string>
using namespace std;

// Base Vehicle Class
class Vehicle
{
protected:
    string type;

public:
    Vehicle(const string &t) : type(t) {}
    virtual void drive()
    { // Hardcoded behavior in derived classes
        cout << "Unknown driving behavior!" << endl;
    }
    virtual ~Vehicle() = default;
};

// Car Class
class Car : public Vehicle
{
public:
    Car() : Vehicle("Car") {}

    void drive() override
    {
        cout << "Driving on roads." << endl;
    }
};

// Boat Class
class Boat : public Vehicle
{
public:
    Boat() : Vehicle("Boat") {}

    void drive() override
    {
        cout << "Driving on water." << endl;
    }
};

// Plane Class
class Plane : public Vehicle
{
public:
    Plane() : Vehicle("Plane") {}

    void drive() override
    {
        cout << "Flying in the air." << endl;
    }
};

// Main Function
int main()
{
    Vehicle *car = new Car();
    car->drive();

    Vehicle *boat = new Boat();
    boat->drive();

    Vehicle *plane = new Plane();
    plane->drive();

    delete car;
    delete boat;
    delete plane;

    return 0;
}
