#ifndef ARRAYSTORER_H
#define ARRAYSTORER_H

#include <iostream>
template <typename T>
struct ArrayStorer
{
    ArrayStorer() = default;

    T** Arrays;
    double* SortingTimesQuickSort{};
    double* SortingTimesHeapSort{};
    double* SortingTimesInsertSort{};
    double* SortingTimesInsertBinarySort{};
};

#endif //ARRAYSTORER_H