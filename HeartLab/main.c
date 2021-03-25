# define _CRT_SECURE_NO_WARNINGS
# define DAYS_PER_YEAR 365 
# define HOURS_PER_DAY 24
# define MIN_PER_HOUR 60 

#include <stdio.h>


int main() {
	int TOTAL_YEARS, TOTAL_BEATS, HB_PER_MINUTE;



	scanf("%d", &TOTAL_YEARS);
	scanf("%d", &HB_PER_MINUTE);

	TOTAL_BEATS = HB_PER_MINUTE * MIN_PER_HOUR * HOURS_PER_DAY * DAYS_PER_YEAR * TOTAL_YEARS;


	printf("The heart beats %d times.\n \n", TOTAL_BEATS);


	main();
	return 0;
}