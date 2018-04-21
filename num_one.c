/*
 * Program filename: num_one.c
 * Author: Cory Ringer
 * Purpose: This program takes an integer and
 * gives the number of one's in the binary 
 * representation of that integer.
 * Initial Version Date: October 2017
 * Last updated: 21 April 2018
 */
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
 * Function: is_integer()
 * Purpose: Checks to see if char* s is an integer.
 */
bool is_integer(char* s)
{
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

/*
 * Function: num_one()
 * Purpose: Calculates the number of 1's in binary rep. of n.
 */
int num_one(int n)
{
    if (!n) // base case
        return 0;
    // induction
    else if (!(n % 2)) // n is even
        return num_one(n / 2);
    else // n is odd
        return num_one(n / 2) + 1;
}

/*
 * Function: main()
 * Purpose: Checks if user input 'argv[1]' is
 * an integer. If it is, then it prints the
 * number of ones for the binary representation
 * of 'argv[1]'.
 */
int main(int argc, char** argv)
{
    if (argv[1] == '\0') {
        fprintf(stderr, "%s: No such integer\n", argv[0]);
        exit(EXIT_FAILURE);
    } else if (!is_integer(argv[1])) { // argv[1] is
        fprintf(stderr,                // NOT an integer
                "%s: %s: No such integer\n",
                argv[0],
                argv[1]
            );
        exit(EXIT_FAILURE);
    } else { // Print number of 1's for binary rep. of argv[1].
        printf("%i\n", num_one(atoi(argv[1])));
        exit(EXIT_SUCCESS);
    }
}
