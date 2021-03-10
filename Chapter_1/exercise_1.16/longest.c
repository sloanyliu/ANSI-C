#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int _getline(char* arr, int max);

int _getline(char* arr, int max) {
  char c = 0;
  int len = 0;
  for(int i = 0; i < max-1; ++i) { // iterating through MAX
	c = getchar(); // get a character
	if(c == '\n') { // check if need to return
      break;
	} else if(c == EOF) { // END of FILE
	  if(len == 0) {
	    return -1;
	  } else {
	    return (-1 * len);
      }
	} else { // get char as part of line, increase len
      arr[i] = c;
	  ++len;
	}
  }
  return len;
}



int main(void)
{
  char buf[MAXLINE];
  char longest[MAXLINE];
  int flag = 0; 
  int max_len = 0;
  int k = 0;
  puts("Enter some lines, the longest will be printed:");
  for(k = _getline(buf, MAXLINE); k >= 0; k = _getline(buf, MAXLINE)) {
	if(flag == 0) {
      max_len = k;
	  memset(longest, '\0', MAXLINE);
	  memcpy(longest, buf, k);
	  flag = 1;
	} else {
	  if(k > max_len) {
        max_len = k;
		memset(longest, '\0', MAXLINE);
        memcpy(longest, buf, k);
	  }
	}
	memset(buf, '\0', MAXLINE);
  }

  if((-1 * k) > max_len) {
    max_len = k * -1;
	memset(longest, '\0', MAXLINE);
	memcpy(longest, buf, sizeof(buf));
  }

  printf("Line is: %s\nLength is: %d\n", longest, max_len);
  return 0;
}
