#ifndef SORTCHECKER_H
#define SORTCHECKER_H

class SortChecker
{
    public:
        SortChecker()
        {
        }
        
        template <typename T>
        bool isSortedAscending(T *arr, int size)
        {
            for (int i = 1; i < size; i++)
            {
                if (arr[i] < arr[i - 1])
                {
                    return false; // Not sorted in ascending order
                }
            }
            return true;
        }

        template <typename T>
        bool isSortedDescending(T *arr, int size)
        {
            for (int i = 1; i < size; i++)
            {
                if (arr[i] > arr[i - 1])
                {
                    return false; // Not sorted in descending order
                }
            }
            return true;
        }

        template <typename T>
        bool isSorted(T *arr, int size)
        {
            return isSortedAscending(arr, size) || isSortedDescending(arr, size);
        }
};

#endif // SORTCHECKER_H