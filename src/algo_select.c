#include "algo_select.h"
#include <assert.h>

static void iswap(int* a, size_t i, size_t j) {
    int t = a[i]; a[i] = a[j]; a[j] = t;
}

int kth_smallest_int(int* a, size_t n, size_t k) {
    size_t L = 0, R = (n == 0) ? 0 : (n - 1);
    int pivot;
    size_t i, j;

    assert(a != NULL);
    assert(k < n);

    for (;;) {
        pivot = a[L + (R - L) / 2];
        i = L;
        j = R;

        while (i <= j) {
            while (a[i] < pivot) ++i;
            while (a[j] > pivot) {
                if (j == 0) break;
                --j;
            }
            if (i <= j) {
                iswap(a, i, j);
                ++i;
                if (j > 0) --j;
            }
        }

        if (j >= k) {
            if (j == 0) break;
            R = j;
        } else if (i <= k) {
            L = i;
        } else {
            /* pivot range покрывает k */
            break;
        }
        if (L >= R) break;
    }
    return a[k];
}
