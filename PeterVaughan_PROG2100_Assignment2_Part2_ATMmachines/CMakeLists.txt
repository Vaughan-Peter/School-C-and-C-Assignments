cmake_minimum_required(VERSION 3.29)
project(PeterVaughan_PROG2100_Assignment2_ATMmachines)

set(CMAKE_CXX_STANDARD 20)

add_executable(PeterVaughan_PROG2100_Assignment2_ATMmachines main.cpp
        start.h
        printIntroMenu.h
        printMainMenu.h
        createAccount.h
        login.h
        testing.h
        wipeData.h)
