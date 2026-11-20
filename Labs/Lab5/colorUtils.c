/**
 * Author: Veronica Lear
 * Date: 2026/09/29
 *
 * Functions that are defined to turn images to grayscale or sepia
 * also finds things like minimum and maximum
 */

#include "colorUtils.h"

double rgbIntToFloat(int c) {
  return (c / 255.0);
}

int max(int x, int y, int z) {
  int m = x > y ? x : y;
  m = m > z ? m : z;
  return m;
}

int toGrayScaleAverage(int r, int g, int b) {
  double unroundedAverage = (r + g + b) / 3.0; //factors in multiplying by ten for rounding
  int roundedAverage = roundToInteger(unroundedAverage);
  return roundedAverage;
}

int min(int x, int y, int z) {
  int min = x < y ? x : y;
  min = min < z ? min : z;
  return min;
}

int roundToInteger(double unrounded) {
  int unroundedInt = unrounded * 10;
  int rounded;
  if ((unroundedInt % 10) >= 5) {
    rounded = (int)unroundedInt / 10 + 1;
  } else {
    rounded = (int)unroundedInt / 10;
  }
  if(rounded > 255) {
    rounded = 255;
  }
  return rounded;
}

int toGrayScaleLightness(int r, int g, int b) {
  double unroundedGrayScale = (max(r, g, b) + min(r, g, b)) / 2.0;
  return roundToInteger(unroundedGrayScale);
}

int toGrayScaleLuminosity(int r, int g, int b) {
  double unroundedLuminosity = (0.21 * r) + (0.72 * g) + (0.07 * b);
  return roundToInteger(unroundedLuminosity);
}

int toSepiaRed(int r, int g, int b) {
  double sepiaRedUnrounded = (0.393 * r) + (0.769 * g) + (0.189 * b);
  return roundToInteger(sepiaRedUnrounded);
}

int toSepiaGreen(int r, int g, int b) {
  double sepiaGreenUnrounded = (0.349 * r) + (0.686 * g) + (0.168 * b);
  return roundToInteger(sepiaGreenUnrounded);
}

int toSepiaBlue(int r, int g, int b) {
  double sepiaBlueUnrounded = (0.272 * r) + (0.534 * g) + (0.131 * b);
  return roundToInteger(sepiaBlueUnrounded);
}


