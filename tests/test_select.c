#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "algo_select.h"

/* Хелпер: сравнить с отсортированной копией */
static void check_kth(const int* src, size_t n) {
    size_t k;
    int* a = (int*)malloc(n * sizeof(int));
    int* b = (int*)malloc(n * sizeof(int));
    size_t i, j;

    assert(a && b);
    memcpy(a, src, n * sizeof(int));
    memcpy(b, src, n * sizeof(int));

    /* простейшая сортировка b ради эталона (insertion) */
    for (i = 1; i < n; ++i) {
        int x = b[i];
        j = i;
        while (j > 0 && b[j-1] > x) {
            b[j] = b[j-1];
            --j;
        }
        b[j] = x;
    }

    for (k = 0; k < n; ++k) {
        memcpy(a, src, n * sizeof(int));
        assert(kth_smallest_int(a, n, k) == b[k]);
    }

    free(a);
    free(b);
}

int main(void) {
    static const int in1[] = {5, 1, 4, 3, 2};
    static const int in2[] = {3, 3, 3, 3};
    static const int in3[] = {10, -1, 7, 0, 5, -2, 10};

    check_kth(in1, sizeof(in1)/sizeof(in1[0]));
    check_kth(in2, sizeof(in2)/sizeof(in2[0]));
    check_kth(in3, sizeof(in3)/sizeof(in3[0]));
    return 0;
}
