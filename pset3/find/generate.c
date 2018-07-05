/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
       
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LIMIT 65536

int main(int argc, string argv[])
{
    // Lets check for command line arguments.
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // Convert string into an integer.
    int n = atoi(argv[1]);

    // If there is a seed option, create first random
    // else use time.
    if (argc == 3)
    {
        srand((unsigned int) atoi(argv[2]));
    }
    else
    {
        srand((unsigned int) time(NULL));
    }

    // Loop through n and print remainder of rand() / 65536
    for (int i = 0; i < n; i++)
    {
        printf("%i,", rand() % LIMIT);
    }

    // Th-th-th-that's all folks!
    return 0;
}
