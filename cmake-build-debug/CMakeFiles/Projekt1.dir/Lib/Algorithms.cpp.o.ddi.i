# 0 "/home/kollibroman/Studia/AIZO/Projekt1/Lib/Algorithms.cpp"
# 1 "/home/kollibroman/Studia/AIZO/Projekt1/cmake-build-debug//"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "/home/kollibroman/Studia/AIZO/Projekt1/Lib/Algorithms.cpp"




# 1 "/home/kollibroman/Studia/AIZO/Projekt1/Lib/Algorithms.h" 1



template <typename T>
class Algorithms
{
    public:
        void QuickSort(T *tab, int left, int right)
        {
            int v = tab[(right + left) / 2];
            int i, j, x;
            i = left;
            j = right;

            do
            {
                while (tab[i] < v)
                {
                    i++;
                }

                while (tab[j] > v)
                {
                    j--;
                }

                if (i <= j)
                {
                    x = tab[i];
                    tab[i] = tab[j];
                    tab[j] = x;
                    i++;
                    j--;
                }
            } while (i <= j);

            if (j > left)
            {
                Quicksort(tab, left, j);
            }

            if (i < right)
            {
                Quicksort(tab, i, right);
            }

        }

        void HeapSort(T *tab, int n)
        {
        }

        void InsertSort(T *tab, int n)
        {
            T temp, j;
            for (int i = 1; i < n; i++)
            {

                temp = tab[i];
                j = i - 1;


                while (j >= 0 && tab[j] > temp)
                {
                    tab[j + 1] = tab[j];
                    --j;
                }

                tab[j + 1] = temp;
            }
        }

        void InsertSortBinary(T *tab, int n)
        {
        }
};
# 6 "/home/kollibroman/Studia/AIZO/Projekt1/Lib/Algorithms.cpp" 2
