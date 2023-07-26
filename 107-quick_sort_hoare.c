#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Interchange two int
 * @a: First int
 * @b: Secondint
 * Return: (empty) Interchanged int
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * partition - Sperating the group using the Hoare partition scheme
 * @array: Group to be seperated
 * @low: Beginning clue of the seperation
 * @high: Final Clue of the seperation
 * @size: Nature of group
 * Return: Clue of pivote (int)
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j = high;

	while (1)
	{
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;

		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
			i++;
			j--;
		}
		else
		{
			if (i != j)
				return (j);
			return (j - 1);
		}
	}
}
/**
 * hoare_qsort - Arranging repeated groups
 * @array: Groups tobe arranged
 * @low: Beginning clue of the seperation
 * @high: Final clue of the seperation
 * @size: Nature of the group
 * Return: Empty
 */
void hoare_qsort(int *array, int low, int high, size_t size)
{
	int i;

	if (low < high)
	{
		i = partition(array, low, high, size);
		if (i > low)
			hoare_qsort(array, low, i, size);
		hoare_qsort(array, i + 1, high, size);
	}
}
/**
 * quick_sort_hoare - Fast arrangement of  Algorithme using hoare partition
 * @array: Group to be arranged
 * @size: Nature of the group
 * Return: Arrange group (empty)
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	hoare_qsort(array, 0, size - 1, size);
}
