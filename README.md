# AlgoBox (C) — v2

[![Linux CI](https://github.com/NotGoodAtC-wow/algobox-2/actions/workflows/ci-ubuntu.yml/badge.svg)](https://github.com/NotGoodAtC-wow/algobox-2/actions/workflows/ci-ubuntu.yml)
[![Windows CI](https://github.com/NotGoodAtC-wow/algobox-2/actions/workflows/ci-windows.yml/badge.svg)](https://github.com/NotGoodAtC-wow/algobox-2/actions/workflows/ci-windows.yml)
![License](https://img.shields.io/badge/license-MIT-informational)
![Language](https://img.shields.io/badge/language-C99-blue)

A small educational algorithms library in **C99**.  
Built with **CMake**, tested with **CTest**. All arrays use row-major, plain `int` buffers.

---

## What’s new in v2

- **Sorting**: classic O(n²) sorts + **heap sort** for O(n log n).
- **Searching**: binary search for sorted arrays.
- **Selection**: **quickselect** (k-th order statistic) — get the k-th smallest in linear average time.
- Cleaner CMake targets, stricter warnings, cross-platform CI (Ubuntu + Windows).

> See headers in `include/` for exact signatures.

---

## Headers & Functions

- `include/algo_sort.h`  
  `bubble_sort_int`, `insertion_sort_int`, `selection_sort_int`, `heap_sort_int`
- `include/algo_search.h`  
  `binary_search_int`
- `include/algo_math.h`  
  (small helpers used in tests/demos, e.g. `gcd_int`, etc.)
- `include/algo_select.h`  
  `quickselect_int` (k-th element)

---

## Build

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```
## Test
```bash
# run all tests via CTest
ctest --test-dir build --output-on-failure
```
## Quick usage
## Sorting
```c
#include "algo_sort.h"
#include <stddef.h>

int a[] = {5, 4, 3, 2, 1};
size_t n = sizeof a / sizeof a[0];

heap_sort_int(a, n);  // O(n log n)
// now: {1, 2, 3, 4, 5}
```
## Searching
```c
#include "algo_search.h"
#include <stddef.h>

const int a[] = {1, 2, 3, 4, 5};
int idx = binary_search_int(a, 5, 4);  // -> 3, or -1 if not found
```
## Selection
```c
#include "algo_select.h"
#include <stddef.h>

int a[] = {7, 1, 9, 2, 5, 3};
size_t n = sizeof a / sizeof a[0];

// Find k-th (0-based) smallest, e.g. k = 2 -> the 3rd smallest element
int kth = quickselect_int(a, n, 2);
```
## Project structure
```cpp
include/
  algo_sort.h
  algo_search.h
  algo_math.h
  algo_select.h
src/
  algo_sort.c
  algo_search.c
  algo_math.c
  algo_select.c
tests/
  test_sort.c
  test_search.c
  test_math.c
  (optional) test_select.c
```
## Roadmap
- v3: more selections and linear-time tricks, extra searches; stability notes for sorts.
- v4: more selections and linear-time tricks, extra searches; stability notes for sorts.
## License: MIT
