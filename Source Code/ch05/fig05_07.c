// fig05_07.c
// Simulating the game of rock, paper, and scissors
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // contains prototype for function time

enum GameStatus {CONTINUE, GAME_WON, GAME_LOST}; // constants represent game status
enum RoundStatus {DRAW, WON, LOST}; // constants represent round status
enum Shape {ROCK, PAPER, SCISSORS}; // constants representing possible shapes

enum Shape computerPlayRandomShape(void); // playRandomShape function prototype;
enum RoundStatus getRoundStatus(enum Shape, enum Shape);
enum Shape convertIntToShape(int);
char* getStringFromShape(enum Shape);

int main(void) {
    srand(time(NULL)); // randomize based on current time
    enum GameStatus gameStatus = CONTINUE; // may be CONTINUE, GAME_WON, or GAME_LOST
    int bestOfN = 3; // best of 3 game
    int winThreshold = (bestOfN / 2) + 1;

    int playerWinCount = 0;
    int computerWinCount = 0;

    int roundNum = 0;

    // while game not complete
    while (CONTINUE == gameStatus) { // should keep playing
        printf("==================\nRound %d\n==================\n", roundNum++);
        printf("Enter 0 (ROCK), or 1 (PAPER), or 2 (SCISSORS): ");

        int playerShapeInt = -1;
        scanf(" %d", &playerShapeInt);

        enum Shape playerShape = convertIntToShape(playerShapeInt); // player shape
        enum Shape computerShape = computerPlayRandomShape(); // computer plays random shape

        enum RoundStatus roundStatus = getRoundStatus(playerShape, computerShape); // get winner for current round
        switch (roundStatus) {
            case DRAW:
                printf("It's a DRAW!\n");
                break;
            case WON:
                printf("Player WON!\n");
                if (++playerWinCount == winThreshold) {
                    // Increment win count, if win count reaches threshold, player wins the game
                    gameStatus = GAME_WON;
                }
                break;
            case LOST:
                printf("Player LOST!\n");
                if (++computerWinCount == winThreshold) {
                    // Increment win count, if win count reaches threshold, computer wins the game
                    gameStatus = GAME_LOST;
                }
                break;
        }
    }

    switch (gameStatus) {
        case GAME_WON:
            printf("**Best of %d game is WON by player!**\n", bestOfN);
            break;
        case GAME_LOST:
            printf("**Best of %d game is WON by computer!**\n", bestOfN);
            break;
        case CONTINUE:
        default:
            printf("**Error! Should not reach here!**");
    }
}

// play a random shape and display result
enum Shape computerPlayRandomShape(void) {
    enum Shape randomShape = convertIntToShape(rand() % 3);
    printf("Computer played %s\n", getStringFromShape(randomShape));
    return randomShape;
}

enum RoundStatus getRoundStatus(enum Shape playerShape, enum Shape computerShape) {
    if (playerShape == computerShape) {
        return DRAW;
    } else if ((playerShape == ROCK && computerShape == SCISSORS)
        || (playerShape == SCISSORS && computerShape == PAPER)
        || (playerShape == PAPER && computerShape == ROCK)) {
        return WON;
    } else {
        return LOST;
    }
}

enum Shape convertIntToShape(int shapeValue) {
    return (enum Shape) shapeValue;
}

char * getStringFromShape(enum Shape shape) {
    switch (shape) {
        case ROCK:
            return "ROCK";
        case PAPER:
            return "PAPER";
        case SCISSORS:
            return "SCISSORS";
    }
    return "";
}
