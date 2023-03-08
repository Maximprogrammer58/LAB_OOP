#include "../include/VehiclesList.h"
#include "../include/Vehicle.h"

using namespace std;

VehiclesList::~VehiclesList()
{
	delete[] list;
}

Vehicle* const VehiclesList::get_list() const
{
	return list;
}

ostream& operator<<(ostream& stream, const VehiclesList& List)
{
	stream << List.get_size() << " vehicles:" << endl;
	for (int i = 0; i < List.get_size(); ++i)
		cout << "  " << i + 1 << ") " << List.get_list()[i];
	return stream;
}

VehiclesList::VehiclesList(const VehiclesList& rhs)
{
	size = rhs.get_size();
	list = new Vehicle[rhs.get_size()]();

	for (int i = 0; i < size; i++)
		list[i] = rhs.get_list()[i];
}

VehiclesList& VehiclesList::operator=(const VehiclesList&  rhs)
{
	VehiclesList copy(rhs);
	swap_function(copy);
	return *this;
}

void VehiclesList::swap_function(VehiclesList& rhs)
{
	int rhs_size = rhs.get_size();
	Vehicle* rhs_list = rhs.get_list();

	swap(size, rhs_size);
	swap(list, rhs_list);
}

void VehiclesList::add(Vehicle Car)
{
	if (size == CAPACITY)
		throw runtime_error("Going outside the array");

	list[size] = Car;
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
		list[i] = list[i - 1];

	list[index] = Car;

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
		list[i] = list[i + 1];
}

void VehiclesList::clear() { size = 0; }

Vehicle VehiclesList::get_item(int index) const
{
	if (index < 0 || size <= index)
		throw runtime_error("Invalid index");
	return list[index];
}

Vehicle& VehiclesList::operator[](int index)
{
	if (index < 0 || size <= index)
		throw runtime_error("Invalid index");
	return list[index];
}

const Vehicle& VehiclesList::operator[](int index) const
{
	if (index < 0 || size <= index)
		throw runtime_error("Invalid index");
	return list[index];
}

int VehiclesList::index_of_max_tax(const double S) const
{
	int first_index = -1;
	double max_tax = 0;

	for (int i = 0; i < size; i++)
	{
		const double tax = list[i].transport_tax(S);
		if ((first_index == -1) || (max_tax < tax))
		{
			first_index = i;
			max_tax = tax;
		}
	}

	return first_index;
}