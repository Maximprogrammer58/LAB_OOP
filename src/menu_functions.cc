#include "../include/menu_functions.h"

void menu::text_menu()
{
	std::cout << " _____________________________________________________" << std::endl;
	std::cout << " |                      ����                         |" << std::endl;
	std::cout << " -----------------------------------------------------" << std::endl;
	std::cout << " | 1 - �������� ������� � �����                      |" << std::endl;
	std::cout << " | 2 - �������� ������� �� �������                   |" << std::endl;
	std::cout << " | 3 - ������� ������� �� �������                    |" << std::endl;
	std::cout << " | 4 - ������� ������ �� �����                       |" << std::endl;
	std::cout << " | 5 - ����� ������� ���������� � ���������� ������� |" << std::endl;
	std::cout << " | 6 - ��������� ������                              |" << std::endl;
	std::cout << " -----------------------------------------------------" << std::endl;
}

int menu::get_key()
{
	int key = _getch();
	if ((key == 49) || (key == 50) || (key == 51) || (key == 52) || (key == 53) || (key == 54))
		return key;
}