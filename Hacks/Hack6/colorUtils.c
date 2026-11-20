/**
 * Author: Veronica Lear
 *
 * Date: 2026/10/08
 *
 * Definitions and functions for a code that turns
 * RGB to CMYK and CMYK to RGB
 */

 #include <stdlib.h>

 #include "colorUtils.h"

 int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k) {
    if(c == NULL || m == NULL || y == NULL || k == NULL) {
        return NULL_ERROR;
    } else if(r < 0 || g < 0 || b < 0) {
        return NEGATIVE_ERROR;
    } else if(r > 255 || g > 255 || b > 255) {
        return TOO_HIGH_ERROR;
    }

    double dividedR, dividedG, dividedB;
    if(r == 0){
        dividedR = 0;
    } else {
        dividedR = r / 255.0;
    }
    if(g == 0) {
        dividedG = 0;
    } else {
        dividedG = g / 255.0;
    }
    if(b == 0) {
        dividedB = 0;
    } else {
        dividedB = b / 255.0;
    }

    *k = 1 - max(dividedR, dividedG, dividedB);

    if(*k == 1) {
        *c = 0.0;
        *m = 0.0;
        *y = 0.0;
    } else {
        *c = (1 - dividedR - *k) / (1 - *k);
        *m = (1 - dividedG - *k) / (1 - *k);
        *y = (1 - dividedB - *k) / (1 - *k);
    }


    return NO_ERROR;
 }

 int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b){
    if(r == NULL || g == NULL || b == NULL) {
        return NULL_ERROR;
    } else if(c < 0 || m < 0 || y < 0 || k < 0) {
        return NEGATIVE_ERROR;
    } else if(c > 1 || m > 1 || y > 1 || k > 1) {
        return TOO_HIGH_ERROR;
    }

    *r = roundToInteger(255 * (1 - c) * (1 - k));
    *g = roundToInteger(255 * (1 - m) * (1 - k));
    *b = roundToInteger(255 * (1 - y) * (1 - k));


    return 0;
 }


 double max(double r, double g, double b){
    return (r > g) ? ((r > b) ? r : b) : ((g > b) ? g : b);
 }


 int roundToInteger(double unrounded) {
    int unroundedInt = unrounded * 10;
    int rounded;
    if((unroundedInt % 10) >= 5) {
        rounded = (int)unroundedInt / 10 + 1;
    } else{
        rounded = (int)unroundedInt / 10;
    }
    if(rounded > 255) {
        rounded = 255;
    }
    return rounded;
 }
