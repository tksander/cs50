/**
 * caesar.c
 *
 * Tommy Sander
 * tksander@usc.edu
 *
 * encodes strings
 */

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// declares array function
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
        
    // names command line argument k
    // string k = argv [1];

    // stores k as an int
    int k = atoi(argv[1]);
    
    //encodes string
    string s = GetString();
   
   // encodes chars
   for (int i = 0, length = strlen(s); i < length; i++)
   {
       if (isalpha(s[i]))
       {
            if (isupper(s[i]))
            {
                printf("%c", (((s[i] + k) - 'A') % 26) + 'A'); 
            }
            if (islower(s[i]))
            {
                printf("%c", (((s[i] + k) - 'a') % 26) + 'a'); 
            }
       }
       else 
       {
           printf("%c", s[i]);
       }
    }

   printf("\n");
 
 return 0;
 }  
 
