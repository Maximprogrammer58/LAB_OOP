#include <cstdio>
#include <stdexcept>
#include "../include/Vehicle.h"

using namespace std;

void VehiclesList::add(Vehicle Car)
{
	if (size == CAPACITY)
		throw runtime_error("Going outside the array");

	List[size] = Car;
	++size;
}

int VehiclesList::get_size() const { return size; }

void VehiclesList::insert(Vehicle Car, int index)
{
	if (size >= CAPACITY)
		throw runtime_error("Going outside the array");

	if (index < 0 || size <= index)
		throw runtime_error("Invalid index");

	for (int i = size; i > index; --i)
		List[i] = List[i - 1];

	List[index] = Car;

	++size;
}

void VehiclesList::remove(int index)
{
	if (size <= 0)
		throw runtime_error("Going outside the array");

	if (index < 0 || size <= index)
		throw runtime_error("Invalid index");

	--size;
	for (int i = index; i < size; i++)
		List[i] = List[i + 1];
}

void VehiclesList::clear() { size = 0; }

Vehicle VehiclesList::get_item(int index) const
{
	if (index < 0 || size <= index)
		throw runtime_error("Invalid index");
	return List[index];
}

Vehicle& VehiclesList::operator[](int index)
{
	if (index < 0 || size <= index)
		throw runtime_error("Invalid index");
	return List[index];
}

const Vehicle& VehiclesList::operator[](int index) const
{
	if (index < 0 || size <= index)
		throw runtime_error("Invalid index");
	return List[index];
}

int VehiclesList::index_of_max_tax(const double S) const
{
	int first_index = -1;
	double max_tax = 0;

	for (int i = 0; i < size; i++)
	{
		const double tax = List[i].transport_tax(S);
		if ((first_index == -1) || (max_tax < tax))
		{
			first_index = i;
			max_tax = tax;
		}
	}

	return first_index;
}