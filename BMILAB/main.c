#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main(void)
{
	double height, weight, bmi;
	int bmievalcode;

	while (1)
	{
		/* --> add code to input weight and height between here */
		scanf("%lf %lf", &weight, &height);
		/* <-- and here */


		/* --> add code to calculate bmi and bmievalcode between here */
		bmi = (weight * 703.0) / (height * height);
		bmievalcode = -1;
		if (bmi < 18.5) {
			bmievalcode = 1;
		}
		else if (bmi >= 18.5 && bmi < 25.0) {
			bmievalcode = 2;
		}
		else if (bmi >= 25.0 && bmi < 30.0) {
			bmievalcode = 3;
		}
		else if (bmi >= 30.0) {
			bmievalcode = 4;
		}
		else bmievalcode = -1; {
		}
		/* <-- and here */


		/*  bmievalcode:
		 *  1 = underweight
		 *  2 = normal
		 *  3 = overweight
		 *  4 = obese
		 */


		 /* --> add code to print bmi and bmievalcode between here */
		if (bmievalcode == 1) {
			printf("bmi =%7.1lf, evaluation is underweight.\n", bmi);
		}
		else if (bmievalcode == 2) {
			printf("bmi =%7.1lf, evaluation is normal.\n", bmi);
		}
		else if (bmievalcode == 3) {
			printf("bmi =%7.1lf, evaluation is overweight.\n", bmi);
		}
		else if (bmievalcode == 4) {
			printf("bmi =%7.1lf, evaluation is obese.\n", bmi);
		}
		else {
			printf("program error!");
		}
		/* <-- and here */
	}

	while (1) getchar();
	return 0;
}


