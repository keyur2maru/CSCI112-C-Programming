#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* only make changes at the places shown below */
/* fill in an expression in place of the comment that says "...something..." */
/* add declarations or code between comments as directed */
/* do not remove the comments in green */
/* do not remove or change anything else, including this comment */

int main(void)
{
	double dcost, dtendered;
	int icost, itendered;
	int itwenties, itens, ifives, iones, iquarters, idimes, inickels, ipennies;
	/* add any additional variables between here -> */
	int itotal;
	/* <- and here*/

	scanf("%lf", &dcost);
	scanf("%lf", &dtendered);

	icost = (int)((dcost * 100.0) +0.000001);
	itendered = (int)((dtendered * 100.0) +0.000001);

	/* add code to calculate itwenties, itens, etc., between here -> */
	itotal = itendered - icost;
	itwenties = itotal / 2000;
	itotal = itotal % 2000;
	itens = itotal / 1000;
	itotal = itotal % 1000;
	ifives = itotal / 500;
	itotal = itotal % 500;
	iones = itotal / 100;
	itotal = itotal % 100;
	iquarters = itotal / 25;
	itotal = itotal % 25;
	idimes = itotal / 10;
	itotal = itotal % 10;
	inickels = itotal / 5;
	itotal = itotal % 5;
	ipennies = itotal;
	/* <- and here */

	printf("%2d twenties\n", itwenties);
	printf("%2d tens\n", itens);
	printf("%2d fives\n", ifives);
	printf("%2d ones\n", iones);
	printf("%2d quarters\n", iquarters);
	printf("%2d dimes\n", idimes);
	printf("%2d nickels\n", inickels);
	printf("%2d pennies\n", ipennies);

	while (1) getchar();
	return 0;
}

