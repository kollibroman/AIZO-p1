#ifndef ALGORITHMS_H
#define ALGORITHMS_H

template <typename T>
class Algorithms
{
    public:
        Algorithms() = default;

        void QuickSort(T *tab, int left, int right)
        {
            if (left >= right)
                return;

            T pivot = tab[(right + left) / 2];
            int i = left, j = right;

            do
            {
                while (tab[i] < pivot)
                    i++;
                while (tab[j] > pivot)
                    j--;

                if (i <= j)
                {
                    std::swap(tab[i], tab[j]);
                    i++;
                    j--;
                }
            } while (i <= j);

            if (j > left)
            {
                QuickSort(tab, left, j);
            }

            if (i < right)
            {
                QuickSort(tab, i, right);
            }
        }

        void HeapSort(T *tab, int n)
        {
            // stworz kopiec
            for (int i = n / 2 - 1; i >= 0; i--)
            {
                Heapify(tab, n, i);
            }

            //Bierzemy po kolei od tylu wyrazy w kopcu
            for (int i = n - 1; i > 0; i--)
            {
                // zamieniamy korzen z ostatnim wyrazem w kopcu
                int temp = tab[0];
                tab[0] = tab[i];
                tab[i] = temp;

                // Przywroc wlasnosc kopca
                Heapify(tab, i, 0);
            }
        }

        void InsertSort(T *tab, int n)
        {
            for (int i = 1; i < n; i++)
            {
                auto temp = tab[i];
                int j = i - 1;

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
            for (int i = 0; i < n; i++)
            {
                auto key = tab[i];
                int j = i - 1;

                int index = BinarySearch(tab, key, 0, j);

                while (j >= index)
                {
                    tab[j + 1] = tab[j];
                    j--;
                }

                tab[j + 1] = key;
            }
        }

        T* copyArray(T* original, int size)
        {
            T* copy = new T[size];

            for (int i = 0; i < size; i++)
            {
                copy[i] = original[i];
            }

            return copy;
        }

private:

    static void Heapify(T* tab, int n, int i)
    {
        // użyj najwiekszego jako korzen
        int largest = i;

        // lewy indeks: 2i + 1
        int left = 2 * i + 1;

        // prawy indeks: 2i + 2
        int right = 2 * i + 2;

        if (left < n && tab[left] > tab[largest])
        {
            largest = left;
        }

        if (right < n && tab[right] > tab[largest])
        {
            largest = right;
        }

        if (largest != i)
        {
            int temp = tab[i];
            tab[i] = tab[largest];
            tab[largest] = temp;

            // Wykonuj rekursywnie do momentu stworzenia kopca
            Heapify(tab, n, largest);
        }
    }

    int BinarySearch(T* tab, int item, int low, int high)
    {
        while (low <= high)
        {
            int mid = low + (high - low) / 2;

            if (item == tab[mid])
            {
                return mid + 1; // Wstaw po duplikatach
            }

            else if (item > tab[mid])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low; // Pozycja do wstawienia
    }
};

#endif //ALGORITHMS_H
