/**
 * Program filename: fibonacci_ptrs.c
 * Author: Cory Ringer
 * Last Updated: 28 February 2018
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i;
    int size = atoi(argv[1]);
    unsigned long int a[size], *prev, *curr;

    prev = a;
    curr = a + 1;
    *prev = 0;
    *curr = 1;

    for (i = 0; i < size-1; i++) {
        printf("%li\n", *prev);
        *(curr + 1) = *curr + *prev;
        prev = curr;
        curr = curr + 1;
    }
}
