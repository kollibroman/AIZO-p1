#ifndef FILEREADER_H
#define FILEREADER_H
#include<fstream>
#include<string>
#include<algorithm>

template <typename T> class FileReader
{
public:
    T *ReadFile(std::string path)
    {
        std::ifstream file(path);
        std::string line;
        int base_size = 0;

        T *tab;

        //Wywalamy pierwsza linijke
        if (std::getline(file, line))
        {
        }

        // Dynamicznie wpisuję rzeczy z plików do tablicy
        while (file >> line)
        {
            T *temp = new T[base_size];
            for (int i = 0; i < base_size; i++)
            {
                temp[i] = tab[i];
            }

            base_size++;

            tab = new T[base_size];
            for (int i = 0; i < base_size - 1; i++)
            {
                tab[i] = temp[i];
            }

            if (IsFloat(line) == false)
            {
                tab[base_size - 1] = std::stoi(line);
            }

            else if(IsFloat(line))
            {
                std::ranges::replace(line, ',', '.');
                tab[base_size - 1] = std::stof(line);
            }

            else
            {
                std::cout << "Niepoprawne dane w pliku" << std::endl;
                return nullptr;
            }

            delete[] temp;
        }

        file.close();
        return tab;
    }

private:
    static bool IsFloat(std::string line)
    {
        return line.find(',') != std::string::npos || line.find('.') != std::string::npos;
    }
};

#endif //FILEREADER_H
