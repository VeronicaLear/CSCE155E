/**
 * Author: Veronica Lear
 * Date: 2026/10/27
 *
 * A collection of funciton definitions for dealing with strings
 * and playing the game horse
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "game_functions.h"

void initializeBlankString(int length, char *newBlank) {
  if(length < 0 || newBlank == NULL) {
    return;
  }
  for(int i=0; i<length; i++) {
    newBlank[i] = '_';
  }
  newBlank[length] = '\0';

  return;
}

void printWithSpaces(char *printString) {
  if(printString == NULL) {
    return;
  }

  int length = strlen(printString);
  for(int i=0; i<length; i++) {
    printf("%c ", printString[i]);
  }
  return;
}

int revealGuessedLetter(const char *solution, char *partialReveal, char guess) {
  int length = strlen(solution);
  int changes = 0;
  for(int i=0; i<length; i++) {
    if(solution[i] == guess) {
      partialReveal[i] = guess;
      changes++;
    }
  }
  if(changes > 0) {
    return 1;
  } else {
    return 0;
  }
}

int checkGuess(const char *firstString, const char *secondString) {
  //compares the two strings
  if(strcmp(firstString, secondString)) {
    return 0;
  } else {
    return 1;
  }
}


void startGame(char word[25]) {
  int won = 0;  // Flag to see if the user has won yet
  int numBadGuesses = 0;  // Counter to end the game on a lose condition
  int possibleBadGuesses;  // Total number of bad guesses allowed
  int charRevealed;  // Flag to see if the user guessed a good letter
  char guess;  // The user's guess
  char revealedLetters[25];  // What the user has revealed so far

  // Initializes the guessing array to all underscores
  initializeBlankString(strlen(word), revealedLetters);

  // Gets the total number of chances
  printf(
      "Please enter the total number of incorrect guesses you would like to be "
      "able to make: ");
  scanf("%d", &possibleBadGuesses);
  printWithSpaces(revealedLetters);

  // Runs the game loop until the number of tries are exhausted or the word is
  // found
  while (numBadGuesses < possibleBadGuesses && !won) {
    printf("Enter a letter to guess: ");
    scanf(" %c", &guess);

    // Updates the revealed letters and checks to see if the user won
    charRevealed = revealGuessedLetter(word, revealedLetters, guess);
    won = checkGuess(word, revealedLetters);

    // Increments bad guesses if the last guess was a miss
    if (!charRevealed) {
      numBadGuesses++;
      printf("Sorry, there is no %c\n", guess);
    } else {
      printf("Yes, '%c' is in the solution!\n", guess);
    }

    // Outputs game information to the user
    printWithSpaces(revealedLetters);
  }

  if (won) {
    printf("Congratulations!  You correctly guessed the word %s\n", word);
  } else {
    printf("You've run out of guesses.  The correct word was %s\n", word);
  }
}
