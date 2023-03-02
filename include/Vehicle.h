#pragma once

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

class VehiclesList
{
	static const int CAPACITY = 10;
	Vehicle List[CAPACITY];
	int size;

public:
	VehiclesList() : size(0) {};

	int get_size() const;

	int index_of_max_tax(const double S) const;

	void add(Vehicle Car);

	void insert(Vehicle Car, int index);

	void remove(int index);

	void clear();

	Vehicle get_item(int index) const;

	Vehicle& operator[](int index);

	const Vehicle& operator[](int index) const;
};