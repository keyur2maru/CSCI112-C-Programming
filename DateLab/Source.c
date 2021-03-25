#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int displayMenu(int* option);
void getJulianDate(int* jyear, int* year);
void getCalendarDate(int* cmonth, int* cday, int* cyear);
int isLeapYear(int year);
int toJulian(int month, int day, int year, int* option);
void toCalendar(int jyear, int year, int option);
void swap(int*, int*);
int daysInYear(int year);
void daysBetweenYears();

int main(void) {
	int jyear, year;
	int option, month, day;

	displayMenu(&option);

	do {
		if (option == 1) {
			getCalendarDate(&month, &day, &year);
			toJulian(month, day, year, &option);

		}
		else if (option == 2) {
			getJulianDate(&jyear, &year);
			toCalendar(jyear, year, option);
		}
		else if (option == 3) {
			daysBetweenYears();
		}
		else {
			exit(1);
		}
	} while (displayMenu(&option) && 1);
	getchar();
	return 0;
}

int displayMenu(int* option) {
	printf("DATE SELECTION MENU\n\n");

	printf("(1) Convert calendar date into Julian date\n");
	printf("(2) Convert Julian date into calendar date\n");
	printf("(3) Compute days between two calendar dates\n");
	printf("(4) Exit program\n");

	printf("\nENTER SELECTION(1-4):");
	scanf("%d", option);

	if (*option >= 1 && *option < 4)
	{
		printf("%d\n", *option);
	}
	else if (*option == 4)
	{
		printf("User has exited the program.\n");

	}
	else
	{
		printf("User entered invalid selection.\n");
	}

	return *option;
}

void getJulianDate(int* jyear, int* year)
{
	scanf("%d %d", jyear, year);
}

void getCalendarDate(int* cmonth, int* cday, int* cyear)
{
	scanf("%d %d %d", cmonth, cday, cyear);
}

int isLeapYear(int year)
{
	return ((!(year % 4) && year % 100) || !(year % 400));
}

int toJulian(int month, int day, int year, int* option)
{
	int days = day;
	switch (month)
	{
	case 12: days += 30;
	case 11: days += 31;
	case 10: days += 30;
	case 9:  days += 31;
	case 8:  days += 31;
	case 7:  days += 30;
	case 6:  days += 31;
	case 5:  days += 30;
	case 4:  days += 31;
	case 3: days += 28 + isLeapYear(year);
	case 2:  days += 31;
	}

	if (*option == 1)
	{
		printf("%d %d\n", days, year);
	}
	return days;
}

void toCalendar(int jyear, int year, int option)
{
	int month, day;

	for (month = 1; month < 12; month++)
		if (jyear < toJulian(month + 1, 1, year, &option)) break;
	day = jyear - toJulian(month, 1, year, &option) + 1;
	printf("%d %d %d\n", month, day, year);
}

void swap(int* a, int* b)
{
	int t;

	t = *b;
	*b = *a;
	*a = t;
}

int daysInYear(int year)
{

	int numDays;
	if (isLeapYear(year) == 1)
		numDays = 366;
	else
		numDays = 365;

	return numDays;
}

void daysBetweenYears()
{
	int year1, year2, option;
	int numDays = 0;
	int day1 = 0;
	int day2 = 0;
	int month1 = 0;
	int month2 = 0;

	scanf("%d %d %d", &month1, &day1, &year1);
	scanf("%d %d %d", &month2, &day2, &year2);

	if (year1 > year2)
	{
		swap(&month1, &month2);
		swap(&day1, &day2);
		swap(&year1, &year2);
	}
	else if (year1 == year2 && month1 > month2)
	{
		swap(&month1, &month2);
		swap(&day1, &day2);
		swap(&year1, &year2);
	}
	else if (year1 == year2 && month1 == month2 && day1 > day2)
	{
		swap(&month1, &month2);
		swap(&day1, &day2);
		swap(&year1, &year2);
	}

	while (year1 < year2)
	{
		numDays += daysInYear(year1);
		year1++;
	}

	numDays += toJulian(month2, day2, year2, &option);
	numDays -= toJulian(month1, day1, year1, &option);
	printf("%d\n", numDays);
}


