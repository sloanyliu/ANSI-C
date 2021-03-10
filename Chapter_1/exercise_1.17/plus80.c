#include <stdio.h>

#define MAX 1000


//
// This program takes in a user input and outputs it if the input is
// greater than 80 chars long
//


int get_line (char line[], int lim);


int
main (void) 
{
	char myLine[MAX];
	int len;

	puts("Enter some characters, if the length is longer than 80 it will be echoed.");
	
	while ((len = get_line(myLine, MAX)) > 0) {
		if (len > 80) {
			printf("%s", myLine);
		}
	}

	return 0;

}


int 
get_line (char line[], int lim) 
{
	int c, i;

	//for loop exits on three conditions
	//1) iterator hits getline()'s limit
	//2) we recieve an EOF char
	//3) we recieve a newline char
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}

	// if its a newline, add it to the string
	if (c == '\n') { 
		line[i] = c;
		++i; 
	} else if (c == EOF) {
		return 0;
	}

	line[i] = '\0';
	return i;
}


