/**
 * Author: Veronica Lear
 * Date: 2026/11/05
 *
 * Header file for functions that read
 * and put the contents into strings
 */

 #include <stdlib.h>

 /**
  * Takes the given file, reads it and returns
  * it all in one string, preserving the endline
  * characters
  */
 char *getFileContents(const char *filePath);

 /**
  * Takes the given file, reads it and returns
  * the lines as an array of strings, each string
  * being one line that does not include the endline
  * characters
  */
 char **getFileLines(const char *filePath, int *numLines);
