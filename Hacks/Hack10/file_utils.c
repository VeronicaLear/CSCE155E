/**
 * Author: Veronica Lear
 * Date: 2026/11/05
 *
 * Source file for reading and extracting file data
 * and putting it into either one string or an array
 * of strings
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>

 #include "file_utils.h"

char *getFileContents(const char *filePath) {
    if(filePath == NULL) {
        return NULL;
    }
    FILE *f = fopen(filePath, "r");
    if(f == NULL) {
        return NULL;
    }
    fseek(f, 0, SEEK_END);
    int fileSize = ftell(f);
    rewind(f);

    int maxSize = 2000;
    char buffer[2000];
    char *newString = (char *) malloc(sizeof(char) * fileSize + 1);

    //puts in first line and reads second line if there is one
    char *s = fgets(buffer, maxSize, f);
    if(s == NULL) {
        fclose(f);
        newString[0] = '\0';
        return newString;
    }

    strcpy(newString, buffer);
    s = fgets(buffer, maxSize, f);

    //checks for end of the file
    while(s != NULL) {
        strcat(newString, buffer);
        s = fgets(buffer, maxSize, f);
    }

    fclose(f);
    return newString;
}


char **getFileLines(const char *filePath, int *numLines) {
    if(filePath == NULL || numLines == NULL) {
        return NULL;
    }
    FILE *f = fopen(filePath, "r");
    if(f == NULL) {
        return NULL;
    }

    int maxSize = 2000;
    char buffer[2000];

    int lineCounter = 0;
    char *s = fgets(buffer, maxSize, f);

    //counts lines in file
    while(s != NULL) {
        lineCounter++;
        s = fgets(buffer, maxSize, f);
    }

    *numLines = lineCounter;
    //if file is empty
    if(lineCounter == 0) {
        fclose(f);
        return NULL;
    }

    char **newString = (char **) malloc(sizeof(char *) * lineCounter);
    rewind(f);
    s = fgets(buffer, maxSize, f);

    for(int i=0; i<lineCounter; i++) {
        if(buffer[strlen(buffer) - 1] == '\n') {
            buffer[strlen(buffer) - 1] = '\0';
        }
        newString[i] = (char *) malloc(sizeof(char) * strlen(buffer) + 1);
        strcpy(newString[i], buffer);
        s = fgets(buffer, maxSize, f);
    }
    fclose(f);
    return newString;

}
