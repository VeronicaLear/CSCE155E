
/**
 * Author: Veronica Lear
 *
 * This program prompts the user to enter the
 * base and the height of a triangle and computes
 * its area using the well-known formula
 *  1/2 * base * height
 *
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

  double area, base, height;

  if (argc != 3) {
    printf("You have to enter as CLI as base and then height");
    return(1);
  }

  base = atof(argv[1]);

  height = atof(argv[2]);

  area = 0.5 * base * height;

  printf("The area is %f square units.\n", area);

  return 0;
}
