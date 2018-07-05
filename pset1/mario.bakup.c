/**************************************************************
*     By Ralkier (Jason Yoder)                                *
*     CS50 2014                                               *
*                                                             *
*     Create a pyramid                                        *
*      mario.c                                                *
**************************************************************/
// Modified for 2013-2014 CS50. (edx.org)
// Add a function for the hashes.
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int p_height = -1;
    // Loop while p_height is < 0 or > 23
    while (p_height < 0 || p_height > 23)
    {
        printf("Enter pyramid height (Between 8 and 23): ");
        // Make sure it is an INT!
        p_height = GetInt();
    }
    // p_width,p_height... self explanitory.
    int p_width = p_height + 2;
    /* p_space (You know... space.. the Space bar
       dec 32..., hex 0x20... oh forget it!)*/
    int p_space = 0;
    // p_hash  (You know, the #)
    int p_hash = 0;
    // Start loop for drawing the pyramid.
    for (int i = 2; i < p_width; i++)
    {
        p_space = p_width - (i);
        
        // While space is NOT equal to 1.
        while (p_space != 1)
        {
            printf(" ");
            p_space--;
        }
        p_hash = i;
        
        // While # is NOT equal to 0.
        while (p_hash != 0)
        {
            printf("#");
            p_hash--;
        }
        printf("\n");
    }
    return 0;
}

