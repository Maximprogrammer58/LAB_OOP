#define EPSILON 1e-5

#include <gtest/gtest.h>
#include "../include/Vehicle.h"

using namespace std;

TEST(VehicleTaxTest, TestForPassengerCar) 
{
	Vehicle Car1(PassengerCar, "Lamborghini Urus" , 4.0f);

	double r1 = Car1.transport_tax(150);

	EXPECT_NEAR(r1, 600.0f, EPSILON);
}

TEST(VehicleTaxTest, TestForTruck)
{
	Vehicle Car2(Truck, "GAZ-53", 3.5f, 3.5f);

	double r2 = Car2.transport_tax(30);

	EXPECT_NEAR(r2, 288.75f, EPSILON);
}

TEST(VehicleTaxTest, TestForMotorcycle)
{
	Vehicle Car3(Motorcycle, "BMW R1200GS", 1.2f);

	double r3 = Car3.transport_tax(50);

	EXPECT_NEAR(r3, 18.0f, EPSILON);
}

TEST(VehicleGetField_V_Test, TestGetEngineCapacity)
{
	Vehicle Car1(Truck, "GAZ-53", 3.5f, 3.5f);
	
	double engine_capacity = Car1.get_engine_capacity();
	
	EXPECT_NEAR(engine_capacity, 3.5f, EPSILON);
}

TEST(VehicleGetField_T_Test, TestGetT)
{
	Vehicle Car1(Truck, "GAZ-53", 3.5f, 3.5f);

	double load_capacity = Car1.get_load_capacity();

	EXPECT_NEAR(load_capacity, 3.5f, EPSILON);
}

TEST(VehicleGetField_NAME_Test, TestGetName)
{
	Vehicle Car1(Truck, "GAZ-53", 3.5f, 3.5f);

	string name = Car1.get_name();

	EXPECT_EQ(name, "GAZ-53");
}

TEST(VehicleGetField_TYPE_Test, TestGetType)
{
	Vehicle Car1(Truck, "GAZ-53", 3.5f, 3.5f);

	string type = Car1.get_type();

	EXPECT_EQ(type, "Truck");
}

TEST(VehicleGetField_THROW_Test, TestThrowGetT)
{
	Vehicle Car2(PassengerCar, "Lamborghini Urus", 4.0f);

	ASSERT_ANY_THROW(Car2.get_load_capacity());
}