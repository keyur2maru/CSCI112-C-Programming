#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	/*     add more variable declarations */
	/* --> between here */
	int first, second, index, next;
	/* <-- and here */

	int count;

	count = 20;
	/*     add code to print the first “count” Fibonacci numbers */
	/*     with the proper format */
	/* --> between here */
	first = 0, second = 1;
	for (index = 0; index < count; index++)
	{
		if (index <= 1)
			next = index;
		else
			next = first + second;
		
		printf("%d", next);
		{
			if (index != count - 1)
				printf(", ");
			else if (count != 0)
				printf(".\n");
		}
		first = second;
		second = next;
	}
	/* <-- and here */

	while (1) getchar();
	return 0;
}
