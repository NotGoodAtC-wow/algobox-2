#ifndef ALGO_SEARCH_H
#define ALGO_SEARCH_H

#include <stddef.h>

/* returns index or -1 */
int linear_search_int(const int* a, size_t n, int key);
/* a must be sorted ascending; returns index or -1 */
int binary_search_int(const int* a, size_t n, int key);

#endif /* ALGO_SEARCH_H */
