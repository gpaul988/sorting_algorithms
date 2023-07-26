#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - Arrange an array of integers in increasing
 * sequence using Bubble sort
 *
 * @array: Group to be arranged
 * @size: Size of the Group
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* Change group[j] and group[j + 1] */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;

				print_array(array, size);
			}
		}

		/**
		 * No two component were changed in the inner
		 * loop, the array is already sorted
		 */
		if (swapped == 0)
			break;
	}
}
