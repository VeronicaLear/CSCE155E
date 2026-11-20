/**
 * Author: Veronica Lear
 * Date: 2026/10/27
 *
 * A collection of prototypes that are used for dealing with strings
 * and playing the game horse
 */

/**
 * Takes two inputs as an interger saying the length of the string (not including \0)
 * and a string that will be altered to be all underscores
 */
void initializeBlankString(int length, char *newBlank);

/**
 * Takes one argument of a string and goes through and prints
 * each element with spaces in between
 */
void printWithSpaces(char *printString);

/**
 * Takes three parameters, the solution, what the person can see / have guessed so far,
 * and the letter that they are guessing now
 * It will change what they can see if they guess a right letter and will return 1 if
 * they guess right, 0 if they guess wrong
 */
int revealGuessedLetter(const char *solution, char *partialReveal, char guess);

/**
 * Compares the two strings that are given and returns 1 if they are the same
 * and 0 if they are not.
 */
int checkGuess(const char *firstString, const char *secondString);

/**
 * Sets the game up, checks for win condition,
 * prints relevant data.  This function has already
 * been implemented for you.
 */
void startGame(char *wordToGuess);
