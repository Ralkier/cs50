/**************************************************************
 * mario.c                                                     *
 *                                                             *
 *     By Ralkier (Jason Yoder)                                *
 *     CS50 2014                                               *
 *                                                             *
 *     Print a pyramid using the hash symbol (#)               *
 *     syntax: ./mario                                         *
 *                                                             *
 **************************************************************/
// printf()
#include <stdio.h>
// GetInt()
#include <cs50.h>

void pyrm(int width);

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
    
    pyrm(p_width);

    return 0;
}

// pyrm function to print spaces and hashes based on width
// (width = user input).
void pyrm(int width)
{
    // Setup and init variables
    int p_space = 0;
    int p_hash = 0;
    
    // for loop to print spaces and hashes to screen.
    for (int i = 2; i < width; i++)
    {
        p_space = width - (i);
        p_hash = i;
        
        while (p_space != 1)
        {
            printf(" ");
            p_space--;
        }
        
        while (p_hash != 0)
        {
            printf("#");
            p_hash--;
        }
        
        printf("\n");   
    }
}
