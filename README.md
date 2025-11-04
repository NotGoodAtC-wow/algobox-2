# algobox-c
[![CI](https://github.com/NotGoodAtC-wow/algobox-2/actions/workflows/cmake.yml/badge.svg)](https://github.com/NotGoodAtC-wow/algobox-2/actions/workflows/cmake.yml)
![Language](https://img.shields.io/badge/language-C99-blue)
![Build](https://img.shields.io/github/actions/workflow/status/NotGoodAtC-wow/algobox-2/cmake.yml?label=CI)
![License](https://img.shields.io/badge/license-MIT-informational)

A modular algorithm and data-structure library in **pure C99**, built with **CMake** and tested via **CTest**.

---

### Features (v1.0.0)
- 🔹 Sorting: bubble, insertion, selection
- 🔹 Searching: linear, binary
- 🔹 Math: gcd, lcm, is_prime, pow_int
- 🔹 Utils: swap, print_array

---

### Build
```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
