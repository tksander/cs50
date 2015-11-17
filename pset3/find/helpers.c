/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <stdio.h>       
#include <cs50.h>
#include <string.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int beginning = 0;
    int ending = n -1;
    // while length of list > 0
    while (ending >= beginning)
    {
        // look at middle of list
        int middle = (beginning + ending) / 2;
        // if number , return true
        if (values[middle] == value)
        {
            return true;
        }
        // else if number higher, search left
        else if (values[middle] > value)
        {
            ending = middle -1;
        }
        // else number lower, search right
        else
        {
            beginning = middle + 1;
        }
     }   
    // return false
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // while the list is out of order
    for (int i = 0; i < n; i++)
    {    
        int smallest_index = i;
    
        // go through the entie list 
        for (int j = i + 1; j < n; j++)
        {
            // find the smallest number
            if (values[j] < values[smallest_index])
            {
                smallest_index = j;
             }
        }
        
         // put the beginning of the list where the smallest number was
         int temp = values[smallest_index];
         
         // assign beginning of list number to where the smallest number was
        values[smallest_index] = values[i];
        
        // assign temp value(smallest number) to beginning of list 
        values[i] = temp;
        printf("Array value #%d: %d\n", i, values[i]);
   }
}


