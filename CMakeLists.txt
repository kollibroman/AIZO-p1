cmake_minimum_required(VERSION 3.30)
project(Projekt1)

set(CMAKE_CXX_STANDARD 20)

project(Projekt1 LANGUAGES CXX VERSION 1.0.0)
add_executable(Projekt1 main.cpp
        Lib/Algorithms.h
        Lib/FileReader.h
        Lib/ArrayDataGenerator.h
        Lib/CsvGenerator.h
        UI/MainMenu.h
        Util/UserInputStorer.h)


