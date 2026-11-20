/**
 * Author: Veronica Lear
 * Date: 2026/09/29
 *
 * A collection of utility functions to manipualte RGB
 * values of an image
 */

/**
 * Scales the given rgb integer component (on the
 * scale [0, 255]) to a floating point number on the
 * scale [0, 1].
 *
 * Note: this function is only included to demonstrate
 * how to unit test floating point values.  See the
 * colorUtilsTester.c for more.
 */
double rgbIntToFloat(int c);

/**
 * Returns the maximum value among the three
 * given integer values.
 */
int max(int x, int y, int z);

/**
 * Returns a gray-scaled RGB value of the three
 * given RGB values using the average technique.
 *
 */
int toGrayScaleAverage(int r, int g, int b);

/**
 * Returns the minimum value among three given integers
 */
int min(int x, int y, int z);

/**
 * Uses the lightness technique to return grayscale value
 * takes in three integers
 */
int toGrayScaleLightness(int r, int g, int b);

/**
 * Rounds to the nearest integer, ending in .5 or higher
 * goes up, everything else stays at the same number
 */
int roundToInteger(double unrounded);

/**
 * Uses the formula 0.21r + 0.72g + 0.07b to calculate the gray scale
 * returns a rounded integer
 */
int toGrayScaleLuminosity(int r, int g, int b);

/**
 * Finds Sepia tone for red using r′= 0.393r + 0.769g + 0.189b
 */
int toSepiaRed(int r, int g, int b);

/**
 *Finds Sepia tone for green using r′= 0.349r + 0.686g + 0.168b
 */
int toSepiaGreen(int r, int g, int b);

/**
 * Finds Sepia tone for blue using r′= 0.2729r + 0.534g + 0.131b
 */
int toSepiaBlue(int r, int g, int b);
