#include "algo_search.h"

int linear_search_int(const int* a, size_t n, int key) {
    if (!a) return -1;
    for (size_t i = 0; i < n; ++i)
        if (a[i] == key) return (int)i;
    return -1;
}

int binary_search_int(const int* a, size_t n, int key) {
    if (!a) return -1;
    int lo = 0, hi = (int)n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        int v = a[mid];
        if (v == key) return mid;
        if (v < key) lo = mid + 1; else hi = mid - 1;
    }
    return -1;
}
