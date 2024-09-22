#include <iostream>
#include <windows.h>
using namespace std;


void First()
{
	cout << "int: " << sizeof(int) << endl;
	cout << "short int: " << sizeof(short int) << endl;
	cout << "long int: " << sizeof(long int) << endl;
	cout << "long long int: " << sizeof(long long int) << endl;
	cout << "float: " << sizeof(float) << endl;
	cout << "double: " << sizeof(double) << endl;
	cout << "long double: " << sizeof(long double) << endl;
	cout << "char: " << sizeof(char) << endl;
	cout << "bool: " << sizeof(bool) << endl;
}


void Second()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int color = 9;
	int A;
	int order = sizeof(int) * 8;
	unsigned int mask = 1 << order - 1;
	cout << "Введите число типа int" << endl;
	cin >> A;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Введите ЧИСЛО" << endl;
		cin >> A;
	}

	for (int i = 1; i <= order; ++i)
	{
		SetConsoleTextAttribute(hConsole, color);
		putchar(mask & A ? '1' : '0');
		mask >>= 1;
		if (i % 8 == 0 || i == 1)
		{
			putchar(' ');
			color++;
		}
	}
	SetConsoleTextAttribute(hConsole, 7);
	cout << endl;
}


void Third()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int color = 11;
	union
	{
		int tool;
		float F;
	};
	int order = sizeof(float) * 8;
	unsigned int mask = 1 << order - 1;
	cout << "Введите число типа float" << endl;
	cin >> F;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Введите ЧИСЛО" << endl;
		cin >> F;
	}

	for (int i = 1; i <= order; ++i)
	{
		SetConsoleTextAttribute(hConsole, color);
		putchar(mask & tool ? '1' : '0');
		mask >>= 1;
		if (i == 9 || i == 1)
		{
			putchar(' ');
			color++;
		}
	}
	SetConsoleTextAttribute(hConsole, 7);
	cout << endl;
}


void Fourth()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	int color = 11;
	union {
		int tool[2];
		double D;
	};
	int order = sizeof(D) * 8;
	unsigned int mask = 1;
	mask <<= order - 1;
	cout << "Введите число типа double" << endl;
	cin >> D;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Введите ЧИСЛО" << endl;
		cin >> D;
	}

	for (int i = 1; i >= 0; --i)
	{
		for (int j = 0; j < order / 2; ++j)
		{
			SetConsoleTextAttribute(hConsole, color);
			putchar(mask & tool[i] ? '1' : '0');
			mask >>= 1;
			if ((i == 1 && j == 0) || (i == 1 && j == 11))
			{
				putchar(' ');
				color++;
			}
		}
		mask = 1 << order - 1;
	}
	SetConsoleTextAttribute(hConsole, 7);
	cout << endl;
}


int main()
{
	setlocale(0, "");
	int number;

	while (true)
	{
		cout << "Введите номер задания от 1 до 4" << endl;
		cin >> number;

		while (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Введите ЧИСЛО" << endl;
			cin >> number;
		}

		switch (number)
		{
		case 1:
			First();
			break;
		case 2:
			Second();
			break;
		case 3:
			Third();
			break;
		case 4:
			Fourth();
			break;
		case 666:
			return 0;
		default:
			cout << "Задания с таким номером нет" << endl;
		}
	}
}