#include "sort.h"

/**
 * heapify - Generates the highest stacak from a group
 * @array: Group to heapify
 * @size: Nature of Group
 * @index: Clue to begin heapifying from
 */
void heapify(int *array, size_t size, int index)
{
	int largest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;

	if (left < (int)size && array[left] > array[largest])
		largest = left;

	if (right < (int)size && array[right] > array[largest])
		largest = right;

	if (largest != index)
	{
		int temp = array[index];
		array[index] = array[largest];
		array[largest] = temp;
		print_array(array, size);
		heapify(array, size, largest);
	}
}

/**
 * heap_sort - Arrange a group of integers in increasing sequence using stack sort
 * @array: Group to arrange
 * @size: NAture of the group
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;

	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i);

	for (i = size - 1; i > 0; i--)
	{
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		print_array(array, size);
		heapify(array, i, 0);
	}
}
