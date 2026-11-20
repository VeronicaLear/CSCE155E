/**
 * Author: Veronica Lear
 * Date: 2026-09-17
 *
 * This program takes in Command Line Input to give a monthly chart of the retirement plan that includes interest from inflation.
 */

 #include <stdlib.h>
 #include <stdio.h>

 int main(int argc, char **argv) {

    double startingBalance, monthlyContribution, rateOfReturn, rateOfInflation, currentBalance, monthlyInflation, currentInterest, totalInterest;
    int yearsUntilRetire, monthsUntilRetire;

    if(argc != 6) {
        printf("ERROR, enter the right amount of inputs.\n");
        printf("An initial starting balance, a monthly contribution amount, an average annual rate of return, an average annual rate of inflation, and a number of years until retirement\n");
        exit(1);
    }

    startingBalance = atof(argv[1]);
    currentBalance = startingBalance;

    monthlyContribution = atof(argv[2]);

    rateOfReturn = atof(argv[3]);
    rateOfInflation = atof(argv[4]);

    monthlyInflation = (((1 + rateOfReturn)/(1 + rateOfInflation)) - 1) / 12;

    yearsUntilRetire = atoi(argv[5]);
    monthsUntilRetire = yearsUntilRetire * 12;

    totalInterest = 0;



    if(rateOfReturn < 0 || rateOfReturn > 1) {
        printf("ERROR enter the rate of return and rate of inflation in the range [0,1]\n");
        exit(1);
    }
    if((rateOfInflation < 0) || (rateOfInflation > 1)) {
        printf("ERROR enter the rate of return and rate of inflation in the range [0,1]\n");
        exit(1);
    }

    if(monthlyContribution * 12 >= 18500) {
        printf("ERROR: Annual conttibution exceeds $18500\n");
        exit(1);
    }


    printf("Month    Interest     Balance\n");

    for(int currentMonth = 1; currentMonth <= monthsUntilRetire; currentMonth++) {

        currentInterest = currentBalance * monthlyInflation;

        //rounding to the nearest cent
        int interestRounding = (currentInterest * 1000);
        if((interestRounding % 10) >= 5) {
            interestRounding += 10;
        }
        interestRounding /= 10;
        currentInterest = interestRounding / 100.0;

        totalInterest += currentInterest;

        currentBalance += monthlyContribution + currentInterest;

        printf("%-5d   $%8.2f   $%8.2f\n", currentMonth, currentInterest, currentBalance);
    }

    printf("Total Interest Earned: $  %.2f\n", totalInterest);
    printf("Total Nest Egg: $ %.2f\n", currentBalance);

    return(0);
 }
