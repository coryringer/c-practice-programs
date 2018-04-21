/**
 * Project name: hi_lo
 * Program filename: hi_lo.c
 * Author: Cory Ringer
 * Last Updated: 20 April 2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * TODO:
 * -create demo mode which lets the computer play by itself
 * -allow user to exit program by typing 'quit' or 'exit'
 * -have command 'guesses' which
 *  lists all previous guesses (requires linked list)
 * -fix user query in main for restarting program
 */

#define LOW_LIMIT       1
#define HIGH_LIMIT      100
#define QUIT_GAME       -1
#define NO              0
#define YES             1
#define INVALID         2

int run_game(void);

/**
 * Function: main()
 * Purpose: Starts up Hi-low game. After it has been
 * completed, it asks the user if he/she would like to
 * play again.
 */
int main(void)
{
    int val, count;
    char input;

    do {
        count = run_game();
        printf("\nYou finished the game with %i guess(es).\n"
               "Do you you wish to play again? (Y/n)\n",
               count
            );

        /*
         * Query user to play again after game is finished,
         * loop if user input is neither y or n
         */
        do {
            printf("> ");
            scanf(" %c", &input);
            while (getchar() != '\n')
                ;

            switch(input)
            {
            case 'n':
                val = NO;
                break;
            case 'N':
                val = NO;
                break;
            case 'Y':
                val = YES;
                break;
            case 'y':
                val = YES;
                break;
            default:
                printf("ERROR: Invalid entry.\n");
                val = INVALID;
            }
        } while(val == INVALID);
    } while (val);
    printf("Goodbye.\n");
    return 0;
}

/*
 * Function: run_game()
 * Purpose: Start game, terminate if user exits program.
 * Returns the number of guesses the user made before 
 * winning game.
 */
int run_game(void)
{
    int guess, rand_number,
        count_guesses, low, high;
    time_t t;

    low = LOW_LIMIT;    // initialize low
    high = HIGH_LIMIT;  // initialize high
    srand(time(&t));    // set random number
    rand_number = (rand() % high) + low;
    count_guesses = 0;  // Initialize counter to zero

    printf("\nI'm thinking of a number between"
           " %i and %i.\n", low, high
        );

    /*
     * Start game, loop until
     * player wins or quits
     */
    do {
        printf("Pick a number between %i and %i\n> ",
               low, high
            );
        scanf("%i", &guess);
        count_guesses++;                  // increment counter
                                          // at every guess
        if (guess == QUIT_GAME) {
            printf("Goodbye.\n");
            exit(0);
        } else if ((guess < rand_number)  // replace low number
                   && (guess > low))      // with guess if guess > low
        { low = guess; }
        else if ((guess > rand_number)    // replace high number
                 && (guess < high))       // with guess if guess < high
        { high = guess; }
    } while (guess != rand_number);
    return count_guesses;
}
