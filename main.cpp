#include "iostream"
#include "arraylib.h"

int main() {
    std::vector<int> pulse = {
        118, 125, 132, 145, 151,
        148, 139, 128, 121, 116
    };

    std::cout << "Пульс спортсмена во время тренировки: " << std::endl;

    for (std::size_t i = 0; i < pulse.size(); i++) {
        std::cout << pulse[i] << " ";
    }

    std::cout << std::endl << std::endl;

    std::cout << "Минимальный пульс: " << arr_min(pulse) << std::endl;
    std::cout << "Максимальный пульс: " << arr_max(pulse) << std::endl;
    std::cout << "Средний пульс: " << arr_average(pulse) << std::endl;
    std::cout << "Медиана: " << arr_median(pulse) << std::endl;
    std::cout << "Количество измерений выше 140: "
            << arr_count_above_140(pulse) << std::endl;

    return 0;
}

