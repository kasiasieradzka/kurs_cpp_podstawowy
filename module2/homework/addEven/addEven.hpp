#pragma once
#include <vector>

int addEven(const std::vector<int>& numbers) {
    int sumOfEvenNumbers = 0;

    for (auto i = 0; i < numbers.size(); i++)
    {
        if (numbers[i] % 2 == 0)
        {
            sumOfEvenNumbers += numbers[i];
        }
        return sumOfEvenNumbers;
    }
}
