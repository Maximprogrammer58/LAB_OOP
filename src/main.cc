#include <clocale>
#include <Windows.h>
#include "../include/Vehicle.h"
#include "../include/VehiclesList.h"
#include "../include/menu_functions.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);

	VehiclesList list;
	
	menu::text_menu();

	while (true)
	{
		int choice = menu::get_key();

		string name;
		int type;
		int index;
		double engine_capacity;
		double load_capacity;

		system("cls");
		menu::text_menu();

		if (choice == 54)
			break;

		switch (choice)
		{
			case 49:
				cout << "Введите название: ";
				getline(cin >> ws, name);
				cout << "Введите тип ТС(0 - легковой, 1 - грузовой, 2 - мотоцикл): ";
				cin >> type;
				if ((ETypeVehicle)type == Truck)
				{
					cout << "Введите объём двигателя в литрах: ";
					cin >> engine_capacity;
					cout << "Введите грузоподъёмность в тоннах: ";
					cin >> load_capacity;
					list.add({(ETypeVehicle)type, name, engine_capacity, load_capacity });
				}
				else
				{
					cout << "Введите объём двигателя в литрах: ";
					cin >> engine_capacity;
					list.add({(ETypeVehicle)type, name, engine_capacity});
				}
				cout << list;
				break;

			case 50:
				cout << "Введите индекс для вставки: ";
				cin >> index;
				cout << "Введите название: ";
				getline(cin >> ws, name);
				cout << "Введите тип ТС(0 - легковой, 1 - грузовой, 2 - мотоцикл): ";
				cin >> type;
				if ((ETypeVehicle)type == Truck)
				{
					cout << "Введите объём двигателя в литрах: ";
					cin >> engine_capacity;
					cout << "Введите грузоподъёмность в тоннах: ";
					cin >> load_capacity;
					list.insert({ (ETypeVehicle)type, name, engine_capacity, load_capacity }, index);
				}
				else
				{
					cout << "Введите объём двигателя в литрах: ";
					cin >> engine_capacity;
					list.insert({ (ETypeVehicle)type, name, engine_capacity }, index);
				}
				cout << list;
				break;

			case 51:
				cout << "Введите индекс для удаления: ";
				cin >> index;
				list.remove(index);
				cout << list;
				break;

			case 52:
				cout << list;
				break;

			case 53:
				int s = 0;
				cout << "Введите базовую ставку: ";
				cin >> s;
				if (s > 0)
				{
					int index = list.index_of_max_tax(s);
					if (index == -1)
						cout << "Список пуст" << endl;
					else
						cout << index + 1 << ") " << list.get_list()[index];
				}
				else
					cout << "Некорректная величина базовой ставки" << endl;
				break;
		}
	}

	cout << "Программа завершена" << endl;

	return 0;
}