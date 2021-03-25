#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

void getCode(char codefile[]);
void getMessage(int msgfile[]);
void sortMessage(int msgfile[]);
void decodeMessage(char codefile[], int msgfile[]);

FILE* fpIn;

#define codeSize 53
#define msgSize 26

int main(void)
{
	char codefile[codeSize];
	int msgfile[msgSize];

	getCode(codefile);
	getMessage(msgfile);
	sortMessage(msgfile);
	decodeMessage(codefile, msgfile);

	fclose(fpIn);
	return 0;
}

void getCode(char codefile[])
{
	fpIn = fopen("codefile.txt", "r");

	if (fpIn == NULL)
	{
		printf("could not open codefile.txt\n");
		exit(1);
	}

	while (!feof(fpIn)) {
		fgets(codefile, codeSize, fpIn);
	}
}

void getMessage(int msgfile[]) {
	int i;

	fpIn = fopen("msgfile.txt", "r");

	if (fpIn == NULL)
	{
		printf("could not open msgfile.txt\n");
		exit(1);
	}

	for (i = 0; i < msgSize; i++) {
		fscanf(fpIn, "%d\n", &msgfile[i]);
	}
}

void sortMessage(int msgfile[]) {
	int i, j, temp;

	for (i = 1; i < msgSize; i++) {
		temp = msgfile[i];
		j = i - 1;
		while (j >= 0 && temp < msgfile[j])
		{
			msgfile[j + 1] = msgfile[j];
			j = j - 1;
		}
		msgfile[j + 1] = temp;
	}
}

void decodeMessage(char codefile[], int msgfile[]) {
	int loop;

	for (loop = 0; loop < msgSize; loop++)
		printf("%c", codefile[msgfile[loop] % 100]);
}