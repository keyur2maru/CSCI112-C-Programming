#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void outputHeaders(void);
void initialBalance(double amount, double* balance, double* service, double* openBalance);
void deposit(double amount, double* balance, double* service, int* numDeposit, double* amtDeposit);
void check(double amount, double* balance, double* service, int* numCheck, double* amtCheck);
void outputSummary(int numDeposit, double amtDeposit, int numCheck, double amtCheck, double openBalance, double service, double closeBalance);

FILE* fpIn;
FILE* fpOut;

// Main function copied from the textbook pg 232
int main(void)
{
	char code;
	double amount, service, balance, amtCheck, amtDeposit, openBalance, closeBalance;
	int numCheck, numDeposit;

	if (!(fpIn = fopen("account.txt", "r")))
	{
		printf("account.txt could not be opened for input.");
		exit(1);
	}
	if (!(fpOut = fopen("csis.txt", "w")))
	{
		printf("csis.text could not be opened for output");
		exit(1);
	}

	amount = 0.0;
	service = 0.0;
	balance = 0.0;
	amtCheck = 0.0;
	amtDeposit = 0.0;
	openBalance = 0.0;
	closeBalance = 0.0;
	numCheck = 0;
	numDeposit = 0;

	outputHeaders();

	while (!feof(fpIn))
	{
		fscanf(fpIn, "%c %lf\n", &code, &amount);
		if (code == 'I')
		{
			initialBalance(amount, &balance, &service, &openBalance);
		}
		else if (code == 'D')
		{
			deposit(amount, &balance, &service, &numDeposit, &amtDeposit);
		}
		else if (code == 'C')
		{
			check(amount, &balance, &service, &numCheck, &amtCheck);
		}
	}

	closeBalance = balance - service;
	outputSummary(numDeposit, amtDeposit, numCheck, amtCheck, openBalance, service, closeBalance);
	fclose(fpIn);
	fclose(fpOut);
	while (1) getchar();
	return 0;
}

//Function for printing and formatting the header
void outputHeaders(void)
{
	printf("%11s%20s%11s%16s\n", "TRANSACTION", "DEPOSIT", "CHECK", "BALANCE");
	fprintf(fpOut, "%11s%20s%11s%16s\n", "TRANSACTION", "DEPOSIT", "CHECK", "BALANCE");
	printf("%11s%20s%11s%16s\n", "-----------", "-------", "-----", "-------");
	fprintf(fpOut, "%11s%20s%11s%16s\n", "-----------", "-------", "-----", "-------");
}

//Function for printing, formatting and account of service fees
void initialBalance(double amount, double* balance, double* service, double* openBalance)
{
	*service = (double)3.00;
	*balance = amount;
	*openBalance = amount;
	printf("Initial Balance%43.2lf\n", *balance);
	fprintf(fpOut, "Initial Balance%43.2lf\n", *balance);
}

//Function for printing and formatting deposits
void deposit(double amount, double* balance, double* service, int* numDeposit, double* amtDeposit)
{
	*service += (double)0.03;
	*balance += amount;
	*amtDeposit += amount;
	(*numDeposit)++;
	printf("%s%24.2lf%27.2lf\n", "Deposit", amount, *balance);
	fprintf(fpOut, "%s%24.2lf%27.2lf\n", "Deposit", amount, *balance);
}

//Function for priting and formatting checks
void check(double amount, double* balance, double* service, int* numCheck, double* amtCheck)
{
	//Checks for overdraft and inserts fees if required
	if ((*balance - amount) > 0)
	{
		*balance -= amount;
	}
	else if ((*balance - amount) < 0)
	{
		*service += (double) 5.00;
		*balance -= amount;
	}
	*service += (double)0.06;
	*amtCheck += amount;
	(*numCheck)++;
	printf("%s%37.2lf%16.2lf\n", "Check", amount, *balance);
	fprintf(fpOut, "%s%37.2lf%16.2lf\n", "Check", amount, *balance);
}

//Function for printing and formatting the output in console window and csis.txt output file
void outputSummary(int numDeposit, double amtDeposit, int numCheck, double amtCheck, double openBalance, double service, double closeBalance)
{

	printf("\n");
	fprintf(fpOut, "\n");
	printf("\n");
	fprintf(fpOut, "\n");
	printf("Total number deposits:%9d\n", numDeposit);
	fprintf(fpOut, "Total number deposits:%9d\n", numDeposit);
	printf("Total amount deposits:%9.2lf\n", amtDeposit);
	fprintf(fpOut, "Total amount deposits:%9.2lf\n", amtDeposit);
	printf("  Total number checks:%9d\n", numCheck);
	fprintf(fpOut, "  Total number checks:%9d\n", numCheck);
	printf("  Total amount checks:%9.2lf\n", amtCheck);
	fprintf(fpOut, "  Total amount checks:%9.2lf\n", amtCheck);
	printf("\n");
	fprintf(fpOut, "\n");
	printf("      Opening balance:%9.2lf\n", openBalance);
	fprintf(fpOut, "      Opening balance:%9.2lf\n", openBalance);
	printf(" Total service charge:%9.2lf\n", service);
	fprintf(fpOut, " Total service charge:%9.2lf\n", service);
	printf("      Closing balance:%9.2lf\n", closeBalance);
	fprintf(fpOut, "      Closing balance:%9.2lf\n", closeBalance);
}