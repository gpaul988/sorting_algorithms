#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/* Data structures */
/**
 * struct listint_s - Dual connected list node shape
 *
 * @n: Integer saved in the node
 * @prev: Indicator to the last element of the list
 * @next: Indicator to the following element of the list
 */
typedef struct listint_s
{
    int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Purpose prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Arranging algorithms */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);
void print_array(const int *array, size_t size);

#endif /* SORT_H */
