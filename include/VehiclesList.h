#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

class VehiclesList
{
	static const int CAPACITY = 10;
	Vehicle* list;
	int size;

public:
	VehiclesList() : size(0), list(new Vehicle[CAPACITY]()) {};

	~VehiclesList();

	VehiclesList(const VehiclesList& rhs);

	VehiclesList& operator=(const VehiclesList& rhs);

	int get_size() const;

	int index_of_max_tax(const double S) const;

	void add(Vehicle Car);

	void insert(Vehicle Car, int index);

	void remove(int index);

	void clear();

	void swap_function(VehiclesList& rhs);

	Vehicle get_item(int index) const;

	Vehicle& operator[](int index);

	Vehicle* const get_list() const;

	const Vehicle& operator[](int index) const;
};

std::ostream& operator<<(std::ostream& stream, const VehiclesList& list);