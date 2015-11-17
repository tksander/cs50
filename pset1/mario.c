/** 
* mario.c
*
* Tommy Sander
* tksander@usc.edu
* Builds a pyramid from a user input number 
*
*/

#include <stdio.h>
#include <cs50.h>

// remember to change directory with cd, and list with ls

int main (void)
{

    /** 
    * executes printf & Getint function 
    * evaluates if  number's outside bounds
    * If inside the bounds, loop exits, retains value of height
    */

 int height;
 do
 {
    printf("In order to build a half pyramid, please type a number between 0 and 23\n");
    height = GetInt();
 }
 while (height > 23 || height < 0); 
  
  /**
  * prints hashes to height of input
  */
  for (int n=0; n < height; n++)
  {
    /**
    * prints spaces
    */
    for (int a=0; a < height-(n+1); a++)  
    {
        printf(" ");
    }  
    /**
    * prints hash marks
    */
    for (int b=0; b < n+2; b++)
    {
        printf ("#");
    }
   printf("\n");
  
  }
 }
 
