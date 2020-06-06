#pragma once
#include <vector>
#include <limits>

int maxOfVector(const std::vector<int>& vec) {
    if (vec.empty() == true) {
        return 0;
    }

    int maxValue = vec[0];

    for (const auto& el : vec) {
        if (el > maxValue) {
            maxValue = el;
        }
    }
    return maxValue;
}
