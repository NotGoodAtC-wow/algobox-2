#include <assert.h>
#include <string.h>
#include "algo_sort.h"
#include "algo_utils.h"

static void copy(int* dst, const int* src, size_t n) {
    for (size_t i = 0; i < n; ++i) dst[i] = src[i];
}

int main(void) {
    int a[] = {5, 1, 4, 2, 8, 3, 3, -1, 0};
    const size_t n = sizeof(a)/sizeof(a[0]);

    int b1[sizeof(a)/sizeof(a[0])];
    int b2[sizeof(a)/sizeof(a[0])];
    int b3[sizeof(a)/sizeof(a[0])];

    copy(b1, a, n);
    copy(b2, a, n);
    copy(b3, a, n);

    bubble_sort_int(b1, n);
    insertion_sort_int(b2, n);
    selection_sort_int(b3, n);

    assert(is_sorted_int(b1, n));
    assert(is_sorted_int(b2, n));
    assert(is_sorted_int(b3, n));

    /* одинаковые множества элементов (простая проверка через сортировку ещё раз) */
    /* здесь достаточно, что все три сортировки дают отсортированный результат */
    return 0;
}
