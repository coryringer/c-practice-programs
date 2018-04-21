/*
 * Filename: fahrtocel.c
 * Author: Cory Ringer
 * Last Updated: 21 April 2018
 * Purpose: This program creates a table of Fahrenheit
 * values and their corresponding Celsius conversions. 
 * 
 * This is a modification of an example program from 
 * K.N. King's "C Programming: A Modern Approach" 1st Ed.
 */
#include <stdio.h>
#include <stdlib.h>

#define FREEZING_POINT 32.0
#define SCALE_FACTOR 5.0 / 9.0
#define START_FAHR 0
#define INCREMENT 100
#define LOOPCOUNT 10

#define HEADING "Fahrenheit\tCelsius"
#define TABLE "%.0lf\t\t%.2f\n"

#define NUM(x) atof(argv[x])

int main(void)
{
    int i = 0;
    double fahr, cel;

    puts(HEADING);
    while (i < LOOPCOUNT) {
	fahr = i * INCREMENT + START_FAHR;
	cel = (fahr - FREEZING_POINT) * SCALE_FACTOR;
	printf(TABLE, fahr, cel);
	i++;
    }
    return 0;
}
