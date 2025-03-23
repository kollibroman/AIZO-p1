#include <iostream>
#include "UI/MainMenu.h"
#include "Util/UserInputStorer.h"
#include "Lib/Algorithms.h"
#define array_size(arr) (sizeof(arr) / sizeof(*(arr)))
#include <chrono>
#include "Util/SortChecker.h"

int main()
{
    auto userInputStorer = new UserInputStorer(0, "", 0);

    auto intArrayStorer = new ArrayStorer<int>();
    auto floatArrayStorer = new ArrayStorer<float>();

    // Allocate arrays properly
    intArrayStorer->Arrays = new int *[1000];
    floatArrayStorer->Arrays = new float *[1000];

    intArrayStorer->SortingTimesQuickSort = new double[1000];
    intArrayStorer->SortingTimesInsertSort = new double[1000];

    floatArrayStorer->SortingTimesQuickSort = new double[100];
    floatArrayStorer->SortingTimesInsertSort = new double[100];

    for (int i = 0; i < 100; i++)
    {
        intArrayStorer->Arrays[i] = new int[10];     // Allocate space for integers
        floatArrayStorer->Arrays[i] = new float[10]; // Allocate space for floats
    }

    auto menu = new MainMenu(userInputStorer, intArrayStorer, floatArrayStorer);

    if (intArrayStorer->Arrays[0] != nullptr) // Ensure it's not null
    {
        auto algorithms = new Algorithms<int>();
        auto sortChecker = new SortChecker();

        for (int i = 0; i < 100; i++)
        {
            auto startQuick = std::chrono::high_resolution_clock::now();
            algorithms->QuickSort(intArrayStorer->Arrays[i], 0, 100 - 1);
            auto endQuick = std::chrono::high_resolution_clock::now();
            double quickSortTime = std::chrono::duration<double, std::milli>(endQuick - startQuick).count();
            intArrayStorer->SortingTimesQuickSort[i] = quickSortTime;

            auto startInsert = std::chrono::high_resolution_clock::now();
            algorithms->InsertSort(intArrayStorer->Arrays[i], 100);
            auto endInsert = std::chrono::high_resolution_clock::now();
            double insertSortTime = std::chrono::duration<double, std::milli>(endInsert - startInsert).count();
            intArrayStorer->SortingTimesInsertSort[i] = insertSortTime;

            std::cout << "Array " << i << " - QuickSort Time: " << quickSortTime << " ms, InsertSort Time: " << insertSortTime << " ms\n";
            std::cout << "Is sorted? " << sortChecker->isSorted(intArrayStorer->Arrays[i], 100) << std::endl;
        }

        delete algorithms; // Free memory
    }
    else if (floatArrayStorer->Arrays[0] != nullptr) // Ensure it's not null
    {
        auto algorithms = new Algorithms<float>();
        auto sortChecker = new SortChecker();

        for (int i = 0; i < 100; i++)
        {
            auto startQuick = std::chrono::high_resolution_clock::now();
            algorithms->QuickSort(floatArrayStorer->Arrays[i], 0, 100 - 1);
            auto endQuick = std::chrono::high_resolution_clock::now();
            double quickSortTime = std::chrono::duration<double, std::milli>(endQuick - startQuick).count();
            floatArrayStorer->SortingTimesQuickSort[i] = quickSortTime;

            auto startInsert = std::chrono::high_resolution_clock::now();
            algorithms->InsertSort(floatArrayStorer->Arrays[i], 100);
            auto endInsert = std::chrono::high_resolution_clock::now();
            double insertSortTime = std::chrono::duration<double, std::milli>(endInsert - startInsert).count();
            floatArrayStorer->SortingTimesInsertSort[i] = insertSortTime;

            std::cout << "Array " << i << " - QuickSort Time: " << quickSortTime << " ms, InsertSort Time: " << insertSortTime << " ms\n";
            std::cout << "Is sorted? " << sortChecker->isSorted(floatArrayStorer->Arrays[i], 100) << std::endl;
        }

        delete algorithms; // Free memory
    }

    // Free allocated memory
    for (int i = 0; i < 100; i++)
    {
        delete[] intArrayStorer->Arrays[i];
        delete[] floatArrayStorer->Arrays[i];
    }

    delete[] intArrayStorer->Arrays;
    delete[] floatArrayStorer->Arrays;
    delete[] intArrayStorer->SortingTimesQuickSort;
    delete[] intArrayStorer->SortingTimesInsertSort;
    delete[] floatArrayStorer->SortingTimesQuickSort;
    delete[] floatArrayStorer->SortingTimesInsertSort;
    delete intArrayStorer;
    delete floatArrayStorer;
    delete userInputStorer;
    delete menu;

    return 0;
}