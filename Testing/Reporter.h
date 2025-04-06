#ifndef REPORTER_H
#define REPORTER_H
#pragma once
#include "../Lib/Algorithms.h"
#include <chrono>
#include "../Lib/ArrayDataGenerator.h"
#include "../Lib/CsvGenerator.h"
#include "../Util/ArrayStorer.h"

class Reporter
{
public:
    Reporter() = default;

    void GenerateRandomArrayData(int GENERATION_COUNT, int ARRAY_SIZE, std::string mainFolderName)
    {
        auto intArrayStorer = new ArrayStorer<int>();
        auto floatArrayStorer = new ArrayStorer<float>();

        // Allocate arrays properly
        intArrayStorer->Arrays = new int *[GENERATION_COUNT];
        floatArrayStorer->Arrays = new float *[GENERATION_COUNT];

        intArrayStorer->SortingTimesQuickSort = new double[GENERATION_COUNT];
        intArrayStorer->SortingTimesInsertSort = new double[GENERATION_COUNT];
        intArrayStorer->SortingTimesInsertBinarySort = new double[GENERATION_COUNT];
        intArrayStorer->SortingTimesHeapSort = new double[GENERATION_COUNT];

        floatArrayStorer->SortingTimesQuickSort = new double[GENERATION_COUNT];
        floatArrayStorer->SortingTimesInsertSort = new double[GENERATION_COUNT];
        floatArrayStorer->SortingTimesInsertBinarySort = new double[GENERATION_COUNT];
        floatArrayStorer->SortingTimesHeapSort = new double[GENERATION_COUNT];

        auto intArrayStorer33 = new ArrayStorer<int>();
        auto floatArrayStorer33 = new ArrayStorer<float>();

        // Allocate arrays properly
        intArrayStorer33->Arrays = new int *[GENERATION_COUNT];
        floatArrayStorer33->Arrays = new float *[GENERATION_COUNT];

        intArrayStorer33->SortingTimesQuickSort = new double[GENERATION_COUNT];
        intArrayStorer33->SortingTimesInsertSort = new double[GENERATION_COUNT];
        intArrayStorer33->SortingTimesInsertBinarySort = new double[GENERATION_COUNT];
        intArrayStorer33->SortingTimesHeapSort = new double[GENERATION_COUNT];

        floatArrayStorer33->SortingTimesQuickSort = new double[GENERATION_COUNT];
        floatArrayStorer33->SortingTimesInsertSort = new double[GENERATION_COUNT];
        floatArrayStorer33->SortingTimesInsertBinarySort = new double[GENERATION_COUNT];
        floatArrayStorer33->SortingTimesHeapSort = new double[GENERATION_COUNT];

        auto intArrayStorerDesc = new ArrayStorer<int>();
        auto floatArrayStorerDesc = new ArrayStorer<float>();

        // Allocate arrays properly
        intArrayStorerDesc->Arrays = new int *[GENERATION_COUNT];
        floatArrayStorerDesc->Arrays = new float *[GENERATION_COUNT];

        intArrayStorerDesc->SortingTimesQuickSort = new double[GENERATION_COUNT];
        intArrayStorerDesc->SortingTimesInsertSort = new double[GENERATION_COUNT];
        intArrayStorerDesc->SortingTimesInsertBinarySort = new double[GENERATION_COUNT];
        intArrayStorerDesc->SortingTimesHeapSort = new double[GENERATION_COUNT];

        floatArrayStorerDesc->SortingTimesQuickSort = new double[GENERATION_COUNT];
        floatArrayStorerDesc->SortingTimesInsertSort = new double[GENERATION_COUNT];
        floatArrayStorerDesc->SortingTimesInsertBinarySort = new double[GENERATION_COUNT];
        floatArrayStorerDesc->SortingTimesHeapSort = new double[GENERATION_COUNT];


        auto intArrayStorer66 = new ArrayStorer<int>();
        auto floatArrayStorer66 = new ArrayStorer<float>();

        // Allocate arrays properly
        intArrayStorer66->Arrays = new int *[GENERATION_COUNT];
        floatArrayStorer66->Arrays = new float *[GENERATION_COUNT];

        intArrayStorer66->SortingTimesQuickSort = new double[GENERATION_COUNT];
        intArrayStorer66->SortingTimesInsertSort = new double[GENERATION_COUNT];
        intArrayStorer66->SortingTimesInsertBinarySort = new double[GENERATION_COUNT];
        intArrayStorer66->SortingTimesHeapSort = new double[GENERATION_COUNT];

        floatArrayStorer66->SortingTimesQuickSort = new double[GENERATION_COUNT];
        floatArrayStorer66->SortingTimesInsertSort = new double[GENERATION_COUNT];
        floatArrayStorer66->SortingTimesInsertBinarySort = new double[GENERATION_COUNT];
        floatArrayStorer66->SortingTimesHeapSort = new double[GENERATION_COUNT];

        auto intArrayStorer100 = new ArrayStorer<int>();
        auto floatArrayStorer100 = new ArrayStorer<float>();

        // Allocate arrays properly
        intArrayStorer100->Arrays = new int *[GENERATION_COUNT];
        floatArrayStorer100->Arrays = new float *[GENERATION_COUNT];

        intArrayStorer100->SortingTimesQuickSort = new double[GENERATION_COUNT];
        intArrayStorer100->SortingTimesInsertSort = new double[GENERATION_COUNT];
        intArrayStorer100->SortingTimesInsertBinarySort = new double[GENERATION_COUNT];
        intArrayStorer100->SortingTimesHeapSort = new double[GENERATION_COUNT];

        floatArrayStorer100->SortingTimesQuickSort = new double[GENERATION_COUNT];
        floatArrayStorer100->SortingTimesInsertSort = new double[GENERATION_COUNT];
        floatArrayStorer100->SortingTimesInsertBinarySort = new double[GENERATION_COUNT];
        floatArrayStorer100->SortingTimesHeapSort = new double[GENERATION_COUNT];

        auto intDataGenerator = new ArrayDataGenerator<int>();
        auto floatDataGenerator = new ArrayDataGenerator<float>();
        auto intAlgorithms = new Algorithms<int>();
        auto floatAlgorithms = new Algorithms<float>();

        //Generuj dane
        for (int i = 0; i < GENERATION_COUNT; i++)
        {
            intArrayStorer->Arrays[i] = new int[ARRAY_SIZE];     // Allocate space for integers
            floatArrayStorer->Arrays[i] = new float[ARRAY_SIZE]; // Allocate space for floats

            intArrayStorer->Arrays[i] = intDataGenerator->GenerateData(ARRAY_SIZE);
            floatArrayStorer->Arrays[i] = floatDataGenerator->GenerateData(ARRAY_SIZE);

            intArrayStorer33->Arrays[i] = new int[ARRAY_SIZE];     // Allocate space for integers
            floatArrayStorer33->Arrays[i] = new float[ARRAY_SIZE]; // Allocate space for floats

            intArrayStorer33->Arrays[i] = intDataGenerator->Generate33PercentSortedData(ARRAY_SIZE);
            floatArrayStorer33->Arrays[i] = floatDataGenerator->Generate33PercentSortedData(ARRAY_SIZE);

            intArrayStorerDesc->Arrays[i] = new int[ARRAY_SIZE];     // Allocate space for integers
            floatArrayStorerDesc->Arrays[i] = new float[ARRAY_SIZE]; // Allocate space for floats

            intArrayStorerDesc->Arrays[i] = intDataGenerator->GenerateDescendSortedData(ARRAY_SIZE);
            floatArrayStorerDesc->Arrays[i] = floatDataGenerator->GenerateDescendSortedData(ARRAY_SIZE);

            intArrayStorer66->Arrays[i] = new int[ARRAY_SIZE];     // Allocate space for integers
            floatArrayStorer66->Arrays[i] = new float[ARRAY_SIZE]; // Allocate space for floats

            intArrayStorer66->Arrays[i] = intDataGenerator->Generate66PercentSortedData(ARRAY_SIZE);
            floatArrayStorer66->Arrays[i] = floatDataGenerator->Generate66PercentSortedData(ARRAY_SIZE);

            intArrayStorer100->Arrays[i] = new int[ARRAY_SIZE];     // Allocate space for integers
            floatArrayStorer100->Arrays[i] = new float[ARRAY_SIZE]; // Allocate space for floats

            intArrayStorer100->Arrays[i] = intDataGenerator->GenerateSortedData(ARRAY_SIZE);
            floatArrayStorer100->Arrays[i] = floatDataGenerator->GenerateSortedData(ARRAY_SIZE);
        }

        // //int
        for (int i = 0; i < GENERATION_COUNT; i++)
        {
            auto copy = intAlgorithms->copyArray(intArrayStorer->Arrays[i], ARRAY_SIZE);
            auto startQuick = std::chrono::high_resolution_clock::now();
            intAlgorithms->QuickSort(copy, 0, ARRAY_SIZE - 1);
            auto endQuick = std::chrono::high_resolution_clock::now();
            double quickSortTime = std::chrono::duration<double, std::milli>(endQuick - startQuick).count();
            intArrayStorer->SortingTimesQuickSort[i] = quickSortTime;
            delete[] copy;

            copy = intAlgorithms->copyArray(intArrayStorer->Arrays[i], ARRAY_SIZE);
            auto startInsert = std::chrono::high_resolution_clock::now();
            intAlgorithms->InsertSort(copy, ARRAY_SIZE);
            auto endInsert = std::chrono::high_resolution_clock::now();
            double insertSortTime = std::chrono::duration<double, std::milli>(endInsert - startInsert).count();
            intArrayStorer->SortingTimesInsertSort[i] = insertSortTime;
            delete[] copy;

            copy = intAlgorithms->copyArray(intArrayStorer->Arrays[i], ARRAY_SIZE);
            auto startBinary = std::chrono::high_resolution_clock::now();
            intAlgorithms->InsertSortBinary(copy,ARRAY_SIZE);
            auto endBinary = std::chrono::high_resolution_clock::now();
            double binarySortTime = std::chrono::duration<double, std::milli>(endBinary - startBinary).count();
            intArrayStorer->SortingTimesInsertBinarySort[i] = binarySortTime;
            delete[] copy;

            copy = intAlgorithms->copyArray(intArrayStorer->Arrays[i], ARRAY_SIZE);
            auto startHeap = std::chrono::high_resolution_clock::now();
            intAlgorithms->HeapSort(copy, ARRAY_SIZE);
            auto endHeap = std::chrono::high_resolution_clock::now();
            double heapSortTime = std::chrono::duration<double, std::milli>(endHeap - startHeap).count();
            intArrayStorer->SortingTimesHeapSort[i] = heapSortTime;
            delete[] copy;
        }

        // //float
        for (int i = 0; i < GENERATION_COUNT; i++)
        {
            auto copy = floatAlgorithms->copyArray(floatArrayStorer->Arrays[i], ARRAY_SIZE);
            auto startQuick = std::chrono::high_resolution_clock::now();
            floatAlgorithms->QuickSort(copy, 0, ARRAY_SIZE - 1);
            auto endQuick = std::chrono::high_resolution_clock::now();
            double quickSortTime = std::chrono::duration<double, std::milli>(endQuick - startQuick).count();
            floatArrayStorer->SortingTimesQuickSort[i] = quickSortTime;
            delete[] copy;

            copy = floatAlgorithms->copyArray(floatArrayStorer->Arrays[i], ARRAY_SIZE);
            auto startInsert = std::chrono::high_resolution_clock::now();
            floatAlgorithms->InsertSort(copy, ARRAY_SIZE);
            auto endInsert = std::chrono::high_resolution_clock::now();
            double insertSortTime = std::chrono::duration<double, std::milli>(endInsert - startInsert).count();
            floatArrayStorer->SortingTimesInsertSort[i] = insertSortTime;
            delete[] copy;

            copy = floatAlgorithms->copyArray(floatArrayStorer->Arrays[i], ARRAY_SIZE);
            auto startBinary = std::chrono::high_resolution_clock::now();
            floatAlgorithms->InsertSortBinary(copy,ARRAY_SIZE);
            auto endBinary = std::chrono::high_resolution_clock::now();
            double binarySortTime = std::chrono::duration<double, std::milli>(endBinary - startBinary).count();
            floatArrayStorer->SortingTimesInsertBinarySort[i] = binarySortTime;
            delete[] copy;

            copy = floatAlgorithms->copyArray(floatArrayStorer->Arrays[i], ARRAY_SIZE);
            auto startHeap = std::chrono::high_resolution_clock::now();
            floatAlgorithms->HeapSort(copy, ARRAY_SIZE);
            auto endHeap = std::chrono::high_resolution_clock::now();
            double heapSortTime = std::chrono::duration<double, std::milli>(endHeap - startHeap).count();
            floatArrayStorer->SortingTimesHeapSort[i] = heapSortTime;
            delete[] copy;
        }

        auto intCSVGenerator = new CsvGenerator<int>();
        auto floatCSVGenerator = new CsvGenerator<float>();

        intCSVGenerator->generateCsvFiles(intArrayStorer, GENERATION_COUNT, mainFolderName + "/RandomInt");
        floatCSVGenerator->generateCsvFiles(floatArrayStorer, GENERATION_COUNT, mainFolderName + "/RandomFloat");

        //int
        for (int i = 0; i < GENERATION_COUNT; i++)
        {
            auto copy = intAlgorithms->copyArray(intArrayStorer33->Arrays[i], ARRAY_SIZE);
            auto startQuick = std::chrono::high_resolution_clock::now();
            intAlgorithms->QuickSort(copy, 0, ARRAY_SIZE - 1);
            auto endQuick = std::chrono::high_resolution_clock::now();
            double quickSortTime = std::chrono::duration<double, std::milli>(endQuick - startQuick).count();
            intArrayStorer33->SortingTimesQuickSort[i] = quickSortTime;
            delete[] copy;

            copy = intAlgorithms->copyArray(intArrayStorer33->Arrays[i], ARRAY_SIZE);
            auto startInsert = std::chrono::high_resolution_clock::now();
            intAlgorithms->InsertSort(copy, ARRAY_SIZE);
            auto endInsert = std::chrono::high_resolution_clock::now();
            double insertSortTime = std::chrono::duration<double, std::milli>(endInsert - startInsert).count();
            intArrayStorer33->SortingTimesInsertSort[i] = insertSortTime;
            delete[] copy;

            copy = intAlgorithms->copyArray(intArrayStorer33->Arrays[i], ARRAY_SIZE);
            auto startBinary = std::chrono::high_resolution_clock::now();
            intAlgorithms->InsertSortBinary(copy,ARRAY_SIZE);
            auto endBinary = std::chrono::high_resolution_clock::now();
            double binarySortTime = std::chrono::duration<double, std::milli>(endBinary - startBinary).count();
            intArrayStorer33->SortingTimesInsertBinarySort[i] = binarySortTime;
            delete[] copy;

            copy = intAlgorithms->copyArray(intArrayStorer33->Arrays[i], ARRAY_SIZE);
            auto startHeap = std::chrono::high_resolution_clock::now();
            intAlgorithms->HeapSort(copy, ARRAY_SIZE);
            auto endHeap = std::chrono::high_resolution_clock::now();
            double heapSortTime = std::chrono::duration<double, std::milli>(endHeap - startHeap).count();
            intArrayStorer33->SortingTimesHeapSort[i] = heapSortTime;
            delete[] copy;
        }

        // //float
        for (int i = 0; i < GENERATION_COUNT; i++)
        {
            auto copy = floatAlgorithms->copyArray(floatArrayStorer33->Arrays[i], ARRAY_SIZE);
            auto startQuick = std::chrono::high_resolution_clock::now();
            floatAlgorithms->QuickSort(copy, 0, ARRAY_SIZE - 1);
            auto endQuick = std::chrono::high_resolution_clock::now();
            double quickSortTime = std::chrono::duration<double, std::milli>(endQuick - startQuick).count();
            floatArrayStorer33->SortingTimesQuickSort[i] = quickSortTime;
            delete[] copy;

            copy = floatAlgorithms->copyArray(floatArrayStorer33->Arrays[i], ARRAY_SIZE);
            auto startInsert = std::chrono::high_resolution_clock::now();
            floatAlgorithms->InsertSort(copy, ARRAY_SIZE);
            auto endInsert = std::chrono::high_resolution_clock::now();
            double insertSortTime = std::chrono::duration<double, std::milli>(endInsert - startInsert).count();
            floatArrayStorer33->SortingTimesInsertSort[i] = insertSortTime;
            delete[] copy;

            copy = floatAlgorithms->copyArray(floatArrayStorer33->Arrays[i], ARRAY_SIZE);
            auto startBinary = std::chrono::high_resolution_clock::now();
            floatAlgorithms->InsertSortBinary(copy,ARRAY_SIZE);
            auto endBinary = std::chrono::high_resolution_clock::now();
            double binarySortTime = std::chrono::duration<double, std::milli>(endBinary - startBinary).count();
            floatArrayStorer33->SortingTimesInsertBinarySort[i] = binarySortTime;
            delete[] copy;

            copy = floatAlgorithms->copyArray(floatArrayStorer33->Arrays[i], ARRAY_SIZE);
            auto startHeap = std::chrono::high_resolution_clock::now();
            floatAlgorithms->HeapSort(copy, ARRAY_SIZE);
            auto endHeap = std::chrono::high_resolution_clock::now();
            double heapSortTime = std::chrono::duration<double, std::milli>(endHeap - startHeap).count();
            floatArrayStorer33->SortingTimesHeapSort[i] = heapSortTime;
            delete[] copy;
        }


        intCSVGenerator->generateCsvFiles(intArrayStorer33, GENERATION_COUNT, mainFolderName + "/RandomInt33");
        floatCSVGenerator->generateCsvFiles(floatArrayStorer33, GENERATION_COUNT, mainFolderName + "/RandomFloat33");

        //int
        for (int i = 0; i < GENERATION_COUNT; i++)
        {
            auto copy = intAlgorithms->copyArray(intArrayStorerDesc->Arrays[i], ARRAY_SIZE);
            auto startQuick = std::chrono::high_resolution_clock::now();
            intAlgorithms->QuickSort(copy, 0, ARRAY_SIZE - 1);
            auto endQuick = std::chrono::high_resolution_clock::now();
            double quickSortTime = std::chrono::duration<double, std::milli>(endQuick - startQuick).count();
            intArrayStorerDesc->SortingTimesQuickSort[i] = quickSortTime;
            delete[] copy;

            copy = intAlgorithms->copyArray(intArrayStorerDesc->Arrays[i], ARRAY_SIZE);
            auto startInsert = std::chrono::high_resolution_clock::now();
            intAlgorithms->InsertSort(copy, ARRAY_SIZE);
            auto endInsert = std::chrono::high_resolution_clock::now();
            double insertSortTime = std::chrono::duration<double, std::milli>(endInsert - startInsert).count();
            intArrayStorerDesc->SortingTimesInsertSort[i] = insertSortTime;
            delete[] copy;

            copy = intAlgorithms->copyArray(intArrayStorerDesc->Arrays[i], ARRAY_SIZE);
            auto startBinary = std::chrono::high_resolution_clock::now();
            intAlgorithms->InsertSortBinary(copy,ARRAY_SIZE);
            auto endBinary = std::chrono::high_resolution_clock::now();
            double binarySortTime = std::chrono::duration<double, std::milli>(endBinary - startBinary).count();
            intArrayStorerDesc->SortingTimesInsertBinarySort[i] = binarySortTime;
            delete[] copy;

            copy = intAlgorithms->copyArray(intArrayStorerDesc->Arrays[i], ARRAY_SIZE);
            auto startHeap = std::chrono::high_resolution_clock::now();
            intAlgorithms->HeapSort(copy, ARRAY_SIZE);
            auto endHeap = std::chrono::high_resolution_clock::now();
            double heapSortTime = std::chrono::duration<double, std::milli>(endHeap - startHeap).count();
            intArrayStorerDesc->SortingTimesHeapSort[i] = heapSortTime;
            delete[] copy;
        }

        //float
        for (int i = 0; i < GENERATION_COUNT; i++)
        {
            auto copy = floatAlgorithms->copyArray(floatArrayStorerDesc->Arrays[i], ARRAY_SIZE);
            auto startQuick = std::chrono::high_resolution_clock::now();
            floatAlgorithms->QuickSort(copy, 0, ARRAY_SIZE - 1);
            auto endQuick = std::chrono::high_resolution_clock::now();
            double quickSortTime = std::chrono::duration<double, std::milli>(endQuick - startQuick).count();
            floatArrayStorerDesc->SortingTimesQuickSort[i] = quickSortTime;
            delete[] copy;

            copy = floatAlgorithms->copyArray(floatArrayStorerDesc->Arrays[i], ARRAY_SIZE);
            auto startInsert = std::chrono::high_resolution_clock::now();
            floatAlgorithms->InsertSort(copy, ARRAY_SIZE);
            auto endInsert = std::chrono::high_resolution_clock::now();
            double insertSortTime = std::chrono::duration<double, std::milli>(endInsert - startInsert).count();
            floatArrayStorerDesc->SortingTimesInsertSort[i] = insertSortTime;
            delete[] copy;

            copy = floatAlgorithms->copyArray(floatArrayStorerDesc->Arrays[i], ARRAY_SIZE);
            auto startBinary = std::chrono::high_resolution_clock::now();
            floatAlgorithms->InsertSortBinary(copy,ARRAY_SIZE);
            auto endBinary = std::chrono::high_resolution_clock::now();
            double binarySortTime = std::chrono::duration<double, std::milli>(endBinary - startBinary).count();
            floatArrayStorerDesc->SortingTimesInsertBinarySort[i] = binarySortTime;
            delete[] copy;

            copy = floatAlgorithms->copyArray(floatArrayStorerDesc->Arrays[i], ARRAY_SIZE);
            auto startHeap = std::chrono::high_resolution_clock::now();
            floatAlgorithms->HeapSort(copy, ARRAY_SIZE);
            auto endHeap = std::chrono::high_resolution_clock::now();
            double heapSortTime = std::chrono::duration<double, std::milli>(endHeap - startHeap).count();
            floatArrayStorerDesc->SortingTimesHeapSort[i] = heapSortTime;
            delete[] copy;
        }

        intCSVGenerator->generateCsvFiles(intArrayStorerDesc, GENERATION_COUNT, mainFolderName + "/RandomIntDesc");
        floatCSVGenerator->generateCsvFiles(floatArrayStorerDesc, GENERATION_COUNT, mainFolderName + "/RandomFloatDesc");

        // //int
        for (int i = 0; i < GENERATION_COUNT; i++)
        {
            auto copy = intAlgorithms->copyArray(intArrayStorer66->Arrays[i], ARRAY_SIZE);
            auto startQuick = std::chrono::high_resolution_clock::now();
            intAlgorithms->QuickSort(copy, 0, ARRAY_SIZE - 1);
            auto endQuick = std::chrono::high_resolution_clock::now();
            double quickSortTime = std::chrono::duration<double, std::milli>(endQuick - startQuick).count();
            intArrayStorer66->SortingTimesQuickSort[i] = quickSortTime;
            delete[] copy;

            copy = intAlgorithms->copyArray(intArrayStorer66->Arrays[i], ARRAY_SIZE);
            auto startInsert = std::chrono::high_resolution_clock::now();
            intAlgorithms->InsertSort(copy, ARRAY_SIZE);
            auto endInsert = std::chrono::high_resolution_clock::now();
            double insertSortTime = std::chrono::duration<double, std::milli>(endInsert - startInsert).count();
            intArrayStorer66->SortingTimesInsertSort[i] = insertSortTime;
            delete[] copy;

            copy = intAlgorithms->copyArray(intArrayStorer66->Arrays[i], ARRAY_SIZE);
            auto startBinary = std::chrono::high_resolution_clock::now();
            intAlgorithms->InsertSortBinary(copy,ARRAY_SIZE);
            auto endBinary = std::chrono::high_resolution_clock::now();
            double binarySortTime = std::chrono::duration<double, std::milli>(endBinary - startBinary).count();
            intArrayStorer66->SortingTimesInsertBinarySort[i] = binarySortTime;
            delete[] copy;

            copy = intAlgorithms->copyArray(intArrayStorer66->Arrays[i], ARRAY_SIZE);
            auto startHeap = std::chrono::high_resolution_clock::now();
            intAlgorithms->HeapSort(copy, ARRAY_SIZE);
            auto endHeap = std::chrono::high_resolution_clock::now();
            double heapSortTime = std::chrono::duration<double, std::milli>(endHeap - startHeap).count();
            intArrayStorer66->SortingTimesHeapSort[i] = heapSortTime;
            delete[] copy;
        }

        // //float
        for (int i = 0; i < GENERATION_COUNT; i++)
        {
            auto copy = floatAlgorithms->copyArray(floatArrayStorer66->Arrays[i], ARRAY_SIZE);
            auto startQuick = std::chrono::high_resolution_clock::now();
            floatAlgorithms->QuickSort(copy, 0, ARRAY_SIZE - 1);
            auto endQuick = std::chrono::high_resolution_clock::now();
            double quickSortTime = std::chrono::duration<double, std::milli>(endQuick - startQuick).count();
            floatArrayStorer66->SortingTimesQuickSort[i] = quickSortTime;
            delete[] copy;

            copy = floatAlgorithms->copyArray(floatArrayStorer66->Arrays[i], ARRAY_SIZE);
            auto startInsert = std::chrono::high_resolution_clock::now();
            floatAlgorithms->InsertSort(copy, ARRAY_SIZE);
            auto endInsert = std::chrono::high_resolution_clock::now();
            double insertSortTime = std::chrono::duration<double, std::milli>(endInsert - startInsert).count();
            floatArrayStorer66->SortingTimesInsertSort[i] = insertSortTime;
            delete[] copy;

            copy = floatAlgorithms->copyArray(floatArrayStorer66->Arrays[i], ARRAY_SIZE);
            auto startBinary = std::chrono::high_resolution_clock::now();
            floatAlgorithms->InsertSortBinary(copy,ARRAY_SIZE);
            auto endBinary = std::chrono::high_resolution_clock::now();
            double binarySortTime = std::chrono::duration<double, std::milli>(endBinary - startBinary).count();
            floatArrayStorer66->SortingTimesInsertBinarySort[i] = binarySortTime;
            delete[] copy;

            copy = floatAlgorithms->copyArray(floatArrayStorer66->Arrays[i], ARRAY_SIZE);
            auto startHeap = std::chrono::high_resolution_clock::now();
            floatAlgorithms->HeapSort(copy, ARRAY_SIZE);
            auto endHeap = std::chrono::high_resolution_clock::now();
            double heapSortTime = std::chrono::duration<double, std::milli>(endHeap - startHeap).count();
            floatArrayStorer66->SortingTimesHeapSort[i] = heapSortTime;
            delete[] copy;
        }

        intCSVGenerator->generateCsvFiles(intArrayStorer66, GENERATION_COUNT, mainFolderName + "/RandomInt66");
        floatCSVGenerator->generateCsvFiles(floatArrayStorer66, GENERATION_COUNT, mainFolderName + "/RandomFloat66");

        // //int
        for (int i = 0; i < GENERATION_COUNT; i++)
        {
            auto copy = intAlgorithms->copyArray(intArrayStorer100->Arrays[i], ARRAY_SIZE);
            auto startQuick = std::chrono::high_resolution_clock::now();
            intAlgorithms->QuickSort(copy, 0, ARRAY_SIZE - 1);
            auto endQuick = std::chrono::high_resolution_clock::now();
            double quickSortTime = std::chrono::duration<double, std::milli>(endQuick - startQuick).count();
            intArrayStorer100->SortingTimesQuickSort[i] = quickSortTime;
            delete[] copy;

            copy = intAlgorithms->copyArray(intArrayStorer100->Arrays[i], ARRAY_SIZE);
            auto startInsert = std::chrono::high_resolution_clock::now();
            intAlgorithms->InsertSort(copy, ARRAY_SIZE);
            auto endInsert = std::chrono::high_resolution_clock::now();
            double insertSortTime = std::chrono::duration<double, std::milli>(endInsert - startInsert).count();
            intArrayStorer100->SortingTimesInsertSort[i] = insertSortTime;
            delete[] copy;

            copy = intAlgorithms->copyArray(intArrayStorer100->Arrays[i], ARRAY_SIZE);
            auto startBinary = std::chrono::high_resolution_clock::now();
            intAlgorithms->InsertSortBinary(copy,ARRAY_SIZE);
            auto endBinary = std::chrono::high_resolution_clock::now();
            double binarySortTime = std::chrono::duration<double, std::milli>(endBinary - startBinary).count();
            intArrayStorer100->SortingTimesInsertBinarySort[i] = binarySortTime;
            delete[] copy;

            copy = intAlgorithms->copyArray(intArrayStorer100->Arrays[i], ARRAY_SIZE);
            auto startHeap = std::chrono::high_resolution_clock::now();
            intAlgorithms->HeapSort(copy, ARRAY_SIZE);
            auto endHeap = std::chrono::high_resolution_clock::now();
            double heapSortTime = std::chrono::duration<double, std::milli>(endHeap - startHeap).count();
            intArrayStorer100->SortingTimesHeapSort[i] = heapSortTime;
            delete[] copy;
        }

        // //float
        for (int i = 0; i < GENERATION_COUNT; i++)
        {
            auto copy = floatAlgorithms->copyArray(floatArrayStorer100->Arrays[i], ARRAY_SIZE);
            auto startQuick = std::chrono::high_resolution_clock::now();
            floatAlgorithms->QuickSort(copy, 0, ARRAY_SIZE - 1);
            auto endQuick = std::chrono::high_resolution_clock::now();
            double quickSortTime = std::chrono::duration<double, std::milli>(endQuick - startQuick).count();
            floatArrayStorer100->SortingTimesQuickSort[i] = quickSortTime;
            delete[] copy;

            copy = floatAlgorithms->copyArray(floatArrayStorer100->Arrays[i], ARRAY_SIZE);
            auto startInsert = std::chrono::high_resolution_clock::now();
            floatAlgorithms->InsertSort(copy, ARRAY_SIZE);
            auto endInsert = std::chrono::high_resolution_clock::now();
            double insertSortTime = std::chrono::duration<double, std::milli>(endInsert - startInsert).count();
            floatArrayStorer100->SortingTimesInsertSort[i] = insertSortTime;
            delete[] copy;

            copy = floatAlgorithms->copyArray(floatArrayStorer100->Arrays[i], ARRAY_SIZE);
            auto startBinary = std::chrono::high_resolution_clock::now();
            floatAlgorithms->InsertSortBinary(copy,ARRAY_SIZE);
            auto endBinary = std::chrono::high_resolution_clock::now();
            double binarySortTime = std::chrono::duration<double, std::milli>(endBinary - startBinary).count();
            floatArrayStorer100->SortingTimesInsertBinarySort[i] = binarySortTime;
            delete[] copy;

            copy = floatAlgorithms->copyArray(floatArrayStorer100->Arrays[i], ARRAY_SIZE);
            auto startHeap = std::chrono::high_resolution_clock::now();
            floatAlgorithms->HeapSort(copy, ARRAY_SIZE);
            auto endHeap = std::chrono::high_resolution_clock::now();
            double heapSortTime = std::chrono::duration<double, std::milli>(endHeap - startHeap).count();
            floatArrayStorer100->SortingTimesHeapSort[i] = heapSortTime;
            delete[] copy;
        }

        intCSVGenerator->generateCsvFiles(intArrayStorer100, GENERATION_COUNT, mainFolderName + " /RandomInt100");
        floatCSVGenerator->generateCsvFiles(floatArrayStorer100, GENERATION_COUNT, mainFolderName + "/RandomFloat100");

        // Free allocated memory
        for (int i = 0; i < GENERATION_COUNT; i++)
        {
            delete[] intArrayStorer->Arrays[i];
            delete[] floatArrayStorer->Arrays[i];
            delete[] intArrayStorerDesc->Arrays[i];
            delete[] floatArrayStorerDesc->Arrays[i];
        }

        delete[] intArrayStorer->Arrays;
        delete[] floatArrayStorer->Arrays;
        delete[] intArrayStorer->SortingTimesQuickSort;
        delete[] intArrayStorer->SortingTimesInsertSort;
        delete[] floatArrayStorer->SortingTimesQuickSort;
        delete[] floatArrayStorer->SortingTimesInsertSort;
        delete[] intArrayStorer->SortingTimesInsertBinarySort;
        delete[] intArrayStorer->SortingTimesHeapSort;
        delete[] floatArrayStorer->SortingTimesInsertBinarySort;
        delete[] floatArrayStorer->SortingTimesHeapSort;
        delete intArrayStorer;
        delete floatArrayStorer;

        delete[] intArrayStorer33->Arrays;
        delete[] floatArrayStorer33->Arrays;
        delete[] intArrayStorer33->SortingTimesQuickSort;
        delete[] intArrayStorer33->SortingTimesInsertSort;
        delete[] floatArrayStorer33->SortingTimesQuickSort;
        delete[] floatArrayStorer33->SortingTimesInsertSort;
        delete[] intArrayStorer33->SortingTimesInsertBinarySort;
        delete[] intArrayStorer33->SortingTimesHeapSort;
        delete[] floatArrayStorer33->SortingTimesInsertBinarySort;
        delete[] floatArrayStorer33->SortingTimesHeapSort;
        delete intArrayStorer33;

        delete[] intArrayStorerDesc->Arrays;
        delete[] floatArrayStorerDesc->Arrays;
        delete[] intArrayStorerDesc->SortingTimesQuickSort;
        delete[] intArrayStorerDesc->SortingTimesInsertSort;
        delete[] floatArrayStorerDesc->SortingTimesQuickSort;
        delete[] floatArrayStorerDesc->SortingTimesInsertSort;
        delete[] intArrayStorerDesc->SortingTimesInsertBinarySort;
        delete[] intArrayStorerDesc->SortingTimesHeapSort;
        delete[] floatArrayStorerDesc->SortingTimesInsertBinarySort;
        delete[] floatArrayStorerDesc->SortingTimesHeapSort;
        delete intArrayStorerDesc;
        delete floatArrayStorerDesc;

        delete[] intArrayStorer66->Arrays;
        delete[] floatArrayStorer66->Arrays;
        delete[] intArrayStorer66->SortingTimesQuickSort;
        delete[] intArrayStorer66->SortingTimesInsertSort;
        delete[] floatArrayStorer66->SortingTimesQuickSort;
        delete[] floatArrayStorer66->SortingTimesInsertSort;
        delete[] intArrayStorer66->SortingTimesInsertBinarySort;
        delete[] intArrayStorer66->SortingTimesHeapSort;
        delete[] floatArrayStorer66->SortingTimesInsertBinarySort;
        delete[] floatArrayStorer66->SortingTimesHeapSort;
        delete intArrayStorer66;
        delete floatArrayStorer66;

        delete[] intArrayStorer100->Arrays;
        delete[] floatArrayStorer100->Arrays;
        delete[] intArrayStorer100->SortingTimesQuickSort;
        delete[] intArrayStorer100->SortingTimesInsertSort;
        delete[] floatArrayStorer100->SortingTimesQuickSort;
        delete[] floatArrayStorer100->SortingTimesInsertSort;
        delete[] intArrayStorer100->SortingTimesInsertBinarySort;
        delete[] intArrayStorer100->SortingTimesHeapSort;
        delete[] floatArrayStorer100->SortingTimesInsertBinarySort;
        delete[] floatArrayStorer100->SortingTimesHeapSort;
        delete intArrayStorer100;
        delete floatArrayStorer100;
    }
};

#endif //REPORTER_H