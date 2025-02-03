cmake_minimum_required(VERSION 3.27)
project(HW4)

set(CMAKE_CXX_STANDARD 11)

add_executable(HW4 main.cpp
        Account.h
        SavingsAccount.cpp
        SavingsAccount.h
        CheckingAccount.cpp
        CheckingAccount.h
        Array.h
        Account.cpp
        Menu.cpp)
