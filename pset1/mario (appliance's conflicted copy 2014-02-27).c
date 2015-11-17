//Builds a pyramid from a user input number
#include <stdio.h>
#include <cs50.h>

int main (void)
{

 int height;
 /*The loop executes the printf and Getint function, then evaluate if the number is outside
 the bounds. If it's inside the bounds the loop exits and retains the value in height.*/
  do
  {
   printf ("In order to build a half pyramid, please type a number between 0 and 23\n");
   height = GetInt();
    }
  while (height>23 || height<0);
  //use If, then, else statement for the 
  //Maybe use a boolean expression using "if (condition && condition)"
  
  for (int i=0; i < height; i++)
  {
  //print spaces
   printf (" ");
  //print hashes
   printf ("#");
  //print new line
   printf ("/n");
  }
  //code outside  
 }
 
