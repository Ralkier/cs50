/**************************************************************
 * caesar.c                                                    *
 *                                                             *
 *     By Ralkier (Jason Yoder)                                *
 *     CS50 2014                                               *
 *                                                             *
 *     Encrypt text using Caesar Cipher                        *
 *     syntax: caesar # (# = a Non negative number)            *
 *                                                             *
 **************************************************************/
// data type string, GetString(), atoi(),free() <-stdlib.h(Located in cs50.h)
#include <cs50.h>
// printf()
#include <stdio.h>
// strlen()
#include <string.h>
// isalpha(),isupper(),islower()
#include <ctype.h>

// Prototypes.
int changeLetter(int letter, int shiftPos, bool sCase);
void errorMessage(void);

int main(int argc, string argv[])
{
    // Print error if command line option is missing.
    if (argc != 2)
    {
        errorMessage();
        return 1;
    }

    // Convert argv[1] into data type int.
    int shift = atoi(argv[1]);
    // Deal with argv[] Just quit if the entry is invalid.
    if (shift < 1)
    {
        errorMessage();
        return 1;
    }
    // Get user input.
    string textEncrypt = GetString();

    // Start of user string(textEncrypt) handling.
    for (int i = 0; i < strlen(textEncrypt); i++)
    {

        // Check for alphabetic characters.
        if (isalpha(textEncrypt[i]))
        {
            // Check for uppercase.
            if (isupper(textEncrypt[i]))
            {
                printf("%c", changeLetter(textEncrypt[i], shift, 1));
                continue;

            // Check for lower case.
            }
            else if (islower(textEncrypt[i]))
            {
                printf("%c", changeLetter(textEncrypt[i], shift, 0));
            }
            continue;

            // Print everything that isn't alpha.
        }
        else
        {
            printf("%c", textEncrypt[i]);
        }
    }
    free(textEncrypt);
    printf("\n");
    return 0;
}

// Error message
void errorMessage(void)
{
    printf("Invalid Syntax\nSyntax: casesar #\n");
}

// encrypt function.
int changeLetter(int letter, int shiftPos, bool sCase)
{
    int x;
    // Handle uppercase letters.
    if (sCase)
        /*So... Z would be 90
        (90 - 65 + 5)%26=4
        4+65=69 (E)*/
    {
        x = (letter - 'A' + shiftPos) % 26 + 'A';
    }
    // Handle lowercase letters.
    if (!sCase)
    {
        x = (letter - 'a' + shiftPos) % 26 + 'a';
    }
    return x;
}
