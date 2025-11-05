#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "algo_sort.h"

static void check_counting(const int* src, size_t n, int maxv, const int* exp) {
    size_t i;
    int* a = (int*)malloc(n * sizeof(int));
    assert(a);
    memcpy(a, src, n * sizeof(int));

    counting_sort_int_nonneg(a, n, maxv);

    for (i = 0; i < n; ++i) {
        assert(a[i] == exp[i]);
    }
    free(a);
}

int main(void) {
    /* кейс 1 */
    static const int in1[]  = {3, 1, 0, 2, 2, 1};
    static const int exp1[] = {0, 1, 1, 2, 2, 3};

    /* кейс 2 (много повторов) */
    static const int in2[]  = {0,0,0,1,1,2,2,2,3};
    static const int exp2[] = {0,0,0,1,1,2,2,2,3};

    /* кейс 3 (максимум на краю) */
    static const int in3[]  = {5,0,5,1,4,3,2};
    static const int exp3[] = {0,1,2,3,4,5,5};

    check_counting(in1, sizeof(in1)/sizeof(in1[0]), 3, exp1);
    check_counting(in2, sizeof(in2)/sizeof(in2[0]), 3, exp2);
    check_counting(in3, sizeof(in3)/sizeof(in3[0]), 5, exp3);
    return 0;
}
