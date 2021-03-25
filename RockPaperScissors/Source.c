#include <stdio.h> 
#include<string.h> 

#define MAX 10
int main()
{

	char input[2][MAX];
	int isrock[2], ispaper[2], isscissors[2];
	int i;

	for (i = 0; i < 2; i++) {
		fgets(input[i], MAX, stdin);
		isrock[i] = (strncmp(input[i], "rock", 4) == 0);
		ispaper[i] = (strncmp(input[i], "paper", 5) == 0);
		isscissors[i] = (strncmp(input[i], "scissors", 8) == 0);

		if (!isrock[i] && !ispaper[i] && !isscissors[i]) { printf("invalid input!"); }
	}
	char x[100] = ("rock crushes scissors");
	char y[100] = ("scissors cuts paper");
	char z[100] = ("paper covers rock");

	/*Player 1 win check*/
	if (isrock[0] && isscissors[1])
		printf("player 1 wins, %s", x);
	if (isscissors[0] && ispaper[1])
		printf("player 1 wins, %s", y);
	if (ispaper[0] && isrock[1])
		printf("player 1 wins, %s", z);

	/*Player 2 win check*/
	if (isrock[1] && isscissors[0])
		printf("player 2 wins, %s", x);
	if (isscissors[1] && ispaper[0])
		printf("player 2 wins, %s", y);
	if (ispaper[1] && isrock[0])
		printf("player 2 wins, %s", z);

	if (isrock[0] && isrock[1] || isscissors[0] && isscissors[1] || ispaper[0] && ispaper[1]) printf("draw");


}


