#include "algo_sort.h"
#include "algo_utils.h"
#include <stdlib.h> /* malloc, free */
#include <assert.h>

/* -------------------- Basic -------------------- */
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

/* -------------------- ADVANCED: QUICKSORT -------------------- */

#define QS_THRESH 16

static void quick_rec(int* a, int L, int R) {
    while (R - L + 1 > QS_THRESH) {
        int i = L, j = R;
        int pivot = a[L + (R - L) / 2];

        while (i <= j) {
            while (a[i] < pivot) ++i;
            while (a[j] > pivot) --j;
            if (i <= j) {
                swap_int(&a[i], &a[j]);
                ++i; --j;
            }
        }
        if (j - L < R - i) {
            if (L < j) quick_rec(a, L, j);
            L = i;
        } else {
            if (i < R) quick_rec(a, i, R);
            R = j;
        }
    }
}

void quick_sort_int(int* a, size_t n) {
    if (!a || n < 2) return;
    quick_rec(a, 0, (int)n - 1);
    insertion_sort_int(a, n);
}

/* -------------------- ADVANCED: MERGESORT -------------------- */

static void merge_run(int* a, int* tmp, int L, int mid, int R) {
    int i = L, j = mid + 1, k = L;
    while (i <= mid && j <= R) {
        if (a[i] <= a[j]) tmp[k++] = a[i++];
        else              tmp[k++] = a[j++];
    }
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= R)   tmp[k++] = a[j++];
    for (int t = L; t <= R; ++t) a[t] = tmp[t];
}

static void merge_rec(int* a, int* tmp, int L, int R) {
    if (R - L + 1 <= QS_THRESH) return;
    int mid = L + (R - L) / 2;
    merge_rec(a, tmp, L, mid);
    merge_rec(a, tmp, mid + 1, R);
    if (a[mid] <= a[mid + 1]) return;
    merge_run(a, tmp, L, mid, R);
}

void merge_sort_int(int* a, size_t n) {
    if (!a || n < 2) return;
    int* tmp = (int*)malloc(n * sizeof(int));
    if (!tmp) { insertion_sort_int(a, n); return; }
    merge_rec(a, tmp, 0, (int)n - 1);
    insertion_sort_int(a, n);
    free(tmp);
}


static void sift_down(int* a, size_t n, size_t i) {
    for (;;) {
        size_t l = 2*i + 1, r = 2*i + 2, mx = i;
        if (l < n && a[l] > a[mx]) mx = l;
        if (r < n && a[r] > a[mx]) mx = r;
        if (mx == i) break;
        swap_int(&a[i], &a[mx]);
        i = mx;
    }
}

void heap_sort_int(int* a, size_t n) {
    if (!a || n < 2) return;

    for (size_t i = n/2; i > 0; --i) {
        sift_down(a, n, i - 1);
    }

    for (size_t k = n; k > 1; --k) {
        swap_int(&a[0], &a[k - 1]);
        sift_down(a, k - 1, 0);
    }
}

void counting_sort_int_nonneg(int* a, size_t n, int max_val) {
    size_t i;
    int v;
    int* cnt;
    size_t idx = 0;

    if (n == 0) return;
    assert(a != NULL);
    assert(max_val >= 0);

    cnt = (int*)calloc((size_t)max_val + 1, sizeof(int));
    assert(cnt != NULL);

    /* подсчёт */
    for (i = 0; i < n; ++i) {
        assert(a[i] >= 0 && a[i] <= max_val);
        ++cnt[a[i]];
    }

    /* восстановление */
    for (v = 0; v <= max_val; ++v) {
        int c = cnt[v];
        while (c-- > 0) {
            a[idx++] = v;
        }
    }

    free(cnt);
}