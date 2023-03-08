#define EPSILON 1e-5

#include <gtest/gtest.h>
#include "../include/Vehicle.h"
#include "../include/VehiclesList.h"

TEST(VehicleListTest_IndexMaxTax, TestMaxTax)
{
	VehiclesList list;
	list.add({ PassengerCar, "GAZ-3110" , 2.4f });
	list.add({ Truck, "GAZ-53", 3.5f, 3.5f });
	list.add({ PassengerCar, "Lamborghini Urus" , 4.0f });
	list.add({ Motorcycle, "BMW R1200GS", 1.2f });

	int index = list.index_of_max_tax(50);

	EXPECT_EQ(index, 1);
}

TEST(VehicleListTestRemoveException, TestRemoveZeroIndex)
{
	VehiclesList list;

	ASSERT_ANY_THROW(list.remove(0));
}

TEST(VehicleListTestExceptions, TestInsert)
{
	VehiclesList list;
	list.add({ PassengerCar, "GAZ-3110" , 2.4f });
	list.add({ Truck, "GAZ-53", 3.5f, 3.5f });
	list.add({ PassengerCar, "Lamborghini Urus" , 4.0f });
	list.add({ Motorcycle, "BMW R1200GS", 1.2f });

	ASSERT_ANY_THROW(list.insert({ PassengerCar, "Bugatti Veyron" , 8.0f }, 50));
}

TEST(VehicleListTestExceptions, Test_get)
{
	VehiclesList list;
	list.add({ PassengerCar, "GAZ-3110" , 2.4f });
	list.add({ Truck, "GAZ-53", 3.5f, 3.5f });
	list.add({ PassengerCar, "Lamborghini Urus" , 4.0f });
	list.add({ Motorcycle, "BMW R1200GS", 1.2f });

	ASSERT_ANY_THROW(list[20]);
}

TEST(VehicleListTestExceptions, TestRemove)
{
	VehiclesList list;
	list.add({ PassengerCar, "GAZ-3110" , 2.4f });
	list.add({ Truck, "GAZ-53", 3.5f, 3.5f });
	list.add({ PassengerCar, "Lamborghini Urus" , 4.0f });
	list.add({ Motorcycle, "BMW R1200GS", 1.2f });

	ASSERT_ANY_THROW(list.remove(-1));
}

TEST(VehicleListTestExceptions, TestGetItem)
{
	VehiclesList list;
	list.add({ PassengerCar, "GAZ-3110" , 2.4f });
	list.add({ Truck, "GAZ-53", 3.5f, 3.5f });
	list.add({ PassengerCar, "Lamborghini Urus" , 4.0f });
	list.add({ Motorcycle, "BMW R1200GS", 1.2f });

	ASSERT_ANY_THROW(list.get_item(10));
}

TEST(VehicleListTestMethods, TestGetSize)
{
	VehiclesList list;
	list.add({ Motorcycle, "BMW R1200GS", 1.2f });
	list.add({ Truck, "GAZ-53", 3.5f, 3.5f });
	list.add({ PassengerCar, "Lamborghini Urus" , 4.0f });
	list.insert({ PassengerCar, "Bugatti Veyron" , 8.0f }, 2);
	list.remove(2);

	int length = list.get_size();

	EXPECT_EQ(length, 3);
}

TEST(VehicleListTestMethods, TestTransportTax)
{
	VehiclesList list;
	list.add({ Motorcycle, "BMW R1200GS", 1.2f });
	list.add({ Truck, "GAZ-53", 3.5f, 3.5f });
	list.add({ PassengerCar, "Lamborghini Urus" , 4.0f });
	list.insert({ PassengerCar, "Bugatti Veyron" , 8.0f }, 2);
	list.remove(2);

	double tax = list[2].transport_tax(150);

	EXPECT_NEAR(tax, 600.0f, EPSILON);
}

TEST(VehicleListTestMethods, TestCopyAndGetEngineCapacity)
{
	VehiclesList list;
	list.add({ Motorcycle, "BMW R1200GS", 1.2f });
	list.add({ Truck, "GAZ-53", 3.5f, 3.5f });
	list.add({ PassengerCar, "Lamborghini Urus" , 4.0f });

	list[0] = { PassengerCar, "Lamborghini Urus" , 4.0f };
	double engine_capacity = list[0].get_engine_capacity();

	EXPECT_NEAR(engine_capacity, 4.0f, EPSILON);
}