/**
 * Author: Veronica Lear
 * Date: 2026/11/05
 *
 * Test cases for functions that deal
 * with protiens
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>

 #include "file_utils.h"

 int main (int argc, char ** argv) {

    char *test = getFileContents("test.txt");

    printf("%s", test);


    int numLines;
    char **stringArray = getFileLines("test.txt", &numLines);
    for(int i=0; i<numLines; i++) {
      printf("%s\n", stringArray[i]);
    }

   return 0;
 }
