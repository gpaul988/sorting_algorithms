#include "sort.h"

/**
 * swap - Interchange two integers
 * @a: Indiacator to first integer
 * @b: Indiacator to second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Seperated scheme for quicksort
 * @array: Group to be arranged
 * @low: Beginning clue of the seperation to be arranged
 * @high: Final clue of the seperation to be arranged
 * @size: Nature of the group
 *
 * Return: Clue of the pivot constituent after seperation
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quicksort - Repeated purpose to arrange a group using quicksort
 * @array: Group to be arranged
 * @low: Beginning clue of the seperated to be arranged
 * @high: Final clue of the seperated to be arranged
 * @size: Nature of the group
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int partition;

	if (low < high)
	{
		partition = lomuto_partition(array, low, high, size);
		quicksort(array, low, partition - 1, size);
		quicksort(array, partition + 1, high, size);
	}
}

/**
 * quick_sort - Arrange a group of integers in increasing
 * sequence using Quick sort algorithm
 *
 * @array: Group to be arranged
 * @size: Nature of the group
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
