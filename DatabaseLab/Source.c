#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdarg.h>

int main(void);
double average(int num, ...);

int main(void) {
	double a = 2.0, b = 4.0, c = 6.0, d = 8.0;
	printf("%5.1lf\n", average(2, a, b));
	printf("%5.1lf\n", average(3, a, b, c));
	printf("%5.1lf\n", average(4, a, b, c, d));
	return 0;
}
double average(int num, ...) {
	int i;
	double total = 0.0;
	va_list ap;
	va_start(ap, num);
	for (i = 1; i <= num; i++) {
		total += va_arg(ap, double);
	}
	va_end(ap);
	return total / num;
}