/**************************************************************
 * greedy.c                                                    *
 *                                                             *
 *     By Ralkier (Jason Yoder)                                *
 *     CS50 2014                                               *
 *                                                             *
 *     Get press count for a belt changer                      *
 *     syntax: ./mario                                         *
 *                                                             *
 **************************************************************/
// GetFloat(), 
#include <cs50.h>
// printf()
#include <stdio.h>
// round()
#include <math.h>

int main(void)
{
    int press_count = 0;
    // GDB, LOVE IT! Wasn't doing floats at first.
    float tmp = 0;
    do
    {
        printf("O hai! How much change is owed?: ");
        tmp = GetFloat();
	}
	
	// Start of press count.. countdown.
	while(tmp < 0);

    // Round it up!
    int change_owed =  round(tmp * 100);
    
    if (change_owed < 0)
    {
        printf("Enter a positive amount\n");
        return 1;
    }

    while (change_owed >= 25)
    {
        change_owed = change_owed - 25;
        press_count++;
    }

    while (change_owed >= 10)
    {
        change_owed = change_owed - 10;
        press_count++;
    }

    while (change_owed >= 5)
    {
        change_owed = change_owed - 5;
        press_count++;
    }
    
    // Oh look we are at 0...or less.
    while (change_owed > 0)
    {
        change_owed = change_owed - 1;
        press_count++;
    }
    // Print the press count.
    printf("%d\n", press_count);

    return 0;
}
