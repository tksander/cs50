#include <cs50.h>
#include <stdio.h>
#include <sdlib.h>

// prototype
int getAge(void);

int main(int argc, char* argv[]);
{
    /ensure user entered one and only one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./trainer dolphins\n");
        return 1;
    }
    
    // convert input to an integer
    int dolphins = atoi(argv[1]);
    
    // ensure number of dolphins is greater than 0
    if (dolphins < 1)
    {
        printf("Please enter a positive number of dolphoins.\n");
        return 2;
    }
    
    // initialize a new array
    int dolphin_ages[dolphins];
    
    //get ages
    for (int i = 0; i < dolphins; i++)
    {
        dolphins_ages[i] = getAge();
    }
}

    //check number of arguments and > 0 
    if (argv
