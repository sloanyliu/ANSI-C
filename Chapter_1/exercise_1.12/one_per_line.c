#include <stdio.h>

/* prints out the words of a message one per line
 * multiple spaces are counted as one space
 */

int
main (void) 
{
  int c, flag;
  c = flag = 0;

  puts("Enter some words separated by spaces -or- tabs:");
  puts("Predd Ctrl+D when you are ready to exit.");

  while ((c = getchar()) != EOF) {
    if (flag == 1 && (c == ' ' || c == '\t')) { continue; } 
    else { flag = 0; }
	  
    if (c == ' ' || c == '\t') { putchar('\n'); flag = 1; } 
    else { putchar(c); }
  }
  return 0;
}
