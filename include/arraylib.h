#ifndef ARRAYLIB_H
#define ARRAYLIB_H

#include <cstddef>
#include <vector>

#if defined(_WIN32)
    #if defined(ARRAYLIB_BUILD)
        #define ARRAYLIB_API __declspec(dllexport)
    #else
        #define ARRAYLIB_API __declspec(dllimport)
    #endif
#else
    #define ARRAYLIB_API
#endif

ARRAYLIB_API int arr_sum(const std::vector<int>& arr);
ARRAYLIB_API int arr_max(const std::vector<int>& arr);
ARRAYLIB_API int arr_min(const std::vector<int>& arr);
ARRAYLIB_API double arr_average(const std::vector<int>& arr);

ARRAYLIB_API std::size_t arr_count_positive(const std::vector<int>& arr);
ARRAYLIB_API std::size_t arr_count_negative(const std::vector<int>& arr);
ARRAYLIB_API std::size_t arr_count_zero(const std::vector<int>& arr);

ARRAYLIB_API int arr_product(const std::vector<int>& arr);
ARRAYLIB_API double arr_median(const std::vector<int>& arr);

ARRAYLIB_API std::size_t arr_count_above_140(const std::vector<int>& arr);

#endif