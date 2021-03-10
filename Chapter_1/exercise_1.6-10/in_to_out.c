#include <stdio.h>
#include <stdlib.h>

/*
 * This program takes the user input from the cmd line
 * and outputs it
 * 
 * The output modifies the input by condensing all spaces 
 * to a single space, changing tabs to \t, \'s to \\, and
 * prints out the count for newlines, spaces, and tabs
 */

int
main (void) 
{
	int c, bc, tc, nc, space_flag;
	c = bc = tc = nc = space_flag = 0;
	
	// Intro, prompting user for words
	puts("Input some chars and press Enter");

	// While we don't get a ^D (EOF), we keep going
	while ((c = getchar()) != EOF) {
		// If there was a space before and we see another space
		// then increment count and move on
		if (space_flag == 1 && c == ' ') {
			bc++;
			continue;
		// Otherwise, reset the flag for continued spaces
		} else {
			space_flag = 0;
		}
		
		//Char processing:
		if (c == '\n') {  // newline
			nc++;
			putchar(c);
		} else if (c == '\t') { // tab
			tc++;
			putchar('\\');
			putchar('t');
		} else if (c == '\\') { // slash
			putchar('\\');
			putchar('\\');
		} else if (c == ' ') { // space
			bc++;
			putchar(c);
			space_flag = 1;
		} else { putchar(c); }
	}

	// print out the counts
	printf("\nBlank count = %d\nTab count = %d\nNewLine count = %d\n", bc, tc, nc);
	return 0;
}
