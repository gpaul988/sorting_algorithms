#include "sort.h"

/**
 * shell_sort - Arrange a group of integers in increasing sequence using Shell sort algorithm with Knuth sequence
 * @array: Group to be arrange
 * @size: Nature of the Group
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int tmp;

	if (array == NULL || size < 2)
		return;

	while (gap < size / 3)
		gap = gap * 3 + 1;

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > tmp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}

			array[j] = tmp;
		}

		print_array(array, size);
		gap /= 3;
	}
}
