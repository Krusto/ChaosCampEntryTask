#pragma once

#include <iostream>
#include <string>

template <typename T>
void Log(T first)
{
    std::cout << first;
}

template <typename T, class... Args>
void Log(T first, Args... args)
{
    std::cout << first;
    Log(args...);
}
