#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // ask for a string from the user
    printf("Please give me a string!\n");
    string s = GetString();
    
    //print out each character on a new line
    for (int i = 0, length = strlen(s); i < length; i++)
    {
    printf("%c\n", s[i]);
    }
}
