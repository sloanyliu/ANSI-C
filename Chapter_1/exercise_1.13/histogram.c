#include <stdio.h>

#define VERT_PRE_SPACES 17 // spaces to print before the title
#define RANGE 51 // max length of word that can be detected

#define HORIZONTAL 1 // trigger horizontal histogram
#define VERTICAL 1 //trigger vertical histogram



int main (void) 
{
	int c; // used to iterate through user input
	int max_len; // the longest length detected
	int max_cnt; // the max count of any word length
	int flag; // used to flag multiple spaces, tabs, or newlines
	int len_inc; // used to keep track of the length of each word
	c = max_len = max_cnt = flag = len_inc = 0;

	/*
	 * array used to keep count of the frequency of each length of word
	 * 
	 * indx of word_lens ==> the word length
	 * the value stored at each indx ==> the count of that length 
	 */
	int word_lens[RANGE]; 
	
	puts("Enter some words separated by spaces -or- tabs:");
	
	// clearing the int array
	for (int h = 0; h < RANGE; h++) { 
		word_lens[h] = 0;
	}

	// loop throgh user input
	while ((c = getchar()) != EOF) {
		// flagging multiple spaces, tabs, or newlines
		if (flag == 1 && (c == ' ' || c == '\t' || c == '\n')) {
			continue; // ignore if there are multiple
		} else {
			flag = 0;
		}
		
		// a space, tab, or newline indicates a word finished
		if (c == ' ' || c == '\t' || c == '\n') {
			// checking to make sure that the input words aren't too long
			if (len_inc > (RANGE - 1)) {
				puts("Size of word TOO LARGE, please enter another word");
				len_inc = 0;
				continue;
			} else {
				word_lens[len_inc]++; // add to the count of that word length
				// update the max count
				if (max_cnt < word_lens[len_inc]) {
					max_cnt = word_lens[len_inc];
				}

				// update the max length
				if (max_len < len_inc) {
					max_len = len_inc;
				}

				len_inc = 0; // clear len_inc for next word
				flag = 1; // set flag up to indicate appearance of new word
			}
		} else {
			len_inc++; // increment length count of current word
		}
	}

	
	// if there was only one word entered, update all necessary vars
	if (max_cnt == 0 || max_len == 0) {
		word_lens[len_inc]++;
		max_cnt = 1;
		max_len = len_inc;
	}


	// PRINT Histogram
	puts("hi");	
	#if (VERTICAL)
	printf("\n");
	
	// TITLE
	for (int k = 0; k < (max_cnt/2) + VERT_PRE_SPACES; k++) {
		printf(" ");
	}
	printf("FREQUENCY\n");

	for (int j = 0; j < max_len + 1; j++) {
		if (j == (max_len + 1)/2) {
			printf("WORD LENGTH %02d:", j);
		} else {
			printf("            %02d:", j);
		}

		for (int p = 0; p < word_lens[j]; p++) {
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
	printf("          WORD LENGTH\n");

	int temp_cnt = max_cnt; // saved for use in printing each row

	// Iterate through the max_cnt (each row)
	for (int p = 0; p < max_cnt + 1; p++) {
		
		// if its the last row, print the x-axis labels (word length)
		if (p == max_cnt) {
			printf("          ");
			for (int f = 0; f < max_len + 1; f++) {
				printf(" %02d", f);
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
			if (word_lens[g] >= temp_cnt) {
				printf("  +");
			} else {
				printf("   ");
			}
		}
		temp_cnt--;
		printf("\n");

	}
	#endif
	
	return 0;
}
