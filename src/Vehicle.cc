#include <cstdio>
#include <string>
#include <stdexcept>
#include "../include/Vehicle.h"

using namespace std;

const string& Vehicle::get_name() const { return name; }

double Vehicle::get_engine_capacity() const { return engine_capacity; }

double Vehicle::get_load_capacity() const
{
    if (type == Truck)
        return load_capacity;
    throw runtime_error("no load capacity");
}

std::string Vehicle::get_type() const
{
    switch (type)
    {
        case PassengerCar:
            return "PassengerCar";
        case Truck:
            return "Truck";
        case Motorcycle:
            return "MotorCycle";
        default:
            throw runtime_error("Unknown type");
    }
}

double Vehicle::transport_tax(const double S) const
{
    switch (type)
    {
        case PassengerCar:
            return S * engine_capacity;
        case Truck:
            return S * engine_capacity * (load_capacity / 2 + 1);
        case Motorcycle:
            return 0.3 * S * engine_capacity;
        default:
            throw runtime_error("Unknown type");
    }
}