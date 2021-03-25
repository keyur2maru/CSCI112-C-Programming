#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void outputheader()
{
	/*     add code to output the table header */
		/* --> between here */
	printf("%10s %15s %15s\n", "DAY", "DEPOSIT", "BALANCE");
	printf("%10s %15s %15s\n", "---", "-------", "-------");
	/* <-- and here */
}

int generatetable(double reqMoney)
{
	/*     add declarations and code to generate the table */
	/*     (based on the parameter value) */
	/*     and return the number of days required to accumulate the specified amount */
		/* --> between here */
	double deposit, balance;
	int days;

	balance = 0.00;
	deposit = 0.01;
	days = 1;

	while (balance <= reqMoney) {
		deposit *= 2.00;
		balance += deposit;
		days++;
	}

	return days;
	/* <-- and here */
}

int main(void)
{
	/*     add declarations and code to input the amount of money, */
	   /*     call the function to output the table header, */
	   /*     and call the function to generate the table, */
	   /*     and print the number of days required */
	/* --> between here */
	double reqMoney, deposit, balance;
	int days, count;

	balance = 0.00;
	deposit = 0.01;
	count = 1;
	balance += deposit;

	scanf("%lf", &reqMoney);
	outputheader();
	printf("%10.2d %15.2lf %15.2lf\n", count, deposit, balance);

	days = generatetable(reqMoney);

	while ((count != days)||(balance <= reqMoney)) {
		deposit *= 2.00;
		balance += deposit;
		count++;
		printf("%10.2d %15.2lf %15.2lf\n", count, deposit, balance);
	}
	printf("It took %d days to accumulate at least %.2lf.\n", count, reqMoney);
	/* <-- and here */

	while (1) getchar();
	return 0;
}

