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
    }
    // stores k as an int
    //int k = atoi(argv[1]);
    
    //gets string to encode
    string s = GetString();
   
   
   // iterates through string to encode
   for (int i = 0, length = strlen(s); i < length; i++)
   {
       // iterates through encyption string   
       for (int j = 0, length = strlen(argv[1]); (j % length) < length; j++) 
           // checks or alpha
           if (isalpha(s[i]))
           {
                // checks for uppercase
                if (isupper(s[i]))
                {
                    printf("%c", (((s[i] + (argv[1][j]- 'A')) - 'A') % 26) + 'A');
                    break; 
                // checks for lowercase
                }
                if (islower(s[i]))
                {

                    printf("%c", (((s[i] + (argv[1][j] - 'a')) - 'a') % 26) + 'a'); 
                    break;
                }
           }
       // prints non-alpha chars    
       else 
       {
           j--;
           printf("%c", s[i]);
           break;
       }
    }

   printf("\n");
 
 return 0;
 }  
 
