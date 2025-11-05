cmake_minimum_required(VERSION 3.16)
project(algobox C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# -----------------------------------------------------------------------------
# Library target
# -----------------------------------------------------------------------------
file(GLOB ALGOLIB_SOURCES
        src/*.c
)

add_library(algobox STATIC ${ALGOLIB_SOURCES}
        include/algo_sort.h
        include/algo_search.h
        include/algo_math.h
        include/algo_utils.h
        src/algo_sort.c
        include/algo_math.h
        src/algo_search.c
        src/algo_math.c
        src/algo_utils.c)
target_include_directories(algobox PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# -----------------------------------------------------------------------------
# Tests
# -----------------------------------------------------------------------------
enable_testing()

# Sort tests
add_executable(test_sort tests/test_sort.c
        tests/test_sort.c)
target_link_libraries(test_sort PRIVATE algobox)
add_test(NAME test_sort COMMAND test_sort)

# Search tests
add_executable(test_search tests/test_search.c
        tests/test_search.c)
target_link_libraries(test_search PRIVATE algobox)
add_test(NAME test_search COMMAND test_search)

# Math tests
add_executable(test_math tests/test_math.c
        tests/test_math.c)
target_link_libraries(test_math PRIVATE algobox)
add_test(NAME test_math COMMAND test_math)

# -----------------------------------------------------------------------------
# Future CLI placeholder (for v5+)
# -----------------------------------------------------------------------------
# add_executable(algobox_cli src/cli.c)
# target_link_libraries(algobox_cli PRIVATE algobox)
