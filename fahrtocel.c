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

#define NUM atoi(argv[1])

int main(int argc, char ** argv)
{
    const int DEFAULT_COUNT = 10;
    const char * HEADING = "Fahrenheit\tCelsius";
    int i = 0;
    int count;
    
    if (argc > 1)
	count = NUM;
    else
	count = DEFAULT_COUNT;

    puts(HEADING);
    while (i < count) {
	const int INCREMENT = 100;
	const int START_FAHR = 0;
	const double FREEZING_POINT = 32.0;
	const double SCALE_FACTOR = (5.0 / 9.0);
	const char * TABLE = "%.0lf\t\t%.2f\n";
	double fahr, cel;
	
	fahr = i * INCREMENT + START_FAHR;
	cel = (fahr - FREEZING_POINT) * SCALE_FACTOR;
	printf(TABLE, fahr, cel);
	i++;
    }
    return 0;
}
