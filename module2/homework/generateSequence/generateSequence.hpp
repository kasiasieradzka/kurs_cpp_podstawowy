#pragma once
#include <vector>

std::vector<int> generateSequence(int count, int step) {

    if (count <= 0){ 
        return {};
    }

    auto firstValue = step;

    std::vector<int> vecSequence;

    for(int i = 0; i < count; i++){
        vecSequence.push_back(firstValue);
        firstValue += step;
    }

    return vecSequence;
}
