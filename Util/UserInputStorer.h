#ifndef USERINPUTSTORER_H
#define USERINPUTSTORER_H
#include <iostream>
#include <utility>

//Struct gdzie przechowywane są dane wprowadzone przez użytkownika
struct UserInputStorer
{
       UserInputStorer(int option, std::string dataType): ChosenAlgorithm(0) {
              Option = option;
              DataType = std::move(dataType);
       }

       int Option;
       std::string DataType;
       int ChosenAlgorithm;
};

#endif //USERINPUTSTORER_H
