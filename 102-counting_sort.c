#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Arrange a group of integers in increasing sequence using Counting sort
 * @array: Group to be arranged
 * @size: Nature of the Group
 */
void counting_sort(int *array, size_t size)
{
	int *count = NULL, *output = NULL;
	int max_value = 0;
	size_t i;

	/* Locate the highest worth in the group */
	for (i = 0; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	/* Generate a computed group with size = max_value + 1 */
	count = malloc((max_value + 1) * sizeof(int));
	if (count == NULL)
		return;

	/* Boot the computed group with 0 */
	for (i = 0; i <= (size_t)max_value; i++)
		count[i] = 0;

	/* Compute the occurance of every element */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Modernise the computed group to save the increasing occurane */
	for (i = 1; i <= (size_t)max_value; i++)
		count[i] += count[i - 1];

	/* Generate the product grouop */
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}

	/* Generate the product group construct on the computed group */
	for (i = size - 1; i != (size_t)(-1); i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	/* Mimic the arranged constituent back to default group */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	/* Allow the assigned memory */
	free(count);
	free(output);

	/* Pull the computed group */
	printf("%d", count[0]);
	for (i = 1; i <= (size_t)max_value; i++)
		printf(", %d", count[i]);
	printf("\n");
}