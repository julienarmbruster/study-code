#include <array>
#include <iostream>

int main() {
    std::array<int, 4> values{ {4, 1, 3, 2} };

    for (std::size_t i = 1; i < values.size(); ++i) {
        int key = values[i];
        std::size_t j = i;
        while (j > 0 && values[j - 1] > key) {
            values[j] = values[j - 1];
            --j;
        }
        values[j] = key;
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
