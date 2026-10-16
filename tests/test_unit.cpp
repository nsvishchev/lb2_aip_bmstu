#include "arraylib.h"

#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

bool close(double a, double b, double eps = 1e-9) {
    return std::fabs(a - b) < eps;
}

int main() {
    std::vector<int> a = {-5, 0, 3, 3, 8, -2};

    // Проверяем сумму
    assert(arr_sum(a) == 7);

    // Проверяем максимум и минимум
    assert(arr_max(a) == 8);
    assert(arr_min(a) == -5);

    // Проверяем количество элементов
    assert(arr_count_positive(a) == 3);
    assert(arr_count_negative(a) == 2);
    assert(arr_count_zero(a) == 1);

    // Проверяем произведение
    assert(arr_product(a) == 0);

    // Проверяем среднее
    assert(close(arr_average(a), 7.0 / 6.0));

    // Медиана массива с чётным количеством элементов
    std::vector<int> b = {7, 1, 9, 3};
    assert(close(arr_median(b), 5.0));

    // Медиана массива с нечётным количеством элементов
    std::vector<int> c = {5, 1, 3};
    assert(close(arr_median(c), 3.0));

    // Медиана не должна изменять исходный массив
    std::vector<int> original = {7, 1, 9, 3};
    std::vector<int> copy = original;

    arr_median(original);
    assert(original == copy);

    // Произведение без нулевых элементов
    std::vector<int> d = {1, 2, 3, 4};
    assert(arr_product(d) == 24);

    // Проверяем дополнительную функцию варианта 19
    std::vector<int> pulse = {
        118, 125, 132, 145, 151,
        148, 139, 128, 121, 116
    };

    assert(arr_count_above_140(pulse) == 3);

    std::cout << "[unit] All tests passed\n";

    return 0;
}
