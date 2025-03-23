#ifndef ARRAYDATAGENERATOR_H
#define ARRAYDATAGENERATOR_H
#include<random>

template <typename T> class ArrayDataGenerator
{
    public:
        ArrayDataGenerator()
        {
        }

        T *GenerateData(int n)
        {
            T *tab = new T[n];

            for (int i = 0; i < n; i++)
            {
                if(typeid(T).name() == typeid(int).name())
                {
                    tab[i] = rand() % 1001;
                }

                else if(typeid(T).name() == typeid(float).name())
                {
                    float newFloat = std::round(static_cast<float>(std::rand()) / static_cast<float>(RAND_MAX) * 100) / 100;
                    tab[i] = newFloat + std::rand() % 1001;
                }
            }

            return tab;
        }

        T *Generate33PercentSortedData(int n)
        {
            T *tab = new T[n];

            for (T i = 0; i < n; i++)
            {
                if (i <= n / 3)
                {
                    tab[i] = i;
                }

                else
                {
                    tab[i] = rand() % 1001;
                }
            }

            return tab;
        }

        T *Generate50PercentSortedData(int n)
        {
            T *tab = new T[n];

            for (T i = 0; i < n; i++)
            {
                if (i <= n / 2)
                {
                    tab[i] = i;
                }

                else
                {
                    tab[i] = rand() % 1001;
                }
            }

            return tab;
        }

        T *Generate66PercentSortedData(int n)
        {
            T *tab = new T[n];

            for (T i = 0; i < n; i++)
            {
                if (i <= n * 2/3)
                {
                    tab[i] = i;
                }

                else
                {
                    tab[i] = rand() % 1001;
                }
            }

            return tab;
        }

        T *GenerateSortedData(int n)
        {
            T *tab = new T[n];

            for (T i = 0; i < n; i++)
            {
                tab[i] = i;
            }

            return tab;
        }
};

#endif //ARRAYDATAGENERATOR_H
