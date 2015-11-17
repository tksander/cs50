/**
*
*
* Week 3 section
* 
* selection sort implementation
*/

void selection_sort(int values[], int n)
{
    // while the list is out of order
    for (int i = 0; i < n; i++)
    {
        int smallest = values[i];
        int smallest_location = i;
    // go throuhgh the entie list 
        for (int j = i + 1; j < n; j++)
        {
        // find the smallest number
        if (smallest > values[j])
        {
            smallest = values[j];
            smallest_location = j;
        }
         // put the beginning of the list where the smallest number was
        values[smallest_location] = values[i];
        
        // place it in the beginning of the list
        values[i] = smallest;
        }
   }
}
