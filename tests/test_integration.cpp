
#include "arraylib.h"

#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

int main() {
    // Вариант 19: пульс спортсмена
    std::vector<int> pulse = {
        118, 125, 132, 145, 151,
        148, 139, 128, 121, 116
    };

    // Проверяем результаты нескольких функций
    assert(arr_min(pulse) == 116);
    assert(arr_max(pulse) == 151);

    assert(std::abs(arr_average(pulse) - 132.3) < 1e-9);
    assert(std::abs(arr_median(pulse) - 130.0) < 1e-9);

    assert(arr_count_above_140(pulse) == 3);

    // Проверяем согласованность результатов
    assert(arr_min(pulse) <= arr_average(pulse));
    assert(arr_average(pulse) <= arr_max(pulse));

    std::cout << "Integration tests passed!" << std::endl;

    return 0;
}
