#ifndef ALGORITHMS_H
#define ALGORITHMS_H

template <typename T>
class Algorithms
{
    public:
        Algorithms()
        {
        }

        void QuickSort(T *tab, int left, int right)
        {
            if (left >= right)
                return;

            T v = tab[(right + left) / 2];
            int i = left, j = right;

            do
            {
                while (tab[i] < v)
                    i++;
                while (tab[j] > v)
                    j--;

                if (i <= j)
                {
                    std::swap(tab[i], tab[j]);
                    i++;
                    j--;
                }
            } while (i <= j);

            if (j > left)
                QuickSort(tab, left, j);
            if (i < right)
                QuickSort(tab, i, right);
        }

        void HeapSort(T *tab, int n)
        {
            // Implementation needed
        }

        void InsertSort(T *tab, int n)
        {
            T temp;
            int j;
            for (int i = 1; i < n; i++)
            {
                temp = tab[i];
                j = i - 1;

                while (j >= 0 && tab[j] > temp)
                {
                    tab[j + 1] = tab[j];
                    j--;
                }
                tab[j + 1] = temp;
            }
        }

        void InsertSortBinary(T *tab, int n)
        {
            // Implementation needed
        }
};

#endif //ALGORITHMS_H
