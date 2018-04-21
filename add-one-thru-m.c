/**
 * Program filename: add-one-thru-m.c
 * Author: Cory Ringer
 * Last Updated: 9 April 2018
 * Purpose: This program takes two numbers, N and M,
 * and outputs N + (1 + 2 + ... + M).
 */
#include <stdio.h>
#include <stdlib.h>

#define arg(n) atoi(argv[n])

int foo(int num, int count)
{
    if (count < 0) {
        fprintf(stderr,
                "ERROR, second value must "
                "be positive.\n"
            );
        exit(EXIT_FAILURE);
    } else if (count == 0)
        return num;
    else {
        /* Add M with N, decrement M. */
        return foo(num + count,
                   count - 1
            );
    }
}

int main(int argc, char **argv)
{
    printf("%i\n", foo(arg(1), arg(2)));
    return 0;
}
