#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <time.h>

#define NUMBER 5

int main(void)
{
    // ask the user for fives names
    string names[NUMBER];
    for (int i = 0; i < NUMBER; i++)
    {
        printf("Name %d\n", i + 1);
        names[i] = GetString();
    }
    
    printf("Please type 5 names\n");
    
    //
    srand(time(NULL));
    int name = rand() % NUMBER;
    printf("%s\n", names[name]);
}    
    
