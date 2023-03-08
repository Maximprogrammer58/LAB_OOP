#include "../include/menu_functions.h"

void menu::text_menu()
{
	std::cout << " _____________________________________________________" << std::endl;
	std::cout << " |                      Меню                         |" << std::endl;
	std::cout << " -----------------------------------------------------" << std::endl;
	std::cout << " | 1 - вставить элемент в конец                      |" << std::endl;
	std::cout << " | 2 - вставить элемент по индексу                   |" << std::endl;
	std::cout << " | 3 - удалить элемент по индексу                    |" << std::endl;
	std::cout << " | 4 - вывести список на экран                       |" << std::endl;
	std::cout << " | 5 - поиск первого транспорта с наибольшим налогом |" << std::endl;
	std::cout << " | 6 - завершить работу                              |" << std::endl;
	std::cout << " -----------------------------------------------------" << std::endl;
}

int menu::get_key()
{
	int key = _getch();
	if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54))
		return key;
}