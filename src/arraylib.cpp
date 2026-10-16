#include <cstddef>
#include <algorithm>
#include <vector>
#include <stdexcept>

// Сумма элементов массива
int arr_sum(const std::vector<int>& arr) {
    int sum = 0;

    for (std::size_t i = 0; i < arr.size(); i++) {
        sum += arr[i];
    }

    return sum;
}

// Максимальный элемент массива
int arr_max(const std::vector<int>& arr) {
    if (arr.empty()) {
        throw std::invalid_argument("Массив пуст");
    }

    int max = arr[0];

    for (std::size_t i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

// Минимальный элемент массива
int arr_min(const std::vector<int>& arr) {
    if (arr.empty()) {
        throw std::invalid_argument("Массив пуст");
    }

    int min = arr[0];

    for (std::size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

// Среднее арифметическое элементов массива
double arr_average(const std::vector<int>& arr) {
    if (arr.empty()) {
        throw std::invalid_argument("Массив пуст");
    }

    return static_cast<double>(arr_sum(arr)) / arr.size();
}

// Количество положительных элементов
std::size_t arr_count_positive(const std::vector<int>& arr) {
    std::size_t count = 0;

    for (std::size_t i = 0; i < arr.size(); i++) {
        if (arr[i] > 0) {
            count++;
        }
    }

    return count;
}

// Количество отрицательных элементов
std::size_t arr_count_negative(const std::vector<int>& arr) {
    std::size_t count = 0;

    for (std::size_t i = 0; i < arr.size(); i++) {
        if (arr[i] < 0) {
            count++;
        }
    }

    return count;
}

// Количество нулевых элементов
std::size_t arr_count_zero(const std::vector<int>& arr) {
    std::size_t count = 0;

    for (std::size_t i = 0; i < arr.size(); i++) {
        if (arr[i] == 0) {
            count++;
        }
    }

    return count;
}

// Произведение элементов массива
int arr_product(const std::vector<int>& arr) {
    int product = 1;

    for (std::size_t i = 0; i < arr.size(); i++) {
        product *= arr[i];
    }

    return product;
}

// Медиана массива
double arr_median(const std::vector<int>& arr) {
    if (arr.empty()) {
        throw std::invalid_argument("Массив пуст");
    }

    // Создаём копию, чтобы не изменять исходный массив
    std::vector<int> copy = arr;

    // Сортируем копию по возрастанию
    std::sort(copy.begin(), copy.end());

    std::size_t n = copy.size();

    // Если количество элементов нечётное
    if (n % 2 != 0) {
        return copy[n / 2];
    }

    // Если количество элементов чётное
    return (static_cast<double>(copy[n / 2 - 1]) + copy[n / 2]) / 2.0;
}

 // Количество измерений пульса выше 140
std::size_t arr_count_above_140(const std::vector<int>& arr) {
    std::size_t count = 0;

    for (std::size_t i = 0; i < arr.size(); i++) {
        if (arr[i] > 140) {
            count++;
        }
    }

    return count;
}