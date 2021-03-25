#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main(void)
{
	double mass_mercury = 3.3022e+23;
	double mass_venus = 4.8685e+24;
	double mass_earth = 5.9736e+24;
	double mass_mars = 6.4185e+23;
	double mass_jupiter = 1.8986e+27;
	double mass_saturn = 5.6846e+26;
	double mass_uranus = 8.6810e+25;
	double mass_neptune = 1.0243e+26;

	double radius_mercury = 2439.7;
	double radius_venus = 6051.8;
	double radius_earth = 6378.1;
	double radius_mars = 3396.2;
	double radius_jupiter = 71492.0;
	double radius_saturn = 60268.0;
	double radius_uranus = 25559.0;
	double radius_neptune = 24764.0;

	double newton_grav = 6.67408e-17;

	double grav_mercury;
	double grav_venus;
	double grav_earth;
	double grav_mars;
	double grav_jupiter;
	double grav_saturn;
	double grav_uranus;
	double grav_neptune;

	double ratio_mercury;
	double ratio_venus;
	double ratio_earth;
	double ratio_mars;
	double ratio_jupiter;
	double ratio_saturn;
	double ratio_uranus;
	double ratio_neptune;


	grav_mercury = newton_grav * mass_mercury / (radius_mercury * radius_mercury);
	grav_venus = newton_grav * mass_venus / (radius_venus * radius_venus);
	grav_earth = newton_grav * mass_earth / (radius_earth * radius_earth);
	grav_mars = newton_grav * mass_mars / (radius_mars * radius_mars);
	grav_jupiter = newton_grav * mass_jupiter / (radius_jupiter * radius_jupiter);
	grav_saturn = newton_grav * mass_saturn / (radius_saturn * radius_saturn);
	grav_uranus = newton_grav * mass_uranus / (radius_uranus * radius_uranus);
	grav_neptune = newton_grav * mass_neptune / (radius_neptune * radius_neptune);

	ratio_earth = 1.0;
	ratio_mercury = grav_mercury / ratio_earth;
	ratio_venus = ratio_earth / grav_venus;
	ratio_mars = ratio_earth / grav_mars;
	ratio_jupiter = ratio_earth / grav_jupiter;
	ratio_saturn = ratio_earth / grav_saturn;
	ratio_uranus = ratio_earth / grav_uranus;
	ratio_neptune = ratio_earth / grav_neptune;


	printf("%10s  %10s  %10s  %10s \n", "planet", "gravity", "g/earth g", "weight 200");
	printf("%10s  %10s  %10s  %10s \n", "------", "-------", "---------", "----------");
	printf("%10s  %10.2le  %10.3lf  %10.1lf\n", "mercury", grav_mercury, ratio_mercury, ratio_mercury * 200.0);
	printf("%10s  %10.2le  %10.3lf  %10.1lf\n", "venus", grav_venus, ratio_venus, ratio_venus * 200.0);
	printf("%10s  %10.2le  %10.3lf  %10.1lf\n", "earth", grav_earth, ratio_earth, ratio_earth * 200.0);
	printf("%10s  %10.2le  %10.3lf  %10.1lf\n", "mars", grav_mars, ratio_mars, ratio_mars * 200.0);
	printf("%10s  %10.2le  %10.3lf  %10.1lf\n", "jupiter", grav_jupiter, ratio_jupiter, ratio_jupiter * 200.0);
	printf("%10s  %10.2le  %10.3lf  %10.1lf\n", "saturn", grav_saturn, ratio_saturn, ratio_saturn * 200.0);
	printf("%10s  %10.2le  %10.3lf  %10.1lf\n", "uranus", grav_uranus, ratio_uranus, ratio_uranus * 200.0);
	printf("%10s  %10.2le  %10.3lf  %10.1lf\n", "neptune", grav_neptune, ratio_neptune, ratio_neptune * 200.0);

	return 0;
}