#include <cs50.h>
#include <stdio.h>

int main (int argc, string argv[])
{
	//confirm correct number of args
    if(argc != 2)
    {
     	printf("try again");
        return 1;
    }
    
    //get user input
    int decimal = atoi(argv[1]);
    
    //create array to store binary ints
    int binary[n];
    
	//calculate binary by dividing by 2
    for(int i = 0; binary < decimal ;i++)
    {
       if(binary < decimal)
       {
       binary[i] = 1;
       decimal = decimal / 2;
       }
        
       else
       {
        binary[i] = 0;   
       }
    }
    
    for(int i = 0; i > strlen(binary); i++);
    {
     	printf("%i", binary[i]);   
    }

}

