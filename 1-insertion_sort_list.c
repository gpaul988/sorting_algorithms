#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Arrange dual linked list of integers in increasing sequence using Insertion sort
 * @list: Indicator to the Indicator of the list
 */
void insertion_sort_list(listint_t **list)
{
        if (list == NULL || *list == NULL || (*list)->next == NULL)
                return;

        listint_t *current;
        current = (*list)->next;

        while (current != NULL)
        {
                listint_t *temp = current;

                while (temp->prev != NULL && temp->n < temp->prev->n)
                {
                        /* Change sub and sub->prev nodes */
                        if (temp->next != NULL)
                                temp->next->prev = temp->prev;
                        temp->prev->next = temp->next;
                        temp->next = temp->prev;
                        temp->prev = temp->prev->prev;
                        temp->next->prev = temp;

                        if (temp->prev == NULL)
                                *list = temp;
                        else
                                temp->prev->next = temp;

                        print_list(*list);
                }
                current = current->next;
        }
}
