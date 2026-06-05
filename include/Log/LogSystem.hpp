#pragma once

#include <iostream>

namespace Log
{
    template <typename T>
    void info(T msg)
    {
        std::cout << "[Info]: " << msg << std::endl;
    }

    template <typename T>
    void error(T msg)
    {
        std::cout << "[Error]: " << msg << std::endl;
    }
}
