#ifndef USERINPUTSTORER_H
#define USERINPUTSTORER_H
#include <iostream>

//Struct gdzie przechowywane są dane wprowadzone przez użytkownika
struct UserInputStorer
{
       UserInputStorer(int option, std::string dataType, int chosenAlgorithm)
       {
              Option = option;
              DataType = dataType;
              ChosenAlgorithm = chosenAlgorithm;
       }
       
       int Option;
       std::string DataType;
       int ChosenAlgorithm;
};

#endif //USERINPUTSTORER_H
