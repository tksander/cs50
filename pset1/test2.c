/** 
* greedy.c
*
* Tommy Sander
* tksander@usc.edu
* Determines change owed in coins 
*
*/
#include <math.h>
#include <stdio.h>
#include <cs50.h>

int main(void)
{

/**
* Asks for change owed
*/

//int counter = 0;
float change; 

do
{
    printf("How much change do I owe ya?\n"); 
    change = GetFloat(); 
}
while (change < 0 );

// convert change to integer
int cents = round(change*100);




    printf("%d\n",cents);
    
}    
