#ifndef STRUCT_H
#define STRUCT_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <conio.h>
#include "Struct.h"

using namespace std;

struct Person_arr
{
	string FIO="";
	int day_b = 0;
	int month_b = 0;
	int year_b = 0;
	int gender = 0;
	int old;
};

class Person
{
private:
	string name_file;
	int number_lines; 
	ifstream file;
	vector<Person_arr> arr;
	void add(char new_num, int* ism)
	{
		int num = (int)new_num - 48;
		*ism = (*ism) * 10 + (int)num;
	}
public:
	Person() :
		number_lines(0)
	{}
	void read_file(string new_name_file)
	{
		name_file = new_name_file;
		file.open(name_file, ios_base::in);
		if (!file.is_open())
		{
			throw exception("Файл не открыт, нет файла с таким именем!");
		}
		char* str = new char[1024];
		while (!file.eof())
		{
			Person_arr new_p;
			int number_commas = 0;
			file.getline(str, 1024, '\n');
			for (int i = 0; str[i] != NULL; i++)
			{
				switch (number_commas)
				{
				case 1:
					if (str[i] == ',')
						number_commas++;
					else
						add(str[i], &new_p.day_b);
					break;
				case 2:
					if (str[i] == ',')
						number_commas++;
					else
						add(str[i], &new_p.month_b);
					break;
				case 3:
					if (str[i] == ',')
						number_commas++;
					else
						add(str[i], &new_p.year_b);
					break;
				case 4:
					if (str[i] == ',')
						number_commas++;
					else
						add(str[i], &new_p.gender);
					break;
				default:
					if (str[i] != ',')
						new_p.FIO += str[i];
					else
						number_commas++;
					break;
				}
			}
			new_p.old = 2020 - new_p.year_b;
			number_lines++;
			arr.push_back(new_p);
		}
		file.close();
		delete[] str;
		cout << "Продолжить";
	}
	void add_person()
	{
		Person_arr new_p;
		cout << "Введите ФИО" << endl;
		cin >> new_p.FIO;
		while (getchar() != '\n');
		cout << "Введите дату рождения" << endl;
		cin >> new_p.day_b;
		while (getchar() != '\n');
		cout << "Введите месяц рождения" << endl;
		cin >> new_p.month_b;
		while (getchar() != '\n');
		cout << "Введите год рождения" << endl;
		cin >> new_p.year_b;
		cout << "Введите гендер (1-мужчина, 0-женщина)" << endl;
		do
		{
			while (getchar() != '\n');
			new_p.gender = _getch()-48;
		}
		while ((new_p.gender != 1) && (new_p.gender != 0));
		new_p.old = 2020 - new_p.year_b;
		number_lines++;
		arr.push_back(new_p);
		cout << "Продолжить";
		_getch();
	}
	void add_file(string name_file)
	{
		ofstream o_file;
		o_file.open(name_file, ios_base::out);
		for (int i = 0; i < number_lines; i++)
		{
			o_file << arr[i].FIO << ',';
			o_file << arr[i].day_b << ',';
			o_file << arr[i].month_b << ',';
			o_file << arr[i].year_b << ',';
			o_file << arr[i].gender << endl;
		}
		file.close();
		cout << "Продолжить";
		_getch();
	}
	void show_person(int index = 0)
	{
		if (index == 0)
			for (int i = 0; i < number_lines; i++)
			{
				cout << "ФИО:\t" << arr[i].FIO << endl;
				cout << "\tДата рождения:" << endl;
				cout << "\t" << arr[i].day_b << "." << arr[i].month_b << "." << arr[i].year_b << endl;
			}
		else
		{
			cout << "ФИО:\t" << arr[index].FIO << endl;
			cout << "\tДата рождения:" << endl;
			cout << "\t" << arr[index].day_b << "." << arr[index].month_b << "." << arr[index].year_b << endl;
		}
		cout << "Продолжить";
		_getch();
	}
	void sort_arr(int vib)
	{
		switch (vib)
		{
		case 4:
		{
			auto comp = [](const Person_arr& f, const Person_arr& s)->bool
			{
				return f.FIO[0] < s.FIO[0];
			};
			sort(arr.begin(), arr.end(), comp);
			break;
		}
		case 5:
		{
			auto comp = [](const Person_arr& f, const Person_arr& s)->bool
			{
				return f.old < s.old;
			};
			sort(arr.begin(), arr.end(), comp);
			break;
		}
		}
		cout << "Продолжить";
		_getch();
	}
	void second_name_chosen_leter(char leter)
	{
		for (int i = 0; i < number_lines; i++)
		{
			if (arr[i].FIO[0] == leter)
				cout << arr[i].FIO << endl;
		}
		cout << "Продолжить";
		_getch();
	}
	void month_chosen(int month)
	{
		cout << "Люди родившиеся в " << month << " месяце" << endl;;
		for (int i = 0; i < number_lines; i++)
		{
			if (arr[i].month_b == month)
				cout << "\t" << arr[i].FIO << endl;
		}
		cout << "Продолжить";
		_getch();
	}
	void old_men_second_name()
	{
		int max = 0;
		int index = -1;
		for (int i = 0; i < number_lines; i++)
		{
			if ((arr[i].gender) && (arr[i].old > max))
			{
				max = arr[i].old;
				index = i;
			}
		}
		if (index!=-1)
		{
			cout << "Старший мужчина\n\t" << arr[index].FIO << endl;
		}
		cout << "Продолжить";
		_getch();
	}
	~Person()
	{
		add_file("file_save.txt");
	}

	

};

#endif // !STRUCT_H

