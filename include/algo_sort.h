#ifndef ALGO_SORT_H
#define ALGO_SORT_H

#include <stddef.h>

/* stable-ish O(n^2) basics for учебной версии */
void bubble_sort_int(int* a, size_t n);
void insertion_sort_int(int* a, size_t n);
void selection_sort_int(int* a, size_t n);

#endif /* ALGO_SORT_H */
