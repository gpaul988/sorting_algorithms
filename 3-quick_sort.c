#include "sort.h"

/**
* quick_sort – Purpose that arranges a group of integers
* in arising sequence using the Quick sort algorithm
* @array: Group to be arranged
* @size: Nature of group
* Return: empty
*/
void quick_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

quick_s(array, 0, size - 1, size);
}

/**
* partition - Separation
* @array: Group to be arranged
* @lo: Beginning clue of the separation to be arranged
* @hi: Final clue of the separation to be arranged
* @size: Nature of group
* Return: Clue of the pivot constituent after separation
*/
int partition(int *array, int lo, int hi, size_t size)
{
int i = lo - 1, j = lo;
int pivot = array[hi], aux = 0;

for (; j < hi; j++)
{
if (array[j] < pivot)
{
i++;
if (array[i] != array[j])
{
aux = array[i];
array[i] = array[j];
array[j] = aux;
print_array(array, size);
}
}
}
if (array[i + 1] != array[hi])
{
aux = array[i + 1];
array[i + 1] = array[hi];
array[hi] = aux;
print_array(array, size);
}
return (i + 1);
}

/**
* quick_s – Fast arrangement
* @array: Group to be arranged
* @lo: Beginning clue of the separation to be arranged
* @hi: Final clue of the separation to be arranged
* @size: Nature of group
* Return: Empty
*/
void quick_s(int *array, int lo, int hi, size_t size)
{
int pivot;

if (lo < hi)
{
pivot = partition(array, lo, hi, size);
quick_s(array, lo, pivot - 1, size);
quick_s(array, pivot + 1, hi, size);
}
}
