#include <array>
#include <iostream>

int main() {
    std::array<int, 4> values{ {4, 1, 3, 2} };

    for (std::size_t i = 0; i + 1 < values.size(); ++i) {
        std::size_t min_index = i;
        for (std::size_t j = i + 1; j < values.size(); ++j) {
            if (values[j] < values[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = values[i];
            values[i] = values[min_index];
            values[min_index] = temp;
        }
    }

    for (std::size_t i = 0; i < values.size(); ++i) {
        std::cout << values[i];
        if (i + 1 < values.size()) {
            std::cout << ' ';
        }
    }
    std::cout << '\n';
    return 0;
}
