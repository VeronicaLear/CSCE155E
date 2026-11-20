/**
 * Author: Veronica Lear
 * Date: 2026/10/29
 *
 * Protypes for functions that alter strings
 */

 #include <stdlib.h>


 /**
  * Takes a string and replaces all instances of oldChar
  * with that of of newChar
  * Makes changes to the original string
  */
 void replaceChar(char *s, char oldChar, char newChar);

 /**
  * Makes a new copy of the given string but replaces all of the
  * instances of oldChar with newChar
  */
 char * replaceCharCopy(const char *s, char oldChar, char newChar);

 /**
  * Changes the original string to remove all instances of the
  * provided character
  */
 void removeChar(char *s, char c);

 /**
  * Makes a deep copy of the given string, but takes out
  * all instances of the provided character
  */
 char * removeCharCopy(const char *s, char c);

/**
 * Makes a new array that is an array of strings, splitting
 * up the given string into n elements of the new array
 */
 char **lengthSplit(const char *s, int n);
