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
int aux = 0;
size_t i = 0, j = 0, pos = 0;

if (array == NULL || size == 0)
return;

for (; i < size - 1; i++)
{
pos = i;
for (j = i + 1; j < size; j++)
{
if (array[j] < array[pos])
pos = j;
}
if (pos != i)
{
aux = array[i];
array[i] = array[pos];
array[pos] = aux;
print_array(array, size);
}
}
}
