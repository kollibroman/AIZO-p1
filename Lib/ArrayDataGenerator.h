#ifndef ARRAYDATAGENERATOR_H
#define ARRAYDATAGENERATOR_H
#include<random>

#include "Algorithms.h"

template <typename T> class ArrayDataGenerator
{
    public:
        ArrayDataGenerator() = default;

        T *GenerateData(int n)
        {
            std::random_device rd;
            std::mt19937 gen(rd());

            T *tab = new T[n];

            if(typeid(T).name() == typeid(int).name())
            {
                std::uniform_int_distribution<int> distribution(0, 1000);

                for(int i = 0; i < n; i++)
                {
                    tab[i] = static_cast<int>(distribution(gen));
                }
            }

            else if(typeid(T).name() == typeid(float).name())
            {
                std::uniform_real_distribution<float> dist(0.0, 1000.0);

                for(int i = 0; i < n; i++)
                {
                    tab[i] = static_cast<float>(dist(gen));
                }
            }

            return tab;
        }

        T *Generate33PercentSortedData(int n)
        {
            T *tab = new T[n];

            tab = this->GenerateData(n);
            auto algorithms = new Algorithms<T>();

            algorithms->QuickSort(tab, 0, (n - 1)/3);

            return tab;
        }

        T *Generate50PercentSortedData(int n)
        {
            T *tab = new T[n];

            tab = this->GenerateData(n);
            auto algorithms = new Algorithms<T>();

            algorithms->QuickSort(tab, 0, (n - 1)/2);

            return tab;
        }

        T *Generate66PercentSortedData(int n)
        {
            T *tab = new T[n];

            tab = this->GenerateData(n);
            auto algorithms = new Algorithms<T>();

            algorithms->QuickSort(tab, 0, (n - 1)*0.66);

            return tab;
        }

        T *GenerateSortedData(int n)
        {
            T *tab = new T[n];

            tab = this->GenerateData(n);
            auto algorithms = new Algorithms<T>();

            algorithms->QuickSort(tab, 0, n - 1);

            return tab;
        }
};

#endif //ARRAYDATAGENERATOR_H
