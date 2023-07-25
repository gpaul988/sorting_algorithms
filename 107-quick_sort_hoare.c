#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Interchange two integers in a group
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * partition_hoare - Sperating the group using the Hoare partition scheme
 * @array: Group to be seperated
 * @low: BEginning clue of the seperation
 * @high: Final clue of the seperation
 * @size: Nature of group
 *
 * Return: Clue of the pivot element
 */
int partition_hoare(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j = high + 1;

	while (1)
	{
		do
		{
			i++;
		} while (array[i] < pivot);

		do
		{
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (j);

		swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * quicksort_hoare - Apply the Quick sort algorithm using Hoare partition scheme
 * @array: Group tobe arranged
 * @low: Beginning clue of the seperation
 * @high: Final clue of the sepeartion
 * @size: Nature of group
 */
void quicksort_hoare(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition_hoare(array, low, high, size);
		quicksort_hoare(array, low, pivot, size);
		quicksort_hoare(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Arrange a group of integers in increasing sequence using the
 * Quick sort algorithm (Hoare partition scheme)
 * @array: Group to be arranged
 * @size: NAture of group
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_hoare(array, 0, size - 1, size);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	printf("\n");
	quick_sort_hoare(array, n);
	printf("\n");
	print_array(array, n);
	return (0);
}
