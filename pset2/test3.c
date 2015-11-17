/**
 * vignere.c
 *
 * Tommy Sander
 * tksander@usc.edu
 *
 * encodes strings per Vigenere's Ciper
 */

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// declares array function
int main(int argc, string argv[])
{
    // !!Check if argv statement is correct
    if (argc != 2)
    {
        printf("Please provide an one word command line argument\n");
        return 1;   
    }
    
    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
        return 1;
        }
        printf("%c\n", argv[1][i]);
    }
    printf("hello\n");
}
