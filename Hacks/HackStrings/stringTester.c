/**
 * Author: Veronica Lear
 * Date: 2026/10/29
 *
 * A testing file for functions about altering strings
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>

 #include "string_utils.h"

 /**
  * Compares two arrays of strings to see if they are equal
  */
 int stringArraysEqual(char **a, char **b, int n);


 int main(int argc, char **argv) {
    int numPassed = 0;
    int numFailed = 0;
    char *testingString = (char *) malloc(sizeof(char) * 50);
    char *solvingString = (char *) malloc(sizeof(char) * 50);
    char *copyString = (char *) malloc(sizeof(char) * 50);


    printf("Now Testing replaceChar\n");
    char oldChar = 'e';
    char newChar = 'o';

    strcpy(testingString, "Hello There!");
    strcpy(solvingString, "Hollo Thoro!");
    replaceChar(testingString, oldChar, newChar);
    if(strcmp(testingString, solvingString) != 0) {
        printf("Failed, returned %s but expected %s\n", testingString, solvingString);
        numFailed++;
    } else {
        printf("Passed\n");
        numPassed++;
    }

    oldChar = 'r';
    newChar = 'q';
    strcpy(testingString, "how you doing today");
    strcpy(solvingString, "how you doing today");
    replaceChar(testingString, oldChar, newChar);
    if(strcmp(testingString, solvingString) != 0) {
        printf("Failed, returned %s but expected %s\n", testingString, solvingString);
        numFailed++;
    } else {
        printf("Passed\n");
        numPassed++;
    }

    oldChar = 'q';
    newChar = 'w';
    strcpy(testingString, "Quack quack is what a duck says");
    strcpy(solvingString, "Quack wuack is what a duck says");
    replaceChar(testingString, oldChar, newChar);
    if(strcmp(testingString, solvingString) != 0) {
        printf("Failed, returned %s but expected %s\n", testingString, solvingString);
        numFailed++;
    } else {
        printf("Passed\n");
        numPassed++;
    }

    oldChar = '!';
    newChar = '?';
    strcpy(testingString, "!It is beautiful!! WOW!");
    strcpy(solvingString, "?It is beautiful?? WOW?");
    replaceChar(testingString, oldChar, newChar);
    if(strcmp(testingString, solvingString) != 0) {
        printf("Failed, returned %s but expected %s\n", testingString, solvingString);
        numFailed++;
    } else {
        printf("Passed\n");
        numPassed++;
    }


    printf("Now Testing replaceCharCopy\n");

    oldChar = 'V';
    newChar = 'p';
    strcpy(testingString, "My name if Veronica, very coool");
    strcpy(solvingString, "My name if peronica, very coool");
    copyString = replaceCharCopy(testingString, oldChar, newChar);
    if(strcmp(copyString, solvingString) != 0) {
        printf("Failed, returned %s but expected %s\n", copyString, solvingString);
        numFailed++;
    } else {
        printf("Passed\n");
        numPassed++;
    }

    oldChar = ' ';
    newChar = '_';
    strcpy(testingString, "I had a great day today");
    strcpy(solvingString, "I_had_a_great_day_today");
    copyString = replaceCharCopy(testingString, oldChar, newChar);
    if(strcmp(copyString, solvingString) != 0) {
        printf("Failed, returned %s but expected %s\n", copyString, solvingString);
        numFailed++;
    } else {
        printf("Passed\n");
        numPassed++;
    }

    oldChar = '2';
    newChar = '3';
    strcpy(testingString, "21,22,23,24,25");
    strcpy(solvingString, "31,33,33,34,35");
    copyString = replaceCharCopy(testingString, oldChar, newChar);
    if(strcmp(copyString, solvingString) != 0) {
        printf("Failed, returned %s but expected %s\n", copyString, solvingString);
        numFailed++;
    } else {
        printf("Passed\n");
        numPassed++;
    }

    oldChar = '+';
    newChar = '/';
    strcpy(testingString, "abc + def = abcdef");
    strcpy(solvingString, "abc / def = abcdef");
    copyString = replaceCharCopy(testingString, oldChar, newChar);
    if(strcmp(copyString, solvingString) != 0) {
        printf("Failed, returned %s but expected %s\n", copyString, solvingString);
        numFailed++;
    } else {
        printf("Passed\n");
        numPassed++;
    }


    printf("Now testing removeChar\n");

    oldChar = 'e';
    strcpy(testingString, "ewww, I don't like the letter e");
    strcpy(solvingString, "www, I don't lik th lttr ");
    removeChar(testingString, oldChar);
    if(strcmp(testingString, solvingString) != 0) {
        printf("Failed, returned %s but expected %s\n", testingString, solvingString);
        numFailed++;
    } else {
        printf("Passed\n");
        numPassed++;
    }

    oldChar = 'v';
    strcpy(testingString, "v is very cool");
    strcpy(solvingString, " is ery cool");
    removeChar(testingString, oldChar);
    if(strcmp(testingString, solvingString) != 0) {
        printf("Failed, returned %s but expected %s\n", testingString, solvingString);
        numFailed++;
    } else {
        printf("Passed\n");
        numPassed++;
    }

    oldChar = ' ';
    strcpy(testingString, "what a great day!");
    strcpy(solvingString, "whatagreatday!");
    removeChar(testingString, oldChar);
    if(strcmp(testingString, solvingString) != 0) {
        printf("Failed, returned %s but expected %s\n", testingString, solvingString);
        numFailed++;
    } else {
        printf("Passed\n");
        numPassed++;
    }


    printf("Now testing removeCharCopy\n");

    oldChar = ' ';
    strcpy(testingString, "abc + def = abcdef");
    strcpy(solvingString, "abc+def=abcdef");
    copyString = removeCharCopy(testingString, oldChar);
    if(strcmp(copyString, solvingString) != 0) {
        printf("Failed, returned %s but expected %s\n", copyString, solvingString);
        numFailed++;
    } else {
        printf("Passed\n");
        numPassed++;
    }

    oldChar = 's';
    strcpy(testingString, "this is testing s");
    strcpy(solvingString, "thi i teting ");
    copyString = removeCharCopy(testingString, oldChar);
    if(strcmp(copyString, solvingString) != 0) {
        printf("Failed, returned %s but expected %s\n", copyString, solvingString);
        numFailed++;
    } else {
        printf("Passed\n");
        numPassed++;
    }

    oldChar = 'p';
    strcpy(testingString, " ");
    strcpy(solvingString, " ");
    copyString = removeCharCopy(testingString, oldChar);
    if(strcmp(copyString, solvingString) != 0) {
        printf("Failed, returned %s but expected %s\n", copyString, solvingString);
        numFailed++;
    } else {
        printf("Passed\n");
        numPassed++;
    }

    oldChar = 'a';
    strcpy(testingString, "University of Nebraska");
    strcpy(solvingString, "University of Nebrsk");
    copyString = removeCharCopy(testingString, oldChar);
    if(strcmp(copyString, solvingString) != 0) {
        printf("Failed, returned %s but expected %s\n", copyString, solvingString);
        numFailed++;
    } else {
        printf("Passed\n");
        numPassed++;
    }


    printf("Now testing lengthSplit\n");
    char ** arrayStrings;
    int stringLength = 4;
    char * expectedStrings[25];
    char * providedString = (char *) malloc(sizeof(char) * 50);

    expectedStrings[0] = "I li";
    expectedStrings[1] = "ke t";
    expectedStrings[2] = "urtl";
    expectedStrings[3] = "es";

    strcpy(providedString, "I like turtles");
    arrayStrings = lengthSplit(providedString, stringLength);
    if(!stringArraysEqual(expectedStrings, arrayStrings, 4)) {
        printf("Failed\n");
        numFailed++;
    } else {
        printf("Passed\n");
        numPassed++;
    }

    stringLength = 3;
    expectedStrings[0] = "Hel";
    expectedStrings[1] = "lo ";
    expectedStrings[2] = "Wor";
    expectedStrings[3] = "ld,";
    expectedStrings[4] = " ho";
    expectedStrings[5] = "w a";
    expectedStrings[6] = "re ";
    expectedStrings[7] = "you";
    expectedStrings[8] = "?";

    strcpy(providedString, "Hello World, how are you?");
    arrayStrings = lengthSplit(providedString, stringLength);
    if(!stringArraysEqual(expectedStrings, arrayStrings, 9)) {
        printf("Failed\n");
        numFailed++;
    } else {
        printf("Passed\n");
        numPassed++;
    }

    stringLength = 6;
    expectedStrings[0] = "I am h";
    expectedStrings[1] = "aving ";
    expectedStrings[2] = "a grea";
    expectedStrings[3] = "t day ";
    expectedStrings[4] = "today!";

    strcpy(providedString, "I am having a great day today!");
    arrayStrings = lengthSplit(providedString, stringLength);
    if(!stringArraysEqual(expectedStrings, arrayStrings, 5)) {
        printf("Failed\n");
        numFailed++;
    } else {
        printf("Passed\n");
        numPassed++;
    }

    stringLength = 1;
    expectedStrings[0] = " ";

    strcpy(providedString, " ");
    arrayStrings = lengthSplit(providedString, stringLength);
    if(!stringArraysEqual(expectedStrings, arrayStrings, 1)) {
        printf("Failed\n");
        numFailed++;
    } else {
        printf("Passed\n");
        numPassed++;
    }


    double percentPassed = 100 * (double)numPassed / (numPassed + numFailed);
    printf("%d passed, %d failed\n", numPassed, numFailed);
    printf("%.0f%%\n", percentPassed);

    free(testingString);
    free(solvingString);
    free(copyString);
    free(providedString);
    free(arrayStrings);

    return 0;
 }


 int stringArraysEqual(char **a, char **b, int n) {

    if(a == NULL && b == NULL) {
        return 1;
    } else if( (a == NULL && b != NULL) || (a != NULL && b == NULL) ) {
        return 0;
    }

    for(int i=0; i<n; i++) {
        if( strcmp(a[i], b[i]) != 0 ) {
            return 0;
        }
    }
    return 1;
}
