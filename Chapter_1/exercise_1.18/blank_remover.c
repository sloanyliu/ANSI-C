#include <stdio.h>
#include <string.h>
#define MAX 1000

int main (void) {
  
  char buf[MAX];
  int d = 0;
  puts("Enter some characters, trailing blanks and tabs will be removed.")
  for(char i = getchar(); i != EOF; i = getchar()) {
    if(i == '\n') {
      for(int k = (d-1); k >= 0; --k) {
        if(buf[k] == ' ' || buf[k] == '\t') {
          buf[k] = '\0';
		} else {
          break;
		}
	  }
	  puts(buf);
	  memset(buf, '\0', MAX);
	  d = 0;
	} else {
      // add to line
      buf[d++] = i;
	  if(d == MAX) {
        break;
	  }
	}
  }
}
