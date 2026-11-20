/***
 * Author: Veronica Lear
 *
 * Date: 2026/09/01
 *
 * This program calculates the air distance using the formula:
 * d=arccos(sin⁡(φ1)sin⁡(φ2)+cos(φ1)cos⁡(φ2)cos⁡(Δ))⋅R
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char **argv) {

    const double R = 6371;
    double latitudeA, latitudeB, longitudeA, longitudeB, deltaLongitude, distance;

    //entering the important values for the calculations
    printf("Enter the Latitude for location A: ");
    scanf("%lf", &latitudeA);

    printf("Enter the Longitude for location A: ");
    scanf("%lf", &longitudeA);

    printf("Enter the Latitude for location B: ");
    scanf("%lf", &latitudeB);

    printf("Enter the Longitude for location B: ");
    scanf("%lf", &longitudeB);

    //printing original and final destinations
    printf("Location Distance\n");
    printf("========================\n");
    printf("Origin:      (%lf,%lf)\n", latitudeA, longitudeA);
    printf("Destination: (%lf,%lf)\n", latitudeB, longitudeB);

    //converting to radians
    latitudeA = latitudeA / 180 * M_PI;
    latitudeB = latitudeB / 180 * M_PI;
    longitudeA = longitudeA / 180 * M_PI;
    longitudeB = longitudeB / 180 * M_PI;

    //evaluating the equation
    deltaLongitude = longitudeA - longitudeB;
    distance = acos(sin(latitudeA) * sin(latitudeB) + cos(latitudeA) * cos(latitudeB) * cos(deltaLongitude)) * R;

    printf("Air distance is %lf\n", distance);
    return 0;
}
