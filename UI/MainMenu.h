#ifndef MAINMENU_H
#define MAINMENU_H

#include <iostream>
#include <vector>
#include "../Util/UserInputStorer.h"
#include "../Lib/ArrayDataGenerator.h"
#include "../Util/ArrayStorer.h"
#include "../Lib/FileReader.h"

class MainMenu
{
public:
    int GENERATION_COUNT = 1000;
    int ARRAY_SIZE = 100000;

    explicit MainMenu(UserInputStorer *&userInput, ArrayStorer<int> *&intArrayStorer, ArrayStorer<float> *&floatArrayStorer)
    {
            std::cout<< "Menu programu" << std::endl;

            std::vector<std::string> options =
            {
                "Wygeneruj dane danego typu (1)",
                "Wczytaj dane z pliku (2)",
                "Opusc program (3)"
            };

            int choice;

            for (auto option : options)
            {
                std::cout << option << std::endl;
            }

            std::cin >> choice;

            switch (choice)
            {
                case 1:
                    userInput->Option = choice;
                    ChooseDataType(userInput);
                    ChooseAlgorithm(userInput);
                    HandleDataGeneration(userInput, intArrayStorer, floatArrayStorer);
                    break;

                case 2:
                    userInput->Option = choice;
                    ChooseDataType(userInput);
                    ChooseAlgorithm(userInput);
                    HandleDataRead(userInput, intArrayStorer, floatArrayStorer);
                    break;

                case 3:
                    std::cout << "Koncze prace programu" << std::endl;
                    return;

                default:
                    std::cout << "Wrong input" << std::endl;
                    break;
            }
    }

private:

    void ChooseAlgorithm(UserInputStorer* &userInput)
    {
        std::cout<< "Menu programu" << std::endl;

        std::vector<std::string> options =
        {
            "Sortowanie szybkie (1)",
            "Sortowanie przez wstawianie (2)",
            "Sortowanie przez wstawianie binarne (3)",
            "Sortowanie przez kopcowanie (4)"
        };

        int choice;

        for (auto option : options)
        {
            std::cout << option << std::endl;
        }

        std::cin >> choice;

        switch(choice)
        {
            case 1:
                std::cout << "Wybrano sortowanie szybkie" << std::endl;
                userInput->ChosenAlgorithm = choice;
                break;

            case 2:
                std::cout << "Wybrano sortowanie przez wstawianie" << std::endl;
                userInput->ChosenAlgorithm = choice;
                break;

            case 3:
                std::cout << "Wybrano sortowanie przez wstawianie binarne" << std::endl;
                userInput->ChosenAlgorithm = choice;
                break;

            case 4:
                std::cout << "Wybrano sortowanie przez kopcowanie" << std::endl;
                userInput->ChosenAlgorithm = choice;
                break;

            default:
                std::cout << "nieakceptowalny wybor" << std::endl;
                break;
        }
    }

    void ChooseDataType(UserInputStorer* &userInput)
    {
        std::cout<< "Wybierz typ danych" << std::endl;

        std::vector<std::string> options =
        {
            "Int (1)",
            "Float (2)",
        };

        int choice;

        for (auto option : options)
        {
            std::cout << option << std::endl;
        }

        std::cin >> choice;

        switch(choice)
        {
            case 1:
                std::cout << "Wybrano int" << std::endl;
                userInput->DataType = "int";
                break;

            case 2:
                std::cout << "Wybrano float" << std::endl;
                userInput->DataType = "float";
                break;

            default:
                std::cout << "nieakceptowalny wybor" << std::endl;
                break;
        }
    }

    void HandleDataGeneration(UserInputStorer *&userInput, ArrayStorer<int> *&intArrayStorer, ArrayStorer<float> *&floatArrayStorer)
    {
        for (int i = 0; i < GENERATION_COUNT; i++)
        {
            if (userInput->DataType == "int")
            {
                auto arrayDataGenerator = new ArrayDataGenerator<int>();
                int *tab = arrayDataGenerator->GenerateData(ARRAY_SIZE);
                intArrayStorer->Arrays[i] = tab;
            }

            else if (userInput->DataType == "float")
            {
                auto arrayDataGenerator = new ArrayDataGenerator<float>();
                float *tab = arrayDataGenerator->GenerateData(ARRAY_SIZE);
                floatArrayStorer->Arrays[i] = tab;
            }
        }
    }

    void HandleDataRead(UserInputStorer *&userInput, ArrayStorer<int> *&intArrayStorer, ArrayStorer<float> *&floatArrayStorer)
    {
        std::cout << "Podaj nazwe pliku" << std::endl;
        std::string fileName;
        std::cin >> fileName;

        if(fileName.find(".txt") == std::string::npos)
        {
            fileName += ".txt";
        }

        for (int i = 0; i < GENERATION_COUNT; i++)
        {
            if (userInput->DataType == "int")
            {
                auto fileReader = new FileReader<int>();
                int *tab = fileReader->ReadFile(fileName);
                intArrayStorer->Arrays[i] = tab;
            }

            else if (userInput->DataType == "float")
            {
                auto fileReader = new FileReader<float>();
                float *tab = fileReader->ReadFile(fileName);
                floatArrayStorer->Arrays[i] = tab;
            }
        }
    }
};

#endif //MAINMENU_H
