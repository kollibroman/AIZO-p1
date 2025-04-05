#pragma once
#include "../Util/ArrayStorer.h"
#include <fstream>
#include <filesystem>
#include <string>
#include <sstream>

#ifndef CSVGENERATOR_H
#define CSVGENERATOR_H

template<typename T> class CsvGenerator {
    public:
    void generateCsvFiles(ArrayStorer<T>* storer, int generationCount, const std::string& folderName)
    {
        // Create folder if it doesn't exist
        std::filesystem::create_directories(folderName);

        auto writeCsv = [&](const std::string& filename, double* times) {
            std::string fullPath = folderName + "/" + filename;
            std::ofstream file(fullPath);
            if (!file.is_open())
            {
                std::cerr << "Error opening file: " << fullPath << std::endl;
                return;
            }

            file << "Index,Time(ms)\n";
            for (int i = 0; i < generationCount; ++i)
            {
                file << i << "," << times[i] << "\n";
            }

            file.close();
            std::cout << "Saved: " << fullPath << std::endl;
        };

        if (storer->SortingTimesQuickSort)
        {
            writeCsv("QuickSortTimes.csv", storer->SortingTimesQuickSort);
        }

        if (storer->SortingTimesHeapSort)
        {
            writeCsv("HeapSortTimes.csv", storer->SortingTimesHeapSort);
        }
        if (storer->SortingTimesInsertSort)
        {
            writeCsv("InsertSortTimes.csv", storer->SortingTimesInsertSort);
        }
        if (storer->SortingTimesInsertBinarySort) {
            writeCsv("InsertBinarySortTimes.csv", storer->SortingTimesInsertBinarySort);
        }
    }
};

#endif //CSVGENERATOR_H
