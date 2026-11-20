/**
 * Author: Veronica Lear
 * Date: 2026/11/05
 *
 * Converts DNA files into RNA and then proteins
 * Reads DNA from file and puts the protein sequence
 * into another file
 */

 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>

 #include "protein_utils.h"
 #include "file_utils.h"

 int main (int argc, char ** argv) {
    if(argc != 3) {
        printf("Invalid number of CLI, needs file read and name of newfile\n");
        return 1;
    }

    char *readFilePath = argv[1];
    char *writeFilePath = argv[2];

    FILE *readFile = fopen(readFilePath, "r");
    FILE *writeFile = fopen(writeFilePath, "w");

    int numLines = 0;
    char **sequence = getFileLines(readFilePath, &numLines);

    //DNA to RNA
    for(int i=0; i<numLines; i++) {
       for(int j=0; j<strlen(sequence[i]); j++) {
           if(sequence[i][j] == 'T') {
               sequence[i][j] = 'U';
           }
       }
    }


    //RNA to protein
    char *tempRNA = (char *) malloc(sizeof(char) * 4);
    tempRNA[0] = '\0';
    int RNAIndexing = 0;
    char *finalSequence = (char *) malloc(sizeof(char) * 2000);
    int proteinCounter = 0;

    for(int i=0; i<numLines; i++) {
        if(proteinCounter != 0 && finalSequence[proteinCounter - 1] == 'x') {
                break;
            }
        for(int j=0; j<strlen(sequence[i]); j++) {
            if(RNAIndexing == 3) {
                tempRNA[RNAIndexing] = '\0';
                RNAIndexing = 0;
                finalSequence[proteinCounter] = rnaToProtein(tempRNA);
                proteinCounter++;
            }
            if(proteinCounter != 0 && finalSequence[proteinCounter - 1] == 'x') {
                break;
            }
            tempRNA[RNAIndexing] = sequence[i][j];
            RNAIndexing++;
        }
     }
     finalSequence[proteinCounter - 1] = '\0';

     fprintf(writeFile, "%s", finalSequence);


    fclose(readFile);
    fclose(writeFile);
    free(finalSequence);
    free(tempRNA);

    return 0;
 }
