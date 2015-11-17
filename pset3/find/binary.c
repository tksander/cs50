/**
* Week 3 section
* Spring 2014
*
* interative binary search implementation
*/

#include <stdbool.h>

bool binary_search(int value, int values[], int n)
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
