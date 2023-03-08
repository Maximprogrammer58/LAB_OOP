#pragma once

#include <iostream>
#include <stdexcept>
#include <string>

enum ETypeVehicle { PassengerCar, Truck, Motorcycle };

class Vehicle
{
    ETypeVehicle type;
    std::string name;
    double engine_capacity;
    double load_capacity;

public:
    Vehicle() {};

	Vehicle(ETypeVehicle type, std::string name, double engine_capacity) : type(type), name(name), engine_capacity(engine_capacity) {};

	Vehicle(ETypeVehicle type, std::string name, double engine_capacity, double load_capacity) : type(type), name(name), engine_capacity(engine_capacity), load_capacity(load_capacity) {};

    double transport_tax(const double S) const;

	double get_engine_capacity() const;

	double get_load_capacity() const;

	std::string get_type() const;

	const std::string& get_name() const;
};

std::ostream& operator<<(std::ostream& stream, const Vehicle& Car);