#include "drone_test_bench.hpp"

int main()
{
    const int SIZE = 5;
    char testFrame[SIZE] = {'1', '2', '3', '4', '5'};

    if (SIZE <= 0)
    {
        std::cout << "Error: SIZE is zero or negative." << std::endl;
        return 1;
    }
    printFrame<SIZE>(testFrame);
    std::cout << min(testFrame) << std::endl;
    composeTags("Channel", "motor_temp", "Priority", 4);

    return 0;
}