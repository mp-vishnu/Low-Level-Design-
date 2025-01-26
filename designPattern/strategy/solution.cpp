#include <iostream>
#include <string>
using namespace std;

// Abstract Strategy class
class DriveStrategy
{
public:
    virtual void drive() const = 0;     // Pure virtual function
    virtual ~DriveStrategy() = default; // Virtual destructor for proper cleanup
};

// Concrete Strategy for Car
class CarDriveStrategy : public DriveStrategy
{
public:
    void drive() const override
    {
        cout << "Driving on roads." << endl;
    }
};

// Concrete Strategy for Boat
class BoatDriveStrategy : public DriveStrategy
{
public:
    void drive() const override
    {
        cout << "Driving on water." << endl;
    }
};

// Concrete Strategy for Plane
class PlaneDriveStrategy : public DriveStrategy
{
public:
    void drive() const override
    {
        cout << "Flying in the air." << endl;
    }
};

// Context class (Vehicle)
class Vehicle
{
private:
    DriveStrategy *driveStrategy; // Pointer to strategy

public:
    Vehicle(DriveStrategy *strategy) : driveStrategy(strategy) {}

    // Method to set a new strategy at runtime
    void setDriveStrategy(DriveStrategy *strategy)
    {
        driveStrategy = strategy;
    }

    void performDrive() const
    {
        driveStrategy->drive(); // Delegate driving behavior to the strategy
    }

    ~Vehicle() = default; // Destructor to clean up strategy
};

int main()
{
    // Create different driving strategies
    CarDriveStrategy carStrategy;
    BoatDriveStrategy boatStrategy;
    PlaneDriveStrategy planeStrategy;

    // Create a Vehicle object with the initial strategy (Car)
    Vehicle vehicle(&carStrategy);
    cout << "Initial Vehicle behavior: ";
    vehicle.performDrive(); // Outputs: Driving on roads.

    // Change the strategy at runtime (Boat)
    vehicle.setDriveStrategy(&boatStrategy);
    cout << "After changing strategy to Boat: ";
    vehicle.performDrive(); // Outputs: Driving on water.

    // Change the strategy again (Plane)
    vehicle.setDriveStrategy(&planeStrategy);
    cout << "After changing strategy to Plane: ";
    vehicle.performDrive(); // Outputs: Flying in the air.

    return 0;
}
