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
	int c, bc, tc, nc, cc, sc, sfg;
	c = bc = tc = nc = cc = sc = sfg = 0;
	
	// Intro, prompting user for words
	puts("Input some chars and press Enter to process them.\nPress Ctrl+D when you want to exit program.");

	// While we don't get a ^D (EOF), we keep going
	while ((c = getchar()) != EOF) {
		// If there was a space before and we see another space
		// then increment count and move on
		if (sfg == 1 && c == ' ') { bc++; continue; } 
                else { sfg = 0; }
		
		//Char processing:
		if (c == '\n') { nc++; putchar(c); } 
                else if (c == '\t') { tc++; putchar('\\'); putchar('t'); } 
                else if (c == '\\') { sc++; putchar('\\'); putchar('\\'); } 
                else if (c == ' ') { bc++; putchar(c); sfg = 1; } 
                else { cc++; putchar(c); }
	}

	// print out the counts
	printf("\nBlank Count = %d\nTab Count = %d\nNewLine Count = %d\n", bc, tc, nc);
        printf("Slah Count = %d\nCharacter Count = %d\n", sc, cc);
	return 0;
}
