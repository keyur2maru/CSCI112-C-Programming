#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void print_array(int score[], int count); //Printing the array
void insertionSort(int score[], int count); //Sort using insertion sort
void frequencyTable(int score[], int count); //Calculates the frequency of the given input
void passingScores(int score[], int count); //Calculates the number of passing/failing students scores
double mean(int score[], int count); //Calculates the average score of the class
int mode(int score[], int count); //Prints the score with most frequency
double medianScore(int score[], int count);  //Checks if the score is even/odd. Then calculates the median accordingly.


#define SIZE 1000 //Defines siz of the array


int main(void) {
	int i = 0; //counter variable initialized 
	int count = 0; //the number of scores(useful entries)
	int static score[SIZE]; //declaration of score array with size defined above.

	printf("Enter array:\n");
	while (i < SIZE) { 
		scanf("%d", &score[i]);
		if (score[i] == -1) {
			break;
		}
		count++;
		i++;
	}

	printf("part a\n");
	print_array(score, count); //passing the score array and the total number of scores; likewiae for the below functions
	insertionSort(score, count);
	printf("\npart b\n");
	print_array(score, count);
	printf("\npart c\n");
	printf("%s %10s\n", "score", "frequency");
	printf("%s %10s\n", "-----", "---------");
	frequencyTable(score, count);
	printf("\npart d\n");
	passingScores(score, count);
	printf("\npart e\n");
	mean(score, count);
	printf("\npart f\n");
	mode(score, count);
	printf("\npart g\n");
	medianScore(score, count);
}

void print_array(int score[], int count) {
	int column = 0;
	int i;
	for (i = 0; i < count; i++) {
			printf("%4d", score[i]);
			column++;
			if (column == 5) {
				printf("\n");
				column = 0;
			}
	}
	printf("\n");
}

void insertionSort(int score[], int count) {
	int i, j, temp;

	for (i = 1; i < count; i++) {
		temp = score[i];
		j = i - 1;
		while (j >= 0 && temp < score[j])
		{
			score[j + 1] = score[j];
			j = j - 1;
		}
		score[j + 1] = temp;
	}


}
/*
void frequencyTable(int score[], int size) {
	int index = size - 1;
	while (index >= 0) {
		int currentScore = score[index];
		int count = 1;
		
		while (index - count >= 0 // stop when you see the end of the array 
				&&
				score[index - count] == currentScore ) // stop when you see a different score 
			{
				count++;
			}
		
		printf("%4d%8d\n", currentScore, count);
		index -= count;
	}
}
*/

void frequencyTable(int score[], int size) {

	int i, j; //counter for the score array
	int currentscore, count;
	int frequency[30];

	for (i = 0; i < size; i++) {
		currentscore = score[i];
		count = 1;
		for (j = i + 1; j < size; j++) {
			frequency[j] = 0;
			if (score[j] == currentscore)
			{
				count++;
				frequency[j] = 1;
			}
		}
		if (i==0 || frequency[i]==0)
			printf("%4d%8d\n", currentscore, count);
	}

	print_array(frequency, 30);
}




void passingScores(int score[], int count) {
	int i;
	int passing = 0;
	int failing = 0;

	for (i = 0; i < count; i++)
	{

		if (score[i] >= 60)
			passing++;
		else
			failing++;
	}


	printf("Passing:%6.1lf%%\n", 100 * (double)passing / count);
	printf("Failing:%6.1lf%%\n", 100 * (double)failing / count);
}

double mean(int score[], int count) {

	int i, sum = 0;
	double mean = 0;

	for (i = 0; i < count; i++) {
		if (score[i] != 0)
		{
			sum += score[i];
		}
	}
	mean = (double)sum / (double)count;
	printf("Mean:%9.1lf\n", mean);
	return 0;
}


int mode(int score[], int size) {
	int index = 0;
	int modeGrade = 0, modeCount = 0;
	while (index < size) {
		int currentScore = score[index];
		int count = 1;
		while (index + count < size /* stop when you see the end of the array */
			&&
			score[index + count] == currentScore /* stop when you see a different score */
			) {
			count++;
		}
		if (count > modeCount) {
			modeGrade = currentScore;
			modeCount = count;
		}
		index += count;
	
	}
	printf("Mode:%7d\n", modeGrade);
	return 0;

}



double medianScore(int score[], int count) {
	double median = 0;

	if (count % 2 == 0) {
		median = ((double)((score[count / 2] + (double)score[count / 2 - 1])) / 2);
	}
	else {
		median = (double)(score[count / 2]);
	}

	printf("Median:%7.1lf\n", median);
	return 0;
}
