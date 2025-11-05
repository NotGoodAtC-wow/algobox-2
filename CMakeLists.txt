cmake_minimum_required(VERSION 3.16)
project(algobox C)

# -----------------------------------------------------------------------------
# Language / flags
# -----------------------------------------------------------------------------
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Чуть более строгие предупреждения
if (MSVC)
    add_compile_options(/W4 /permissive-)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# -----------------------------------------------------------------------------
# Library target
# -----------------------------------------------------------------------------
add_library(algobox STATIC
        src/algo_math.c
        src/algo_search.c
        src/algo_sort.c
        src/algo_utils.c
        src/algo_select.c
        # заголовки только для IDE (не компилируются)
        include/algo_math.h
        include/algo_search.h
        include/algo_sort.h
        include/algo_utils.h
        include/algo_select.h
)
target_include_directories(algobox PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# -----------------------------------------------------------------------------
# Tests
# -----------------------------------------------------------------------------
enable_testing()

# sort
add_executable(test_sort tests/test_sort.c
        tests/test_counting.c)
target_link_libraries(test_sort PRIVATE algobox)
add_test(NAME test_sort COMMAND test_sort)

# search
add_executable(test_search tests/test_search.c)
target_link_libraries(test_search PRIVATE algobox)
add_test(NAME test_search COMMAND test_search)

# math
add_executable(test_math tests/test_math.c)
target_link_libraries(test_math PRIVATE algobox)
add_test(NAME test_math COMMAND test_math)

# select (quickselect)  <-- NEW
add_executable(test_select tests/test_select.c
        tests/test_select.c)
target_link_libraries(test_select PRIVATE algobox)
add_test(NAME test_select COMMAND test_select)

# counting sort        <-- NEW
add_executable(test_counting tests/test_counting.c
        tests/test_counting.cpp
        tests/test_counting.c
        tests/test_counting.c
        tests/test_counting.c)
target_link_libraries(test_counting PRIVATE algobox)
add_test(NAME test_counting COMMAND test_counting)

# -----------------------------------------------------------------------------
# (Опционально) CLI на будущее
# -----------------------------------------------------------------------------
# add_executable(algobox_cli src/cli.c)
# target_link_libraries(algobox_cli PRIVATE algobox)
