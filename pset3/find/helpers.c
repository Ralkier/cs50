/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Declare and initialize variables.
    int i, j, tmp = 0;

    // Loop until i < n(sizeof(value[]...) - 1
    for (i = 0;i < n - 1;i++)
    {
        // Loop until j < n(sizeof(value[]...) - (i + 1)
        for(j = 0; j < n - (i + 1); j++)
        {
            // Check and compare index of values[]
            if(values[j] > values[j + 1])
            {
                // Start swaping
                // Make tmp = current index
                tmp=values[j];
                // Change value[j] to current index + 1
                values[j] = values[j + 1];
                // change the next index to tmp.
                values[j + 1] = tmp;
            }
        }
    }
    return;
}
