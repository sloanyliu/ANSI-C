#include <stdio.h>
#include <ctype.h>

#define VERT_PRE_SPACES 17 // spaces to print before the title
#define RANGE 30 // max length of word that can be detected

#define HORIZONTAL 1 // trigger horizontal histogram
#define VERTICAL 1 //trigger vertical histogram



int main (void) 
{
	int c; // used to iterate through user input
	int max_len = 26; // the longest length detected
	int max_cnt; // the max count of any char
	int flag; // used to flag multiple spaces, tabs, or newlines
	int len_inc; // used to keep track of the length of each word
	c  = max_cnt = flag = len_inc = 0;

	/*
	 * array used to keep count of the frequency of each length of word
	 * 
	 * indx of word_lens ==> the word length
	 * the value stored at each indx ==> the count of that length 
	 */
	int chars[RANGE];
	
	puts("Enter some words separated by spaces -or- tabs:");
	
	// clearing the int array
	for (int h = 0; h < RANGE; h++) { 
		chars[h] = 0;
	}

	/**********
	Change to be made:
	When looping char by char through the user input, we count the frequency
	of the chars now, and print that as a histogram
	--> need to create array with size == # of chars possible
	    -> char ASCII - 'A' could be index
		-> value at index is frequency
		    
	**********/
	// loop throgh user input
	while ((c = getchar()) != EOF) {
		c = tolower(c); // converting to lower case
		// flagging multiple spaces, tabs, or newlines
		if (flag == 1 && (c == ' ' || c == '\t' || c == '\n')) {
			continue; // ignore if there are multiple
		} else {
			flag = 0;
		}
		
		// a space, tab, or newline indicates a word finished
		if (c == ' ' || c == '\t' || c == '\n') {
			flag = 1; // set flag up to indicate appearance of new word
		} else {
			if (isalpha(c)) {
				chars[c - 'a']++; // increment char count at index
			}
		}
	}

	for (int i = 0; i < RANGE; i++) {
		if (max_cnt < chars[i]) {
			max_cnt = chars[i];
		}
	}


	// PRINT Histogram	
	#if (VERTICAL)
	printf("\n");
	
	// TITLE
	for (int k = 0; k < (max_cnt/2) + VERT_PRE_SPACES; k++) {
		printf(" ");
	}
	printf("FREQUENCY\n");

	for (int j = 0; j < max_len; j++) {
		if (j == (max_len/2)) {
			printf("CHARS %c:", j + 'a');
		} else {
			printf("      %c:", j + 'a');
		}

		for (int p = 0; p < chars[j]; p++) {
			printf(" +");
		}
		printf("\n");
	}
	#endif

	#if (HORIZONTAL)
	printf("\n");

	for (int n = 0; n < (((max_len - 1) * 3)/2); n++) {
		printf(" ");
	}
	printf("CHARS  \n");

	int temp_cnt = max_cnt; // saved for use in printing each row

	// Iterate through the max_cnt (each row)
	for (int p = 0; p < max_cnt + 1; p++) {
		
		// if its the last row, print the x-axis labels (word length)
		if (p == max_cnt) {
			printf("          ");
			for (int f = 0; f < max_len; f++) {
				printf(" %c", f + 'a');
			}
			printf("\n");
			break;
		} else if (p == (max_cnt / 2)) {
			printf("FREQUENCY ");
		} else {
			printf("          ");
		}
		
		// Iterate through max_len + 1 to print (each column on) this row
		for (int g = 0; g < max_len + 1; g++) {
			// ADD A Y AXIS
			if (chars[g] >= temp_cnt) {
				printf(" +");
			} else {
				printf("  ");
			}
		}
		temp_cnt--;
		printf("\n");

	}
	#endif
	
	return 0;
}
