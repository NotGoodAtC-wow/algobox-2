#include <assert.h>
#include "algo_search.h"

int main(void) {
    const int a[] = {-3, -1, 0, 1, 3, 7, 9, 12};
    const int n = (int)(sizeof(a)/sizeof(a[0]));

    /* linear */
    assert(linear_search_int(a, n, 7) >= 0);
    assert(linear_search_int(a, n, 100) == -1);

    /* binary (массив отсортирован по возрастанию) */
    int i = binary_search_int(a, n, 7);
    assert(i >= 0 && a[i] == 7);

    assert(binary_search_int(a, n, -3) == 0);
    assert(binary_search_int(a, n, 2) == -1);

    return 0;
}
