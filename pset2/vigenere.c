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
        printf("Please provide a one word command line argument\n");
        return 1;   
    }
    
    for (int i = 0, length = strlen(argv[1]); i < length; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
        printf("Please provide only alphabetical characters\n");
        return 1;
        }
    }
    // stores argv as an int
    // for(int k[i], length = strlen(argv[1]); i < length; i++)
    // int k[i] = atoi(argv[1]);
    
    //gets string to encode
    string plaintxt = GetString();
    
   // assigns strlen of encryption string to 'keylength'
   int keylength = strlen(argv[1]);
   
   // iterates through string to encode
   for (int i = 0, key = 0, length = strlen(plaintxt); i < length ; i++)
   {
           // checks plaintext for alpha chars
           if (isalpha(plaintxt[i]))
           {
                // checks plaintextfor uppercase
                if (isupper(plaintxt[i]))
                {
                
                    // checks key for upper case
                    if (isupper(argv[1][key % keylength]))
                    {
                    printf("%c", (((plaintxt[i] + (argv[1][key % keylength]- 'A')) - 'A') % 26) + 'A');
                    key++;
                    }
                    
                    // key for lower case
                    else
                    {
                    printf("%c", (((plaintxt[i] + (argv[1][key % keylength]- 'a')) - 'A') % 26) + 'A');
                    key++;
                    }
                }
                
                // checks plaintext for lowercase
                if (islower(plaintxt[i]))
                {
                
                    // checks key for upper case
                    if (isupper(argv[1][key % keylength]))
                    {
                    printf("%c", (((plaintxt[i] + (argv[1][key % keylength]- 'A')) - 'a') % 26) + 'a');
                    key++;
                    }
                    
                    // key for lower case
                    else
                    {
                    printf("%c", (((plaintxt[i] + (argv[1][key % keylength]- 'a')) - 'a') % 26) + 'a');
                    key++;
                    }
                }
           }
           
       // prints non-alpha chars    
       else 
       {
           printf("%c", plaintxt[i]);
       }
    }

   printf("\n");
 
 return 0;
 }  
 
