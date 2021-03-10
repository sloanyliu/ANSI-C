#include <stdio.h>

/*
 * 
 *
 *
 */

int
main (void) 
{
	int c, flag;
	c = flag = 0;

	puts("Enter some words separated by spaces -or- tabs:");

	while ((c = getchar()) != EOF) {
		if (flag == 1 && (c == ' ' || c == '\t')) {
			continue;
		} else {
			flag = 0;
		}

		if (c == ' ' || c == '\t') {
			putchar('\n');
			flag = 1;
		} else {
			putchar(c);
		}
	}
	
	return 0;
}
