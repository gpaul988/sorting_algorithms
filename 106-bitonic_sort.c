#include "sort.h"
#include <stdio.h>

/**
 * bitonic_compare - COntrast two elements based on the given command
 * @array: Group holding the elements
 * @idx1: Clue of the first element
 * @idx2: Clue of the second element
 * @dir: Command (1 increasing, 0 reducing)
 */
void bitonic_compare(int *array, size_t idx1, size_t idx2, int dir)
{
	if ((array[idx1] > array[idx2] && dir) || (array[idx1] < array[idx2] && !dir))
	{
		int temp = array[idx1];

		array[idx1] = array[idx2];
		array[idx2] = temp;
	}
}

/**
 * bitonic_merge - Joins two tempgroup into a bitonic sequence
 * @array: Group to be arranged
 * @start: Beginningi of clue of tempgroup
 * @size: Nature of tempgroup
 * @dir: Command (1 increasing, 0 reducing)
 */
void bitonic_merge(int *array, size_t start, size_t size, int dir)
{
	size_t i;

	if (size > 1)
	{
		size_t mid = size / 2;

		for (i = start; i < start + mid; i++)
			bitonic_compare(array, i, i + mid, dir);
		bitonic_merge(array, start, mid, dir);
		bitonic_merge(array, start + mid, mid, dir);
	}
}

/**
 * bitonic_sort_recursive - Repeated group of a bitonic sequence
 * @array: Group to be arranged
 * @start: beginning of clue of the sequence
 * @size: Nature of the sequence
 * @dir: Command (1 Increasing, 0 reducing)
 */
void bitonic_sort_recursive(int *array, size_t start, size_t size, int dir)
{
	if (size > 1)
	{
		size_t mid = size / 2;

		printf("Merging [%lu/%lu] (%s):\n", size, size * 2, (dir ? "UP" : "DOWN"));
		print_array(array + start, size);

		bitonic_sort_recursive(array, start, mid, 1);
		bitonic_sort_recursive(array, start + mid, mid, 0);
		bitonic_merge(array, start, size, dir);

		printf("Result [%lu/%lu] (%s):\n", size, size * 2, (dir ? "UP" : "DOWN"));
		print_array(array + start, size);
	}
}

/**
 * bitonic_sort - Arrange a group of integers in increasing
 * sequence using bitonic sort
 *
 * @array: Group to be arranged
 * @size: Nature of the group
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, 1);
}
