/**
 * Author: Veronica Lear
 *
 * Date: 2026/10/08
 *
 * Prototypes and documentation for a code that turns
 * RGB to CMYK and CMYK to RGB
 */

 typedef enum {
    NO_ERROR,
    NULL_ERROR,
    NEGATIVE_ERROR,
    TOO_HIGH_ERROR
 }ErrorCode;

 /**Turns RGB into CMYK using
  * r′= r / 255
  * g′= g / 255
  * b′= b / 255
  * k = 1 − max(r′,g′,b′)
  * c = (1 − r′ − k) (1 − k)
  * m = (1 − g′ − k) (1 − k)
  * y = (1 − b′ − k) (1 − k)
  */
 int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k);


 /**
  * Turns CMYK into RGB using
  * r = 255 ⋅ (1 − c) ⋅ (1 − k)
  * g = 255 ⋅ (1 − m) ⋅ (1 − k)
  * b = 255 ⋅ (1 − y) ⋅ (1 − k)
  */
 int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b);

 /**
  * Finds the maximum value of three integers
  */
 double max(double r, double g, double b);

 /**
  * Rounds to the nearest integer instead of truncating
  * also checks that it does not exceed 255
  */
 int roundToInteger(double unrounded);
