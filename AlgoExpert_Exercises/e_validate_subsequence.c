/* Given two non-empty arrays of integers, write a function that determines whether the second array is a subsequence of the first one. */
/* A subsequence of an array is a set of numbers that aren't necessaryly adjacent in the array but that are in the same order as they appear in the array. */.
/* [1, 3, 4] form a subsequence of the array [1, 2, 3, 4] */

#include <stdio.h>
#include <stdbool.h>

int main()
{
    int array[] = {5, 1, 22, 25, 6, -1, 8, 10};
    int sequence[] = {1, 6, -1, 10};
    
    bool is_sequence = false;
    /* Calculate the size of the array */
    int array_size = sizeof(array) / sizeof(array[0]);
    /* Pointer variable used to iterate over the sequence */
    int* sequence_cursor = sequence;
    /* Get the last element of the sequence: calculate the size of the sequence and substract one */
    int last_sequence_element_index = (sizeof(sequence) / sizeof(sequence[0])) - 1;
    /* Variable to point to the last element of the sequence */
    int* last_sequence_element = sequence + last_sequence_element_index;
    
    /* See if there is the same address (last element of the array - last sequence element */
    //printf("%p\n", &sequence[3]);
    //printf("%p\n", last_sequence_element);
    //printf("%d", *last_sequence_element);

    /* Iterate over the array -> everytime an element of the sequence is found increment the pointer */
    
    for(int element  = 0; element < array_size; element++)
    {
        if(sequence_cursor == last_sequence_element)
        {
            printf("The sequence is part of the array. \n");
            is_sequence = true;
            break;
        }
        if(*sequence_cursor == array[element])
        {
            sequence_cursor += 1;
        }
    }
    
    if(!is_sequence)
    {
        printf("The sequence is not part of the array!");
    }

    return 0;
}