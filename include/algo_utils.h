#ifndef ALGO_UTILS_H
#define ALGO_UTILS_H

#include <stddef.h>
#include <stdio.h>

/* swap two ints (safe for a==b) */
static inline void swap_int(int* a, int* b) {
    if (!a || !b || a == b) return;
    int t = *a; *a = *b; *b = t;
}

/* print array in one line: "x0 x1 ... xn-1\n" to out (stdout if out==NULL) */
static inline void print_array_int(const int* a, size_t n, FILE* out) {
    if (!a) return;
    if (!out) out = stdout;
    for (size_t i = 0; i < n; ++i) {
        fprintf(out, "%d", a[i]);
        if (i + 1 < n) fputc(' ', out);
    }
    fputc('\n', out);
}

/* return 1 if non-decreasing (ascending with equals allowed), else 0 */
static inline int is_sorted_int(const int* a, size_t n) {
    if (!a) return 0;
    for (size_t i = 1; i < n; ++i)
        if (a[i-1] > a[i]) return 0;
    return 1;
}

/* qsort comparator for ints (ascending) */
static inline int cmp_int_asc(const void* x, const void* y) {
    int a = *(const int*)x, b = *(const int*)y;
    return (a > b) - (a < b);
}

#endif /* ALGO_UTILS_H */
