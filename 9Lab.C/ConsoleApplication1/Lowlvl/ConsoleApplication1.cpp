#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;

//Легкий уровень: Вывести дату в формате: числовое значение без начальных нулей, полное название дня недели и месяца, полный год.
//Написать программу, которая определяет за сколько спортсмен пробежит 3000 метров в секундах и вывести его скорость в м/c.

struct Date
{
	int day;
	int month;
	int year;
	bool isDateCorrect();
};

struct Week
{
	int number_of_the_day;
	bool isWeekCorrect();
};

bool Date::isDateCorrect()
{
	bool result = false;

	switch (month)
	{
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
	{
		if ((day >= 1) && (day <= 31) && (year < 2021))
			result = true;
		break;
	}
	case 4:
	case 6:
	case 9:
	case 11:
	{
		if ((day > 0) && (day <= 30) && (year < 2021))
			result = true;
		break;
	}
	case 2:
	{
		if (year % 4 != 0)
		{
			if ((day > 0) && (day <= 28) && (year < 2021))
				result = true;
		}
		else
		{
			if ((day > 0) && (day <= 29) && (year < 2021))
				result = true;
		}
		break;
	}

	default:
		result = false;
	}

	return result;
}

bool Week::isWeekCorrect()
{
	bool result = false;

	switch (number_of_the_day)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	{
		result = true;
		break;
	}

	default:
		result = false;
	}

	return result;
}

void easy()
{
	Date date;
	Week week;
	double seconds, meter_in_second;
	struct tm* entered, start_time;
	char formatted[80];
	time_t entered_time = time(NULL), start;
	entered = localtime(&entered_time);

	do
	{
		cout << "Введите число, день недели, месяц и год для форматирования: ";
		cin >> date.day >> week.number_of_the_day >> date.month >> date.year;
		cout << endl;
	} while (!date.isDateCorrect() || !week.isWeekCorrect());

	entered->tm_mday = date.day;
	entered->tm_wday = week.number_of_the_day - 1;
	entered->tm_mon = date.month - 1;
	entered->tm_year = date.year - 1900;

	strftime(formatted, sizeof(formatted), "%e %A %B %G", entered);
	cout << "Введенное время: " << formatted << endl << endl;

	cout << "Теперь введите время начала бега спортсмена(месяц, число, день недели, часы, минуты, секунды(год вы ввели раньше)): ";
	cin >> start_time.tm_mon >> start_time.tm_mday >> start_time.tm_wday >> start_time.tm_hour >> start_time.tm_min >> start_time.tm_sec;

	start_time.tm_mon -= 1;
	start_time.tm_wday -= 1;

	cout << endl;

	time(&start);
	start_time = *localtime(&start);
	seconds = difftime(start, mktime(&start_time));

	cout << "Времени прошло с начала бега спортсмена: " << seconds << endl;

	meter_in_second = 3000 / seconds;

	cout << "Скорость, с которой спортсмен пробежал 3000 метров: " << meter_in_second << " м/c" << endl << endl;
}

int main()
{
	setlocale(LC_ALL, "RU");
	easy();
}