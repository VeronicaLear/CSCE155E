/**
 * Author: Veronica Lear
 * Date: 2026/10/15
 *
 * Prototypes and documentation for operations on arrays
 */

 #include <stdlib.h>

 /**
  * Looks at a given array to see if the given x is within that array
  * Returns true if it is and false otherwise
  */
 int contains(const int *arr, int size, int x);

 /**
  * Looks at a given array to see if the value x is within the
  * indexes i and j
  * Returns true if it is and false otherwise
  */
 int containsWithin(const int *arr, int size, int x, int i, int j);

 /**
  * Creates a new deep copy of the given array that is the size of the new size
  * If it is smaller than the original, only the first part of the original array will be copied
  * If it is larger, than it will get padded with zeros at the end
  */
 int * paddedCopy(const int *arr, int oldSize, int newSize);

 /**
  * Takes an array and reverses the order of the elements in it
  */
  void reverse(int *arr, int size);

  /**
  * Creates a duplicate copy of the array, but in reverse order
  */
  int * reverseCopy(const int *arr, int size);
