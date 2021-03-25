#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

FILE* fpIn;

void processFile(char inputFile[]);
void cipher(char inputFile[], int* shift);
void outputCode(char inputFile[]);


int main(void) {
	int shift = 0;
	char inputFile[1000];

	if (!(fpIn = fopen("congress.txt", "r"))) {
		printf("congress.txt could not be opened for input.");
		exit(1);
	}
	processFile(inputFile);
	cipher(inputFile, &shift);
	outputCode(inputFile);

	fclose(fpIn);
	return 0;
}

void processFile(char inputFile[]) {
	char c = fgetc(fpIn);
	int i;

	for (i = 0; c != EOF; c = fgetc(fpIn)) {
		if (isalpha(c)) {
			inputFile[i] = toupper(c);
			i++;
		}
	}
	inputFile[i] = '\0';
}

void cipher(char inputFile[], int* shift) {
	int i = 0;
	scanf("%d", shift);

	while (inputFile[i]) {
		inputFile[i] += *shift;
		if (!isupper(inputFile[i])) {
			inputFile[i] = inputFile[i] - 'Z' + 'A' - 1;
		}
		i++;
	}
}

void outputCode(char inputFile[]) {
	for (int i = 0; inputFile[i] != 0; i++) {
		if (i % 50 == 0 && i != 0) {
			putchar('\n');
		}
		else if (i % 5 == 0 && i != 0) {
			putchar(' ');
		}
		putchar(inputFile[i]);
	}
}