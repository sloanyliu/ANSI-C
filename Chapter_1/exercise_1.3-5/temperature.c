#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

int
main (void)
{
	printf("Celcius   Farenheit\n");
	for (int i = LOWER; i <= UPPER; i += STEP) {
		printf("%3d       %4.3f\n", i, (float) (5 * (i - 32))/9);
	}
	for (int i = (UPPER - 20); i >= LOWER; i -= STEP) {
		printf("%3d       %4.3f\n", i, (float) (5 * (i - 32))/9);
	}
	return 0;
}

