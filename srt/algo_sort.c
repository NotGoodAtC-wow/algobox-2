#include "algo_sort.h"
#include "algo_utils.h"

void bubble_sort_int(int* a, size_t n) {
    if (!a || n < 2) return;
    int changed = 1;
    for (size_t pass = 0; pass + 1 < n && changed; ++pass) {
        changed = 0;
        for (size_t i = 0; i + 1 < n - pass; ++i) {
            if (a[i] > a[i+1]) { swap_int(&a[i], &a[i+1]); changed = 1; }
        }
    }
}

void insertion_sort_int(int* a, size_t n) {
    if (!a || n < 2) return;
    for (size_t i = 1; i < n; ++i) {
        int key = a[i];
        size_t j = i;
        while (j > 0 && a[j-1] > key) {
            a[j] = a[j-1];
            --j;
        }
        a[j] = key;
    }
}

void selection_sort_int(int* a, size_t n) {
    if (!a || n < 2) return;
    for (size_t i = 0; i + 1 < n; ++i) {
        size_t minj = i;
        for (size_t j = i + 1; j < n; ++j)
            if (a[j] < a[minj]) minj = j;
        swap_int(&a[i], &a[minj]);
    }
}
