#include "sort.h"

/**
 * swap - Interchange elements of a group
 *
 * @xp: Indicator to element to be interchanged
 * @yp: Indicator to element to be interchanged
 */
void swap(int *xp, int *yp)
{
	int temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/**
 * selection_sort - Arrange group of integers in increasing order using
 * the selection sort algorithm
 *
 * @array: Group to be arranged
 * @size: Nature of the group
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx == i)
			continue;
		swap(&array[min_idx], &array[i]);
		print_array(array, size);
	}
}
