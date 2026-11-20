/**
 * Author: Veronica Lear
 * Date: 2026/10/29
 *
 * Function definitions for altering strings
 */

 #include <stdlib.h>
 #include <string.h>

 #include "string_utils.h"

 void replaceChar(char *s, char oldChar, char newChar) {
    if(s == NULL) {
        return;
    }
    int length = strlen(s);
    for(int i=0; i<length; i++) {
        if(s[i] == oldChar) {
            s[i] = newChar;
        }
    }
    return;
 }

 char * replaceCharCopy(const char *s, char oldChar, char newChar) {
    if(s == NULL) {
        return NULL;
    }
    int length = strlen(s);
    char *newS = (char *) malloc((length + 1) * sizeof(char));
    for(int i=0; i<=length; i++) {
        newS[i] = s[i];
    }
    replaceChar(newS, oldChar, newChar);
    return newS;
 }


 void removeChar(char *s, char c) {
    if(s == NULL) {
        return;
    }
    int length = strlen(s);
    char *tempString = (char *) malloc(sizeof(char) * (length +1));
    tempString[0] = '\0';
    int j = 0;
    for(int i=0; i<length; i++) {
        if(s[i] != c) {
            tempString[j] = s[i];
            j++;
        }
    }
    tempString[j] = '\0';
    int tempLength = strlen(tempString);
    for(int i=0; i<=tempLength; i++) {
        s[i] = tempString[i];
    }

    free(tempString);
    return;
 }

 char * removeCharCopy(const char *s, char c){
    if(s == NULL) {
        return NULL;
    }
    int length = strlen(s);
    char *newCopy = (char *) malloc(sizeof(char) * (length + 1));
    for(int i=0; i<=length; i++) {
        newCopy[i] = s[i];
    }
    removeChar(newCopy, c);
    return newCopy;
 }

 char **lengthSplit(const char *s, int n) {
    if(s == NULL || n <= 0) {
        return NULL;
    }
    int length = strlen(s);
    int totalElem;
    if(length % n != 0) {
        totalElem = (length / n) + 1;
    } else {
        totalElem = length / n;
    }

    char **newArray = (char **) malloc(sizeof(char *) * totalElem);
    for(int i=0; i<totalElem; i++) {
        newArray[i] = (char *) malloc(sizeof(char) * (n + 1));
        strcpy(newArray[i], "");
    }

    int sIndex = 0;
    int j;
    for(int i=0; i<totalElem; i++) {
        for(j=0; j<n || sIndex < n; j++) {
            newArray[i][j] = s[sIndex];
            sIndex++;
        }
        newArray[i][j] = '\0';
    }

    return newArray;
 }
