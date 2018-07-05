/**************************************************************
 * vigenere.c                                                  *
 *                                                             *
 *     By Ralkier (Jason Yoder)                                *
 *     CS50 2012                                               *
 *                                                             *
 *     Encrypt text using vigenere cipher                      *
 *     syntax: vigenere <key> (<key> = some text)              *
 *                                                             *
 **************************************************************/
// data type string, GetString()
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
int getDecimal(int aLetter);

int main(int argc, string argv[])
{
    // Print error if command line option is missing.
    if (argc != 2)
    {
        errorMessage();
        return 1;
    }

    // Get the key from the command line.
    string vigenKey = argv[1];
    int vigenLen = strlen(vigenKey);

    // Check for non alpha characters.
    for (int j = 0; j < vigenLen; j++)
    {
        if (!isalpha(vigenKey[j]))
        {
            errorMessage();
            return 1;
        }
    }

    // Prompt user for a string to encrypt.
    string encryptStr = GetString();
    int keyPosition = 0;
    for (int i = 0; i < strlen(encryptStr); i++)
    {
        // Check for alpha.
        if (isalpha(encryptStr[i]))
        {
            // Check for uppercase.
            if (isupper(encryptStr[i]))
            {
                printf("%c", changeLetter(encryptStr[i], vigenKey[keyPosition], 1));
            }
            // Check for lowercase.
            if (islower(encryptStr[i]))
            {
                printf("%c", changeLetter(encryptStr[i], vigenKey[keyPosition], 0));
            }
            // Check for key position, set to 0 once strlen(vigenKey) is reached.
            if (keyPosition == vigenLen - 1)
            {
                keyPosition = 0;
                /*So.. forgot to add else here
                  which will cause keyPosition to never be 0.*/
            }
            else
            {
                keyPosition++;
            }
            // Print everything else.
        }
        else
        {
            printf("%c", encryptStr[i]);
        }
    }
    free(encryptStr);
    printf("\n");
    return 0;
}
// Convert a letter
int getDecimal(int aLetter)
{
    if (!isalpha(aLetter))
    {
        printf("DEBUG: %c or %c is not alpha!", aLetter, aLetter);
        return 1;
    }
    int cInt;
    if (isupper(aLetter))
    {
        cInt = aLetter - 'A';
    }
    if (islower(aLetter))
    {
        cInt = aLetter - 'a';
    }

    return cInt;
}
// changeLetter function (Taken from my caesar.c).
int changeLetter(int letter, int shiftPos, bool sCase)
{
    int x;
    shiftPos = getDecimal(shiftPos);
    if (sCase)
        // So... Z would be 90
        // (90 - 65 + 5)%26=4
        // 4+65=69 (E)
    {
        x = (letter - 'A' + shiftPos) % 26 + 'A';
    }
    if (!sCase)
    {
        x = (letter - 'a' + shiftPos) % 26 + 'a';
    }
    return x;
}

void errorMessage(void)
{
    printf("Invalid Syntax\nSyntax: vigenere <key> (Alpha chars only)\n");
}

