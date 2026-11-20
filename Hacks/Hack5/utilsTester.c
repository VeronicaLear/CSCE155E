/**
 * Author: Veronica Lear
 *
 * Date: 2026/10/01
 *
 * Test cases for functions in utils.c
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "utils.h"

const double EPSILON = 0.001;

int main(int argc, char **argv) {

    int numPassed = 0;
    int numFailed = 0;
    double degree, expectedResult, result;
    double originLatitude, originLongitude, destinationLatitude, destinationLongitude;
    double timeForLorentz, percentC;

    printf("Testing degreesToRadians\n");
    degree = 0;
    expectedResult = 0.0;
    result = degreesToRadians(degree);
    if(fabs(expectedResult - result) < EPSILON) {
        numPassed++;
        printf("Passed\n");
    } else {
        numFailed++;
        printf("Failed, expecting %f, but got %f. From input %f\n", expectedResult, result, degree);
    }

    degree = 45.2;
    expectedResult = 0.78888882;
    result = degreesToRadians(degree);
    if(fabs(expectedResult - result) < EPSILON) {
        numPassed++;
        printf("Passed\n");
    } else {
        numFailed++;
        printf("Failed, expecting %f, but got %f. From input %f\n", expectedResult, result, degree);
    }

    degree = 180;
    expectedResult = 3.14159265;
    result = degreesToRadians(degree);
    if(fabs(expectedResult - result) < EPSILON) {
        numPassed++;
        printf("Passed\n");
    } else {
        numFailed++;
        printf("Failed, expecting %f, but got %f. From input %f\n", expectedResult, result, degree);
    }

    degree = 420;
    expectedResult = 7.33038286;
    result = degreesToRadians(degree);
    if(fabs(expectedResult - result) < EPSILON) {
        numPassed++;
        printf("Passed\n");
    } else {
        numFailed++;
        printf("Failed, expecting %f, but got %f. From input %f\n", expectedResult, result, degree);
    }


    printf("Testing getAirDistance\n");

    originLatitude = 40.8136;
    originLongitude = -96.7026;
    destinationLatitude =  40.8200;
    destinationLongitude = -96.7000;
    expectedResult = 0.744523;
    result = getAirDistance(originLatitude, originLongitude, destinationLatitude, destinationLongitude);
    if(fabs(expectedResult - result) < EPSILON) {
        numPassed++;
        printf("Passed\n");
    } else {
        numFailed++;
        printf("Failed, expecting %f, but got %f. From input (%f,%f) and (%f,%f)\n", expectedResult, result, originLatitude, originLongitude, destinationLatitude, destinationLongitude);
    }

    originLatitude = 40.8136;
    originLongitude = -96.7026;
    destinationLatitude =  41.8781;
    destinationLongitude = -87.6298;
    expectedResult = 766.195548;
    result = getAirDistance(originLatitude, originLongitude, destinationLatitude, destinationLongitude);
    if(fabs(expectedResult - result) < EPSILON) {
        numPassed++;
        printf("Passed\n");
    } else {
        numFailed++;
        printf("Failed, expecting %f, but got %f. From input (%f,%f) and (%f,%f)\n", expectedResult, result, originLatitude, originLongitude, destinationLatitude, destinationLongitude);
    }


    originLatitude = 40.7128;
    originLongitude = -74.0060;
    destinationLatitude =  34.0522;
    destinationLongitude = -118.2437;
    expectedResult = 3935.746;
    result = getAirDistance(originLatitude, originLongitude, destinationLatitude, destinationLongitude);
    if(fabs(expectedResult - result) < EPSILON) {
        numPassed++;
        printf("Passed\n");
    } else {
        numFailed++;
        printf("Failed, expecting %f, but got %f. From input (%f,%f) and (%f,%f)\n", expectedResult, result, originLatitude, originLongitude, destinationLatitude, destinationLongitude);
    }

    originLatitude = 10;
    originLongitude = 12;
    destinationLatitude =  30;
    destinationLongitude = -110;
    expectedResult = 12388.829660;
    result = getAirDistance(originLatitude, originLongitude, destinationLatitude, destinationLongitude);
    if(fabs(expectedResult - result) < EPSILON) {
        numPassed++;
        printf("Passed\n");
    } else {
        numFailed++;
        printf("Failed, expecting %f, but got %f. From input (%f,%f) and (%f,%f)\n", expectedResult, result, originLatitude, originLongitude, destinationLatitude, destinationLongitude);
    }


    printf("Now testing lorentzTimeDilation\n");

    timeForLorentz = 1;
    percentC = 0.25;
    expectedResult = 1.032796;
    result = lorentzTimeDilation(timeForLorentz, percentC);
    if(fabs(expectedResult - result) < EPSILON) {
        numPassed++;
        printf("Passed\n");
    } else {
        numFailed++;
        printf("Failed, expecting %f, but got %f. From input t = %f and percentC = %f\n", expectedResult, result, timeForLorentz, percentC);
    }

    timeForLorentz = 100;
    percentC = 0.5;
    expectedResult = 115.47005;
    result = lorentzTimeDilation(timeForLorentz, percentC);
    if(fabs(expectedResult - result) < EPSILON) {
        numPassed++;
        printf("Passed\n");
    } else {
        numFailed++;
        printf("Failed, expecting %f, but got %f. From input t = %f and percentC = %f\n", expectedResult, result, timeForLorentz, percentC);
    }

    timeForLorentz = 0;
    percentC = 0.75;
    expectedResult = 0;
    result = lorentzTimeDilation(timeForLorentz, percentC);
    if(fabs(expectedResult - result) < EPSILON) {
        numPassed++;
        printf("Passed\n");
    } else {
        numFailed++;
        printf("Failed, expecting %f, but got %f. From input t = %f and percentC = %f\n", expectedResult, result, timeForLorentz, percentC);
    }

    printf("Passed: %d\n", numPassed);
    printf("Failed: %d\n", numFailed);
    printf("Percentage: %.2f%%\n", numPassed / ((double)numFailed + numPassed) * 100.0);

    return 0;
}
