/**
 * Program filename: fibonacci_ptrs.c
 * Author: Cory Ringer
 * Last Updated: 28 February 2018
 */
#include <stdio.h>
#include <stdlib.h>

#define SIZE atoi(argv[1])

int main(int argc, char **argv)
{
    int i;
    unsigned long int fib_nums[SIZE], *prev, *curr;

    prev = fib_nums;
    curr = fib_nums + 1;
    *prev = 0;
    *curr = 1;

    for (i = 0; i < size-1; i++) {
        printf("%li\n", *prev);
        *(curr + 1) = *curr + *prev;
        prev = curr;
        curr = curr + 1;
    }
}
