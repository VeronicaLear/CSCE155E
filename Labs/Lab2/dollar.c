/***
 * Veronica Lear
 *
 * Date: 2026/09/01
 *
 * This program converts US Dollars to British Pounds
 * and Japanese (JPY) and takes a 10% fee
 */

 #include <stdlib.h>
 #include <stdio.h>

 int main(int argc, char **argv) {
    double usDollars, britishPound, fee;
    int JPY;
    const double poundPerDollar = 0.79;
    const double JPYPerDollar = 127.65;

    printf("Please input the total amount of US Dollars: ");
    scanf("%lf", &usDollars);

    //taking the fee out
    fee = usDollars * 0.1;
    usDollars -= fee;

    //converting half to pounds and half to JPY
    britishPound = (usDollars / 2) * poundPerDollar;
    JPY = (usDollars / 2) * JPYPerDollar;

    printf("Fee (10%%): $%.2f\n", fee);
    printf("You get:\n");
    printf("%.2f GBP\n", britishPound);
    printf("%d JPY\n", JPY);

    return 0;
 }
