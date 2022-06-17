#include <iostream>
#include "Stack.h"

using namespace std;

void foo1();
void foo2();
template <class T>
double average(T* arr, int size);
template<class T>
void check_stack();



int main()
{
	setlocale(0, "rus");
	char menu;
	while (1)	// главное меню
	{
		cout << "Меню"
			<< "\n  1.Функция-шаблон, вычисляющая среднее арифметическое"
			<< "\n  2.Функционал параметризованного стека"
			<< "\n  0.Выход\n-> ";
		cin >> menu;

		system("cls");

		switch (menu)
		{
		case '1': foo1();	break;
		case '2': foo2();	break;
		case '0':			return 0;
		}
	}
	return 0;
}


void foo1()
{
	char menu_1;
	while (1)
	{
		cout << "\n[Задание 1]: Выбор типа данных "
			<< "\n     1. int"
			<< "\n     2. float"
			<< "\n     3. double"
			<< "\n     0. Назад\n-> ";
		cin >> menu_1;
		if (menu_1 == '0') return;
		srand(int(time(0)));
		int size;
		do
		{
			cout << "Введите размер массива: ";
			cin >> size;
		} while (size < 1);

		system("cls");

		switch (menu_1)
		{
		case '1': {
			int* arr = new int[size];
			for (int i = 0; i < size; i++)
				arr[i] = int(rand() % 51);
			for (int i = 0; i < size; i++)
				cout << "[" << arr[i] << "] ";
			cout << "\nСреднее арифметическое: " << average<int>(arr, size);
			delete[] arr;
			break; }
		case '2': {
			float* arr = new float[size];
			for (int i = 0; i < size; i++)
				arr[i] = float(rand() % 51 + 0.0 + float(rand() % 100) / 100.0);
			for (int i = 0; i < size; i++)
				cout << "[" << arr[i] << "] ";
			cout << "\nСреднее арифметическое: " << average<float>(arr, size);
			delete[] arr;
			break; }
		case '3': {
			double* arr = new double[size];
			for (int i = 0; i < size; i++)
				arr[i] = double(rand() % 51 + 0.0 + double(rand() % 100000) / 100000.0);
			for (int i = 0; i < size; i++)
				cout << "[" << arr[i] << "] ";
			cout << "\nСреднее арифметическое: " << average<double>(arr, size);
			delete[] arr;
			break; }
		}
	}
}
template <class T>
double average(T* arr, int size)
{
	T av = arr[0];
	for (int i = 1; i < size; av += arr[i++]);
	return av / size;
}

void foo2()
{
	char menu_2;
	while (1)
	{
		cout << "\n[Задание 2]: Выбор типа данных"
			<< "\n     1. int"
			<< "\n     2. char"
			<< "\n     3. float"
			<< "\n     4. double"
			<< "\n     0. Назад\n-> ";
		cin >> menu_2;

		system("cls");

		switch (menu_2)
		{
		case '1': {
			check_stack<int>();
			break; }
		case '2': {
			check_stack<char>();
			break; }
		case '3': {
			check_stack<float>();
			break; }
		case '4': {
			check_stack<double>();
			break; }
		case '0':
			system("cls");
			return;
		}
	}
}

template<class T>
void check_stack()
{
	srand(size_t(time(0)));
	char num;
	Stack<T> S1, S2;
	while (1)
	{
		cout << "\n  1. Ввод стека"
			<< "\n  2. Вывод стека на экран"
			<< "\n  3. Перегрузка оператора +="
			<< "\n  4. Перегрузка оператора -"
			<< "\n  5. Перегрузка оператора ="
			<< "\n  0. Назад\n-> ";
		cin >> num;

		system("cls");

		switch (num)	// соответственно вызываем методы		
		{
		case '1': {
			cout << "   Выберете стек"
				<< "\n    1. первый"
				<< "\n    2. второй"
				<< "\n    0. Назад\n-> ";
			cin >> num;
			switch (num)
			{
			case '1': {
				cout << "     Введите " << S1.get_size() << " элементов через пробел\n-> ";
				cin >> S1;
				break; }
			case '2': {
				cout << "     Введите " << S2.get_size() << " элементов через пробел\n-> ";
				cin >> S2;
				break; }
			}
			break; }
		case '2': {
			if (S1.isempty())
				cout << "   Первый стек пустой" << endl << endl;
			else
				cout << "   Первый стек: " << endl << S1 << endl << endl;
			if (S2.isempty())
				cout << "   Второй стек пустой" << endl;
			else
				cout << "   Второй стек: " << endl << S2 << endl;
			break; }
		case '3': {
			T el;
			cout << "   Выберете стек"
				<< "\n    1. первый"
				<< "\n    2. второй"
				<< "\n    0. Назад\n-> ";
			cin >> num;
			switch (num)
			{
			case '1': {
				if (S1.isfull())
				{
					cout << "     Стек полон" << endl;
					break;
				}
				cout << "     Введите элемент: ";
				cin >> el;
				S1 += el;
				break; }
			case '2': {
				if (S2.isfull())
				{
					cout << "     Стек полон" << endl;
					break;
				}
				cout << "     Введите элемент: ";
				cin >> el;
				S2 += el;
				break; }
			}
			break; }
		case '4': {
			T el;
			cout << "   Выберете стек"
				<< "\n    1. первый"
				<< "\n    2. второй"
				<< "\n    0. Назад\n-> ";
			cin >> num;
			switch (num)
			{
			case '1': {
				if (S1.isempty())
					cout << "     Стек пустой" << endl;
				else
					cout << "     Последний элемент: " << -S1 << endl;
				break; }
			case '2': {
				if (S2.isempty())
					cout << "     Стек пустой" << endl;
				else
					cout << "     Последний элемент: " << -S2 << endl;
				break; }
			}
			break; }
		case '5': {
			cout << "\n    1. первый = второй"
				<< "\n    2. второй = первый"
				<< "\n    0. Назад\n-> ";
			cin >> num;

			switch (num)
			{
			case '1':
				S1 = S2;
				break;
			case '2':
				S2 = S1;
				break;
			}
			break; }
		case '0':
			system("cls");
			return;
		}
	}
}