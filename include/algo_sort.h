#ifndef ALGO_SORT_H
#define ALGO_SORT_H

#include <stddef.h>

/* stable-ish O(n^2) basics */
void bubble_sort_int(int* a, size_t n);
void insertion_sort_int(int* a, size_t n);
void selection_sort_int(int* a, size_t n);

/* Advanced(v2) */
void quick_sort_int(int* a, size_t n);
void merge_sort_int(int* a, size_t n);
void heap_sort_int(int* a, size_t n);
static void sift_down(int* a, size_t n, size_t i);

#endif /* ALGO_SORT_H */
