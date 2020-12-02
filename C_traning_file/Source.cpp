#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Struct.h"

using namespace std;

void menu()
{
	system("cls");
	cout << "1-��������� ������ �� ����� " << endl;
	cout << "2-������ ������ " << endl;
	cout << "3-���������� ������ " << endl;
	cout << "4-���������� ���� ������ �� �������� " << endl;
	cout << "5-���������� ���� ������ �� �������� " << endl;
	cout << "6-�����: ������ �����, ���������� � �������� ������ " << endl;
	cout << "7-�����: ������� ������ �������� �������  " << endl;
	cout << "8-�����: ��� �������, ������������ � �������� ����� " << endl;
	cout << "0- ����� �� ��������� " << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Person f;
	int vib = -1;
	while (vib != 0)
	{
		menu();
		//while (getchar() != '\n');
		vib = _getch() - 48;
		switch (vib)
		{
		case 1:
		{
			cout << "������� ��� ����� ";
			string name_file;
			cin >> name_file;
			try
			{
				f.read_file(name_file);
			}
			catch (const std::exception& e)
			{
				cout << e.what() << endl;
			}
			break;
			_getch();
		}
		case 2:
		{
			f.add_person();
			_getch();
			break;
		}
		case 3:
		{
			string name_file;
			cout << "������� ��� ����� ";
			cin >> name_file;
			f.add_file(name_file);
			break;
		}
		case 4:
		{
			f.sort_arr(4);
			break;
		}
		case 5:
		{
			f.sort_arr(5);
			break;
		}
		case 6:
		{
			int month;
			cout << "������� ����� ";
			do
			{
				cin >> month;
			} while ((month<0)&&(month>12));
			f.month_chosen(month);
			break;
		}
		case 7:
		{
			f.old_men_second_name();
			break;
		}
		case 8:
		{
			char leter;
			cin >> leter;
			f.second_name_chosen_leter(leter);
			break;
		}
		case 9:
		{
			f.show_person();
			_getch();
			break;
		}
		case 0:
		{
			vib = 0;
			break;
		}
		}
	}
}