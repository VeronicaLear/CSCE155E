/**
 * Author:
 * Date:
 *
 * This programs provides basic calculator functionality
 * allowing a user to enter two operands and to compute
 * various calculated values.
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

  double a, b, result;
  int choice;

  printf("Enter operand a: ");
  scanf("%lf", &a);

  printf("Enter operand b: ");
  scanf("%lf", &b);

  printf("Enter operation:\n");
  printf("(1) Addition\n");
  printf("(2) Subtraction\n");
  printf("(3) Multiplication\n");
  printf("(4) Division\n");
  printf("(5) Minimum\n");
  printf("(6) log_a(b)\n");
  scanf("%d", &choice);

  if(choice == 1) {
    if ((a >= 0) && (b >= 0)) {
      printf("%f", a + b);
    }else {
      printf("ERROR one or more of the entered values are negative\n");
    }
  } else if(choice == 2) {
    result = a - b;
    printf("%f", result);
  } else if(choice == 3) {
    result = a * b;
    printf("%f", result);
  } else if(choice == 4) {
    if (b == 0) {
      printf("ERROR b is zero and you cannot divide by zero\n");
    } else {
      result = a / b;
      printf("%f", result);
    }
  } else if(choice == 5) {
    if (a < b) {
      printf("%f", a);
    } else {
      printf("%f", b);
    }
  } else if(choice == 6) {
    if ((a <= 0) || (b <= 0)) {
      printf("ERROR one or more values is less than or equal to zero\n");
    } else {
      if ((log(b) != 0) && (log(a) != 0)) {
        result = (log(b) / log(a));
        printf("%f", result);
      } else {
        printf("ERROR cannot divide by zero");
      }
     }
  } else {
    printf("Please input a valid operator next time");
  }

  return 0;
}
