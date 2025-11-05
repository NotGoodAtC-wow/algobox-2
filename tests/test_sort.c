#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "algo_sort.h"
#include "algo_utils.h"

static int same_multiset(const int* a, const int* b, size_t n) {
    int* c = (int*)malloc(n * sizeof(int));
    int* d = (int*)malloc(n * sizeof(int));
    if (!c || !d) { free(c); free(d); return 0; }
    for (size_t i = 0; i < n; ++i) { c[i] = a[i]; d[i] = b[i]; }
    qsort(c, n, sizeof(int), cmp_int_asc);
    qsort(d, n, sizeof(int), cmp_int_asc);
    int ok = (memcmp(c, d, n * sizeof(int)) == 0);
    free(c); free(d);
    return ok;
}

static void run_one(int (*sort_fn)(void), const char* /*unused*/) { (void)sort_fn; }
static void apply_and_check(void (*sortf)(int*, size_t),
                            const int* src, size_t n) {
    int* a = (int*)malloc(n * sizeof(int));
    int* b = (int*)malloc(n * sizeof(int));
    assert(a && b);
    for (size_t i = 0; i < n; ++i) { a[i] = src[i]; b[i] = src[i]; }
    qsort(b, n, sizeof(int), cmp_int_asc);

    sortf(a, n);
    assert(is_sorted_int(a, n));
    assert(same_multiset(a, b, n));

    free(a); free(b);
}

static void test_all_on(const int* src, size_t n) {
    apply_and_check(bubble_sort_int,    src, n);
    apply_and_check(insertion_sort_int, src, n);
    apply_and_check(selection_sort_int, src, n);
    apply_and_check(quick_sort_int,     src, n);
    apply_and_check(merge_sort_int,     src, n);
    apply_and_check(heap_sort_int,      src, n);
}

int main(void) {
    {
        const int a[] = {5,1,4,2,8,3,3,-1,0,42,-7,8,8,8,2};
        test_all_on(a, sizeof(a)/sizeof(a[0]));
    }
    {
        const int a[] = {1,1,1,1,1,1,1};
        test_all_on(a, sizeof(a)/sizeof(a[0]));
    }
    {
        const int a[] = {-10,-5,-5,-5,-1,0,2,2,3,1000};
        test_all_on(a, sizeof(a)/sizeof(a[0]));
    }
    {
        const int a[] = {9,8,7,6,5,4,3,2,1,0};
        test_all_on(a, sizeof(a)/sizeof(a[0]));
    }
    {
        const int a[] = {2};
        test_all_on(a, 1);
    }
    {
        const int a[] = {3,2};
        test_all_on(a, 2);
    }
    return 0;
}
