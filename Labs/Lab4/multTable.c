/**
 * Author: Veronica Lear
 * Date: 2026/09/14
 *
 * This program generates a multiplication table
 * of the size given as a command line argument.
 */
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {

  if(argc != 2) {
    printf("Error: provide an integer\n");
    exit(1);
  }

  int n = atoi(argv[1]);
  if(n <= 0) {
    printf("empty table!\n");
    exit(0);
  }

  //header
  printf("--- ");
  for(int header=1; header<=n; header++) {
    printf("%3d ", header);
  }
  printf("\n");

  //body
  for(int row=1; row<=n; row++) {
    printf("%3d ", row);
    for(int column=1; column<=n; column++) {
      printf("%3d ", column * row);
    }
    printf("\n");
  }

  return 0;
}
