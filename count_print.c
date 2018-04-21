// count_print.c
#include <stdio.h>

int main(void)
{
    const int array_val = 51;
    int array[array_val];
    int i;
    
    for (i = 0; i < array_val; i++)
	array[i] = 0;

    while (1) {
        int val;

        printf("Pick a number between 0 and 50: ");
        scanf("%i", &val);

        if (val == -1) {
	    int i;
	    
	    for (i = 0; i < array_val; i++) {
		if (array[i] >= 1)
		    printf("%i\t%i\n", i, array[i]);
	    }
	    return 0;
        } else if (val < (array_val - 1) || val > 0)
            array[val] += 1;
    }

    return 0;
}
