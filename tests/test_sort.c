#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "algo_sort.h"
#include "algo_utils.h"

typedef void (*sort_fn)(int*, size_t);

static void run_case_named(const char* name, sort_fn f,
                           const int* in, size_t n, const int* exp) {
    size_t i;
    int* a = (int*)malloc(n * sizeof(int));
    assert(a != NULL);
    for (i = 0; i < n; ++i) a[i] = in[i];

    f(a, n);

    for (i = 0; i < n; ++i) {
        if (a[i] != exp[i]) {
            fprintf(stderr, "[%s] mismatch at i=%zu: got=%d, exp=%d\n",
                    name, i, a[i], exp[i]);
            assert(0 && "sorted array mismatch");
        }
    }
    free(a);
}

#define RUN_ALL(name,in,n,exp) do { \
run_case_named("bubble_"   name, bubble_sort_int,    (in), (n), (exp)); \
run_case_named("insertion_"name, insertion_sort_int, (in), (n), (exp)); \
run_case_named("selection_"name, selection_sort_int, (in), (n), (exp)); \
run_case_named("quick_"    name, quick_sort_int,     (in), (n), (exp)); \
run_case_named("merge_"    name, merge_sort_int,     (in), (n), (exp)); \
run_case_named("heap_"     name, heap_sort_int,      (in), (n), (exp)); \
} while (0)

int main(void) {
    /* кейс 1 */
    static const int in1[]  = {5, 4, 3, 2, 1};
    static const int exp1[] = {1, 2, 3, 4, 5};
    const size_t n1 = sizeof(in1) / sizeof(in1[0]);

    /* кейс 2 (исправлено: 8 элементов, добавлена 3) */
    static const int in2[]  = {3, 1, 2, 2, 5, 4, 4, 0};
    static const int exp2[] = {0, 1, 2, 2, 3, 4, 4, 5};
    const size_t n2 = sizeof(in2) / sizeof(in2[0]);

    RUN_ALL("case1", in1, n1, exp1);
    RUN_ALL("case2", in2, n2, exp2);

    return 0;
}
