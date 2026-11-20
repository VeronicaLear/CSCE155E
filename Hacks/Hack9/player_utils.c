/**
 * Author: Veronica Lear
 * Date: 2026/10/22
 *
 * Function Definitions for tic tac toe game
 * and making a move
 */

#include <stdlib.h>
#include <stdio.h>

#include "utils.h"
#include "game_utils.h"
#include "player_utils.h"


void userMove(Move **board, Move player) {

  int input = 0;
  while(input == 0) {
    printf("Please enter a choice (1-9): ");
    scanf("%d", &input);
    flushInput();
    if(input < 1 || input > 9) {
      printf("Error: input is out of range, try again.\n");
    } else if(board[(input-1)/3][(input-1) % 3] != NONE) {
      printf("Error: that choice was already made.\n");
    } else {
      //we map 1-9 to [0][0] thru [2][2]:
      board[(input-1)/3][(input-1) % 3] = player;
      return;
    }
    input = 0;
  }
}
