#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[])
{   
    // (two and only two command line arguments)
    if (argc!= 3)
        return 1;
    // print out a greeting to the user that includes their first name
    printf("Hello %s\n", argv[1]);
    
}
