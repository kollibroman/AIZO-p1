#include <iostream>
#include "UI/MainMenu.h"
#include "Util/UserInputStorer.h"
#include "Lib/Algorithms.h"
#define array_size(arr) (sizeof(arr) / sizeof(*(arr)))
#include <chrono>

#include "Util/SortChecker.h"

template<typename T> void displayArray(T* tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i % 10 == 0 && i != 0)
        {
            std::cout << tab[i] << std::endl;
        }

        else
        {
            std::cout << tab[i] << " ";
        }
    }
}

int main()
{
    srand(time(0));
    int GENERATION_COUNT = 10;
    int ARRAY_SIZE = 100;

    auto userInputStorer = new UserInputStorer(0, "");

    auto intArrayStorer = new ArrayStorer<int>();
    auto floatArrayStorer = new ArrayStorer<float>();

    // Allocate arrays properly
    intArrayStorer->Arrays = new int *[GENERATION_COUNT];
    floatArrayStorer->Arrays = new float *[GENERATION_COUNT];

    intArrayStorer->SortingTimesQuickSort = new double[GENERATION_COUNT];
    intArrayStorer->SortingTimesInsertSort = new double[GENERATION_COUNT];

    floatArrayStorer->SortingTimesQuickSort = new double[GENERATION_COUNT];
    floatArrayStorer->SortingTimesInsertSort = new double[GENERATION_COUNT];

    for (int i = 0; i < GENERATION_COUNT; i++)
    {
        intArrayStorer->Arrays[i] = new int[ARRAY_SIZE];     // Allocate space for integers
        floatArrayStorer->Arrays[i] = new float[ARRAY_SIZE]; // Allocate space for floats
    }

    auto menu = new MainMenu(userInputStorer, intArrayStorer, floatArrayStorer, GENERATION_COUNT, ARRAY_SIZE);

    if (userInputStorer->Option == 1)
    {
        if (intArrayStorer->Arrays[0] != nullptr) // Ensure it's not null
        {
            auto algorithms = new Algorithms<int>();
            auto sortChecker = new SortChecker();

            for (int i = 0; i < GENERATION_COUNT; i++)
            {
                auto copy = algorithms->copyArray(intArrayStorer->Arrays[i], ARRAY_SIZE);
                std::cout << "Array: " << std::endl;
                displayArray(copy, ARRAY_SIZE);

                // if (userInputStorer->ChosenAlgorithm == 1)
                // {
                //     auto startQuick = std::chrono::high_resolution_clock::now();
                //     algorithms->QuickSort(copy, 0, ARRAY_SIZE - 1);
                //     auto endQuick = std::chrono::high_resolution_clock::now();
                //     double quickSortTime = std::chrono::duration<double, std::milli>(endQuick - startQuick).count();
                //     intArrayStorer->SortingTimesQuickSort[0] = quickSortTime;
                //
                //     std::cout << "\n SortedArray:" << std::endl;
                //     displayArray(copy, ARRAY_SIZE);
                //
                //     std::cout << "\n Sorted? " << sortChecker->isSorted(copy, ARRAY_SIZE) << std::endl;
                //     std::cout << "\n Array " << 0 << " - QuickSort Time: " << quickSortTime << " ms" << std::endl;
                // }

                // else if (userInputStorer->ChosenAlgorithm == 2)
                // {
                    auto startInsert = std::chrono::high_resolution_clock::now();
                    algorithms->InsertSort(copy, ARRAY_SIZE);
                    auto endInsert = std::chrono::high_resolution_clock::now();
                    double insertSortTime = std::chrono::duration<double, std::milli>(endInsert - startInsert).count();
                    intArrayStorer->SortingTimesInsertSort[0] = insertSortTime;

                    std::cout << "\n SortedArray: " << std::endl;
                    displayArray(copy, ARRAY_SIZE);

                    std::cout << "\n Sorted? " << sortChecker->isSorted(copy, ARRAY_SIZE) << std::endl;
                    std::cout << "\n Array " << 0 << " - InsertSort Time: " << insertSortTime << " ms" << std::endl;
                // }

                delete[] copy;
            }

            delete algorithms; // Free memory
        }

        else if (floatArrayStorer->Arrays[0] != nullptr) // Ensure it's not null
        {
            auto algorithms = new Algorithms<float>();
            auto sortChecker = new SortChecker();

            for (int i = 0; i < GENERATION_COUNT; i++)
            {
                auto copy = algorithms->copyArray(floatArrayStorer->Arrays[i], ARRAY_SIZE);
                std::cout << "Array: " << std::endl;
                displayArray(copy, ARRAY_SIZE);

                if (userInputStorer->ChosenAlgorithm == 1)
                {
                    auto startQuick = std::chrono::high_resolution_clock::now();
                    algorithms->QuickSort(copy, 0, ARRAY_SIZE - 1);
                    auto endQuick = std::chrono::high_resolution_clock::now();
                    double quickSortTime = std::chrono::duration<double, std::milli>(endQuick - startQuick).count();
                    floatArrayStorer->SortingTimesQuickSort[0] = quickSortTime;

                    std::cout << "\n SortedArray:" << std::endl;
                    displayArray(copy, ARRAY_SIZE);

                    std::cout << "\n Sorted? " << sortChecker->isSorted(copy, ARRAY_SIZE) << std::endl;
                    std::cout << "\n Array " << 0 << " - QuickSort Time: " << quickSortTime << " ms" << std::endl;
                }

                else if (userInputStorer->ChosenAlgorithm == 2)
                {
                    auto startInsert = std::chrono::high_resolution_clock::now();
                    algorithms->InsertSort(copy, ARRAY_SIZE);
                    auto endInsert = std::chrono::high_resolution_clock::now();
                    double insertSortTime = std::chrono::duration<double, std::milli>(endInsert - startInsert).count();
                    floatArrayStorer->SortingTimesInsertSort[0] = insertSortTime;

                    std::cout << "\n SortedArray: " << std::endl;
                    displayArray(copy, ARRAY_SIZE);

                    std::cout << "\n Sorted? " << sortChecker->isSorted(copy, ARRAY_SIZE) << std::endl;
                    std::cout << "\n Array " << 0 << " - InsertSort Time: " << insertSortTime << " ms" << std::endl;
                }

                delete[] copy;
            }

            delete algorithms; // Free memory
        }
   }

    else if (userInputStorer->Option == 2)
    {
        auto sortChecker = new SortChecker();

        if (userInputStorer->DataType == "int")
        {
            auto algorithms = new Algorithms<int>();
            auto copy = algorithms->copyArray(intArrayStorer->Arrays[0], 49);
            std::cout << "Array: " << std::endl;
            displayArray(copy, 49);

            if (userInputStorer->ChosenAlgorithm == 1)
            {
                auto startQuick = std::chrono::high_resolution_clock::now();
                algorithms->QuickSort(copy, 0, 48);
                auto endQuick = std::chrono::high_resolution_clock::now();
                double quickSortTime = std::chrono::duration<double, std::milli>(endQuick - startQuick).count();
                intArrayStorer->SortingTimesQuickSort[0] = quickSortTime;

                std::cout << "\n SortedArray:" << std::endl;
                displayArray(copy, 49);
                std::cout << "\n Sorted? " << sortChecker->isSorted(copy, 49) << std::endl;
                std::cout << "\n Array " << 0 << " - QuickSort Time: " << quickSortTime << " ms" << std::endl;
            }

            else if (userInputStorer->ChosenAlgorithm == 2)
            {
                auto startInsert = std::chrono::high_resolution_clock::now();
                algorithms->InsertSort(copy, 49);
                auto endInsert = std::chrono::high_resolution_clock::now();
                double insertSortTime = std::chrono::duration<double, std::milli>(endInsert - startInsert).count();
                intArrayStorer->SortingTimesInsertSort[0] = insertSortTime;

                std::cout << "\n SortedArray: " << std::endl;
                displayArray(copy, 49);

                std::cout << "\n Sorted? " << sortChecker->isSorted(copy, 49) << std::endl;
                std::cout << "\n Array " << 0 << " - InsertSort Time: " << insertSortTime << " ms" << std::endl;
            }
        }

        else if (userInputStorer->DataType == "float")
        {
            auto algorithms = new Algorithms<float>();
            auto copy = algorithms->copyArray(floatArrayStorer->Arrays[0], 49);
            std::cout << "Array: " << std::endl;
            displayArray(copy, 49);

            if (userInputStorer->ChosenAlgorithm == 1)
            {
                auto startQuick = std::chrono::high_resolution_clock::now();
                algorithms->QuickSort(copy, 0, 48);
                auto endQuick = std::chrono::high_resolution_clock::now();
                double quickSortTime = std::chrono::duration<double, std::milli>(endQuick - startQuick).count();
                floatArrayStorer->SortingTimesQuickSort[0] = quickSortTime;

                std::cout << "\n SortedArray:" << std::endl;
                displayArray(copy, 49);
                std::cout << "\n Array " << 0 << " - QuickSort Time: " << quickSortTime << " ms" << std::endl;
                delete[] copy;
            }

            else if (userInputStorer->ChosenAlgorithm == 2)
            {
                auto startInsert = std::chrono::high_resolution_clock::now();
                algorithms->InsertSort(copy, 49);
                auto endInsert = std::chrono::high_resolution_clock::now();
                double insertSortTime = std::chrono::duration<double, std::milli>(endInsert - startInsert).count();
                floatArrayStorer->SortingTimesInsertSort[0] = insertSortTime;

                std::cout << "\n SortedArray: " << std::endl;
                displayArray(copy, 49);

                std::cout << "\n Array " << 0 << " - InsertSort Time: " << insertSortTime << " ms" << std::endl;
                delete[] copy;
            }
        }
    }

    // Free allocated memory
    for (int i = 0; i < GENERATION_COUNT; i++)
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