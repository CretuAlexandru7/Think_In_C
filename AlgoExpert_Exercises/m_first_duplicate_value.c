/* Given an array of integers (with maximum value = 100) -> write a function that returns the first integer that appears more than once) */

#include <stdio.h>
#include <stdbool.h>


int findDuplicateNo(int* array, int size)
{
    /* 99 possible values */
    /* Idea of map */
    int hashArray[99] = {0};
    
    for(int i = 0; i < size; i++)
    {
        if(hashArray[array[i]] != 0)
        {
            return array[i];
        }
        
        hashArray[array[i]]++;
    }
    
    /* If no duplicates have been found -> return -1 */
    return -1;
}


int main()
{
    int test_array[] = {1, 22, 43, 2, 8, 43, 92, 11};
    int array_size = sizeof(test_array) / sizeof(test_array[0]);
   
    int duplicated_elem = findDuplicateNo(test_array, array_size);
    
    if (duplicated_elem != -1) {
        printf("First duplicate value: %d\n", duplicated_elem);
    } else {
        printf("No duplicates found.\n");
    }
    
    return 0;
}
