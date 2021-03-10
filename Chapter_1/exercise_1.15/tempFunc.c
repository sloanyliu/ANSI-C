#include <stdio.h>

#define UPPER 300
#define LOWER 0 
#define STEP 20

float cel_to_far (int cel);

float cel_to_far (int cel)
{
	return (float) ((5 * (cel - 32)) / 9);
}

int main (void)
{
	printf("Celcius   Farenheit\n");
	for (int i = LOWER; i <= UPPER; i += STEP) {
		printf("%3d       %4.3f\n", i, cel_to_far(i));
	}
	for (int i = (UPPER - 20); i >= LOWER; i -= STEP) {
		printf("%3d       %4.3f\n", i, cel_to_far(i));
	}
	return 0;
}
