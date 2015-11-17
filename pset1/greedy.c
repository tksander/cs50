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

int counter = 0;
float change; 

do
{
    printf("How much change do I owe ya?\n"); 
    change = GetFloat(); 
}
while (change < 0 );

// convert change to integer
int cents = round(change*100);

    
int quarter = 25, dime = 10, nickel = 05, penny = 01;

while (cents >= quarter)
{
counter++;
cents = cents - 25;
} 

while (cents >= dime)
{
counter++;
cents = cents - 10;
} 

while (cents >= nickel)
{
counter++;
cents = cents - 5;
} 

while (cents >= penny)
{
counter++;
cents = cents - 1;
} 

    printf("%d\n", counter);           
}

