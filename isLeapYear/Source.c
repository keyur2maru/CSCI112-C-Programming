#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int isLeapYear(int year)
{
	return ((!(year % 4) && year % 100) || !(year % 400));
}


int main(void) {
	int year;

	while (1)
	{
		scanf("%d", &year);
		if (isLeapYear(year))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
