#pragma once
#include <iostream>
#include "MainMenu.h"
#include "../Util/UserInputStorer.h"
#include "../Lib/Algorithms.h"
#include "../Util/SortChecker.h"
#include <chrono>

#ifndef MENUUTILS_H
#define MENUUTILS_H

class MenuUtils
{
    public:
        MenuUtils(UserInputStorer *&userInputStorer)
        {
            while (true)
            {
                auto intArrayStorer = new ArrayStorer<int>();
                auto floatArrayStorer = new ArrayStorer<float>();

                int GENERATION_COUNT = 1;

                // Allocate arrays properly
                intArrayStorer->Arrays = new int *[GENERATION_COUNT];
                floatArrayStorer->Arrays = new float *[GENERATION_COUNT];

                intArrayStorer->SortingTimesQuickSort = new double[GENERATION_COUNT];
                intArrayStorer->SortingTimesInsertSort = new double[GENERATION_COUNT];

                floatArrayStorer->SortingTimesQuickSort = new double[GENERATION_COUNT];
                floatArrayStorer->SortingTimesInsertSort = new double[GENERATION_COUNT];

                intArrayStorer->SortingTimesInsertBinarySort = new double[GENERATION_COUNT];
                intArrayStorer->SortingTimesHeapSort = new double[GENERATION_COUNT];

                floatArrayStorer->SortingTimesInsertBinarySort = new double[GENERATION_COUNT];
                floatArrayStorer->SortingTimesHeapSort = new double[GENERATION_COUNT];

                auto menu = new MainMenu(userInputStorer, intArrayStorer, floatArrayStorer);
                int ARRAY_SIZE = userInputStorer->ArraySize;

                if (userInputStorer->Option == 1)
                {
                    if (userInputStorer->DataType == "int") // Ensure it's not null
                    {
                        auto algorithms = new Algorithms<int>();
                        auto sortChecker = new SortChecker();

                        for (int i = 0; i < GENERATION_COUNT; i++)
                        {
                            auto copy = algorithms->copyArray(intArrayStorer->Arrays[i], ARRAY_SIZE);
                            std::cout << "Array: " << std::endl;
                            displayArray(copy, ARRAY_SIZE);

                            if (userInputStorer->ChosenAlgorithm == 1)
                            {
                                auto startQuick = std::chrono::high_resolution_clock::now();
                                algorithms->QuickSort(copy, 0, ARRAY_SIZE - 1);
                                auto endQuick = std::chrono::high_resolution_clock::now();
                                double quickSortTime = std::chrono::duration<double, std::milli>(endQuick - startQuick).count();
                                intArrayStorer->SortingTimesQuickSort[i] = quickSortTime;

                                std::cout << "\n SortedArray:" << std::endl;
                                displayArray(copy, ARRAY_SIZE);

                                std::cout << "\n Sorted? " << sortChecker->isSorted(copy, ARRAY_SIZE) << std::endl;
                                std::cout << "\n Array " << i << " - QuickSort Time: " << quickSortTime << " ms" << std::endl;
                            }

                            else if (userInputStorer->ChosenAlgorithm == 2)
                            {
                                auto startInsert = std::chrono::high_resolution_clock::now();
                                algorithms->InsertSort(copy, ARRAY_SIZE);
                                auto endInsert = std::chrono::high_resolution_clock::now();
                                double insertSortTime = std::chrono::duration<double, std::milli>(endInsert - startInsert).count();
                                intArrayStorer->SortingTimesInsertSort[i] = insertSortTime;

                                std::cout << "\n SortedArray: " << std::endl;
                                displayArray(copy, ARRAY_SIZE);

                                std::cout << "\n Sorted? " << sortChecker->isSorted(copy, ARRAY_SIZE) << std::endl;
                                std::cout << "\n Array " << i << " - InsertSort Time: " << insertSortTime << " ms" << std::endl;
                            }

                            else if (userInputStorer->ChosenAlgorithm == 3)
                            {
                                auto startBinary = std::chrono::high_resolution_clock::now();
                                algorithms->InsertSortBinary(copy, ARRAY_SIZE);
                                auto endBin = std::chrono::high_resolution_clock::now();
                                double binarySortTime = std::chrono::duration<double, std::milli>(endBin - startBinary).count();
                                intArrayStorer->SortingTimesInsertBinarySort[i] = binarySortTime;

                                std::cout << "\n SortedArray: " << std::endl;
                                displayArray(copy, ARRAY_SIZE);

                                std::cout << "\n Sorted? " << sortChecker->isSorted(copy, ARRAY_SIZE) << std::endl;
                                std::cout << "\n Array " << i << " - BinaryInsertSort Time: " << binarySortTime << " ms" << std::endl;
                            }

                            else if (userInputStorer->ChosenAlgorithm == 4)
                            {
                                auto startHeap = std::chrono::high_resolution_clock::now();
                                algorithms->HeapSort(copy, ARRAY_SIZE);
                                auto endHeap = std::chrono::high_resolution_clock::now();
                                double heapSortTime = std::chrono::duration<double, std::milli>(endHeap - startHeap).count();
                                intArrayStorer->SortingTimesHeapSort[i] = heapSortTime;

                                std::cout << "\n SortedArray: " << std::endl;
                                displayArray(copy, ARRAY_SIZE);

                                std::cout << "\n Sorted? " << sortChecker->isSorted(copy, ARRAY_SIZE) << std::endl;
                                std::cout << "\n Array " << i << " - HeapSort Time: " << heapSortTime << " ms" << std::endl;
                            }

                            delete[] copy;
                        }

                        delete algorithms; // Free memory
                    }

                    else if (userInputStorer->DataType == "float")
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
                                floatArrayStorer->SortingTimesQuickSort[i] = quickSortTime;

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
                                floatArrayStorer->SortingTimesInsertSort[i] = insertSortTime;

                                std::cout << "\n SortedArray: " << std::endl;
                                displayArray(copy, ARRAY_SIZE);

                                std::cout << "\n Sorted? " << sortChecker->isSorted(copy, ARRAY_SIZE) << std::endl;
                                std::cout << "\n Array " << 0 << " - InsertSort Time: " << insertSortTime << " ms" << std::endl;
                            }

                            else if (userInputStorer->ChosenAlgorithm == 3)
                            {
                                auto startBinary = std::chrono::high_resolution_clock::now();
                                algorithms->InsertSortBinary(copy, ARRAY_SIZE);
                                auto endBin = std::chrono::high_resolution_clock::now();
                                double binarySortTime = std::chrono::duration<double, std::milli>(endBin - startBinary).count();
                                floatArrayStorer->SortingTimesInsertBinarySort[i] = binarySortTime;

                                std::cout << "\n SortedArray: " << std::endl;
                                displayArray(copy, ARRAY_SIZE);

                                std::cout << "\n Sorted? " << sortChecker->isSorted(copy, ARRAY_SIZE) << std::endl;
                                std::cout << "\n Array " << 0 << " - BinaryInsertSort Time: " << binarySortTime << " ms" << std::endl;
                            }

                            else if (userInputStorer->ChosenAlgorithm == 4)
                            {
                                auto startHeap = std::chrono::high_resolution_clock::now();
                                algorithms->HeapSort(copy, ARRAY_SIZE);
                                auto endHeap = std::chrono::high_resolution_clock::now();
                                double heapSortTime = std::chrono::duration<double, std::milli>(endHeap - startHeap).count();
                                floatArrayStorer->SortingTimesHeapSort[i] = heapSortTime;

                                std::cout << "\n SortedArray: " << std::endl;
                                displayArray(copy, ARRAY_SIZE);

                                std::cout << "\n Sorted? " << sortChecker->isSorted(copy, ARRAY_SIZE) << std::endl;
                                std::cout << "\n Array " << 0 << " - HeapSort Time: " << heapSortTime << " ms" << std::endl;
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

                        else if (userInputStorer->ChosenAlgorithm == 3)
                        {
                            auto startBinary = std::chrono::high_resolution_clock::now();
                            algorithms->InsertSortBinary(copy, ARRAY_SIZE);
                            auto endBin = std::chrono::high_resolution_clock::now();
                            double binarySortTime = std::chrono::duration<double, std::milli>(endBin - startBinary).count();
                            intArrayStorer->SortingTimesInsertBinarySort[0] = binarySortTime;

                            std::cout << "\n SortedArray: " << std::endl;
                            displayArray(copy, ARRAY_SIZE);

                            std::cout << "\n Sorted? " << sortChecker->isSorted(copy, ARRAY_SIZE) << std::endl;
                            std::cout << "\n Array " << 0 << " - BinaryInsertSort Time: " << binarySortTime << " ms" << std::endl;
                        }

                        else if (userInputStorer->ChosenAlgorithm == 4)
                        {
                            auto startHeap = std::chrono::high_resolution_clock::now();
                            algorithms->HeapSort(copy, ARRAY_SIZE);
                            auto endHeap = std::chrono::high_resolution_clock::now();
                            double heapSortTime = std::chrono::duration<double, std::milli>(endHeap - startHeap).count();
                            intArrayStorer->SortingTimesHeapSort[0] = heapSortTime;

                            std::cout << "\n SortedArray: " << std::endl;
                            displayArray(copy, ARRAY_SIZE);

                            std::cout << "\n Sorted? " << sortChecker->isSorted(copy, ARRAY_SIZE) << std::endl;
                            std::cout << "\n Array " << 0 << " - HeapSort Time: " << heapSortTime << " ms" << std::endl;
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
                        }

                        else if (userInputStorer->ChosenAlgorithm == 3)
                        {
                            auto startBinary = std::chrono::high_resolution_clock::now();
                            algorithms->InsertSortBinary(copy, ARRAY_SIZE);
                            auto endBin = std::chrono::high_resolution_clock::now();
                            double binarySortTime = std::chrono::duration<double, std::milli>(endBin - startBinary).count();
                            floatArrayStorer->SortingTimesInsertBinarySort[0] = binarySortTime;

                            std::cout << "\n SortedArray: " << std::endl;
                            displayArray(copy, ARRAY_SIZE);

                            std::cout << "\n Sorted? " << sortChecker->isSorted(copy, ARRAY_SIZE) << std::endl;
                            std::cout << "\n Array " << 0 << " - BinaryInsertSort Time: " << binarySortTime << " ms" << std::endl;
                        }

                        else if (userInputStorer->ChosenAlgorithm == 4)
                        {
                            auto startHeap = std::chrono::high_resolution_clock::now();
                            algorithms->HeapSort(copy, ARRAY_SIZE);
                            auto endHeap = std::chrono::high_resolution_clock::now();
                            double heapSortTime = std::chrono::duration<double, std::milli>(endHeap - startHeap).count();

                            //TODO: fix segfault here
                            floatArrayStorer->SortingTimesHeapSort[0] = heapSortTime;

                            std::cout << "\n SortedArray: " << std::endl;
                            displayArray(copy, ARRAY_SIZE);

                            std::cout << "\n Sorted? " << sortChecker->isSorted(copy, ARRAY_SIZE) << std::endl;
                            std::cout << "\n Array " << 0 << " - HeapSort Time: " << heapSortTime << " ms" << std::endl;
                        }

                        delete[] copy;
                    }
                }

                if (userInputStorer->Option == 3)
                {
                    // Free allocated memory
                    break;
                }
            }
        }

private:
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
};

#endif //MENUUTILS_H