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

function(add_opt_test name src)
    if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${src}")
        add_executable(${name} ${src})
        target_link_libraries(${name} PRIVATE algobox)
        add_test(NAME ${name} COMMAND ${name})
    endif()
endfunction()

# существующие
add_opt_test(test_sort   tests/test_sort.c)
add_opt_test(test_search tests/test_search.c)
add_opt_test(test_math   tests/test_math.c)

# появятся автоматически, когда добавишь файлы
add_opt_test(test_select   tests/test_select.c)
add_opt_test(test_counting tests/test_counting.c)   # именно .c, не .cpp
