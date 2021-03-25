#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main(void)
{
	int x1, x2, x3, x4;
	int xlarge, xsmall, ixlarge, ixsmall;

	while (1)
	{
		printf("enter x1, x2, x3, x4:\n");
		scanf("%d%d%d%d", &x1, &x2, &x3, &x4);

		/*     add code to calculate xlarge, xsmall,
		 *     ixlarge, ixsmall
		 * --> between here */
		xlarge = (x1 > x2 && x1 > x3 && x1 > x4) ? x1 : ((x2 > x3 && x2 > x4) ? x2 : (x3 > x4 ? x3 : x4));
		xsmall = (x1 < x2 && x1 < x3 && x1 < x4) ? x1 : ((x2 < x3 && x2 < x4) ? x2 : (x3 < x4 ? x3 : x4));
		ixlarge = (x1 > x2 && x1 > x3 && x1 > x4) ? 1 : ((x2 > x3 && x2 > x4) ? 2 : (x3 > x4 ? 3 : 4));
		ixsmall = (x1 < x2 && x1 < x3 && x1 < x4) ? 1 : ((x2 < x3 && x2 < x4) ? 2 : (x3 < x4 ? 3 : 4));
		/* <-- and here */

		printf("largest = %4d at position %d, ", xlarge, ixlarge);
		printf("smallest = %4d at position %d\n", xsmall, ixsmall);
	}

	while (1) getchar();
	return 0;
}

