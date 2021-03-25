#include<stdio.h>
#define SECS_PER_HOUR 3600 //1 hour = 60mins * 60 secs = 3600 secs
#define METERS_PER_MILE 1600 
int main()
{
	double distance, time, speedmph, speedmps;


	scanf("%lf", &distance);
	scanf("%lf", &time);

	speedmph = distance / time;
	speedmps = (speedmph * METERS_PER_MILE) / SECS_PER_HOUR;

	printf("The speed is %.2lf miles per hour.\n", speedmph);
	printf("The speed is %.2lf meters per second.\n", speedmps);
}
