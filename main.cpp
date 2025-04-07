#include <iostream>
#include "Util/UserInputStorer.h"
#include <chrono>

#include "Testing/Reporter.h"
#include "UI/MenuUtils.h"

int main()
{
    int GENERATION_COUNT = 10;
    int ARRAY_SIZE = 100;

    int option;

    std::cout << "Wybierz dzialanie programu: " << std::endl;
    std::cout << "Interaktywne menu do sprawdzania (1) " << std::endl;
    std::cout << "Generacja danych do sprawozdania (2) " << std::endl;
    std::cout << "Zakończ program (3) " << std::endl;
    std::cin >> option;

    if (option == 1)
    {
        auto userInputStorer = new UserInputStorer(0, "");

        auto menuUtils = new MenuUtils(userInputStorer);

        delete userInputStorer;
    }

    else if (option == 2)
    {
        //Odpalać na własną odpowiedzialnośc - wszystkie 7 instukcji wykonywało się 7h
        auto reporter = new Reporter();

        reporter->GenerateRandomArrayData(100, 5000, "../5000");
        reporter->GenerateRandomArrayData(100, 10000, "../10000");
        reporter->GenerateRandomArrayData(100, 20000, "../20000");
        reporter->GenerateRandomArrayData(100, 40000, "../40000");
        reporter->GenerateRandomArrayData(100, 60000, "../60000");
        reporter->GenerateRandomArrayData(100, 80000, "../80000");
        reporter->GenerateRandomArrayData(100, 100000, "../100000");
    }

    else
    {
        return 0;
    }

    return 0;
}