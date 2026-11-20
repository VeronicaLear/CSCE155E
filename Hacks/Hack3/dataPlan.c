/**
 * Author: Veronica Lear
 *
 * Date: 2026/09/10
 *
 * This program looks at how much GB someone has spent
 * and helps them prevent from going over on their plan.
 * It does this by taking averages and comparing the
 * details that are entered over Command Line.
 * Assuming that there are 30 days in a month.
 */

 #include <stdlib.h>
 #include <stdio.h>

 int main (int arg, char **argv) {
    int daysLeft, daysPassed;
    double expectedAverage, actualAverage, gbPlan, gbUsed, gbLeft, remainingAverage;

    if (arg != 4) {
        printf("ERROR: Enter GB in plan, Current day of the month, and total number of GB used so far in the command line.\n");
        return 1;
    }

    //readability
    gbPlan = atof(argv[1]);
    daysPassed = atoi(argv[2]);
    gbUsed = atof(argv[3]);

    if ((daysPassed <= 0) || (daysPassed > 30)) {
        printf("ERROR: Please enter a valid day of the month 1-30.\n");
        return 1;
    }
    if (gbUsed < 0) {
        printf("ERROR: You could not have used negative GB.\n");
        return 1;
    }

    gbLeft = gbPlan - gbUsed;
    daysLeft = 30 - daysPassed;
    printf("%d days used, %d days remaining.\n", daysPassed, daysLeft);

    //checking for zeros in division
    if (gbUsed == 0) {
        actualAverage = 0.0;
    } else {
        actualAverage = gbUsed / daysPassed;
    }
    printf("Average daily use: %.2f GB/day.\n\n", actualAverage);

    if (gbPlan == 0) {
        expectedAverage = 0.0;
    } else {
        expectedAverage = gbPlan / 30;
    }

    if ((gbLeft == 0) || (daysLeft == 0)) {
        remainingAverage = 0.0;
    } else {
        remainingAverage = gbLeft / daysLeft;
    }


    if (gbUsed >= gbPlan){
        printf("You have already met your limit for this month.  Looks like you're getting some overage charges...\n");
    } else if (actualAverage > expectedAverage) {
        printf("You are EXCEEDING your average daily use (%.2f GB/day).\n", expectedAverage);

        double expectedUsedOver = ((actualAverage * daysLeft) + gbUsed) - gbPlan;

        printf("Continuing this high usage, you'll exceed your data plan by %.2f GB.\n\n", expectedUsedOver);
        printf("To stay below your data plan, use no more than %.2f GB/day.\n", (remainingAverage));
    } else {
        printf("You are at or below your average daily use (%.2f GB/day).\n", expectedAverage);
        printf("You can use up to %.2f GB/day and stay below your data plan limit\n", (remainingAverage));
    }

    return 0;
 }
