#include "FileHandle.h"
#include <iostream>
#include <stdexcept>

void TestNormalReturn()
{
    FileHandle file("test.txt");
}

void TestEarlyReturn()
{
    FileHandle file("test.txt");

    std::cout << "Before early return\n";

    return;

    std::cout << "This will never run\n";
}

void TestException()
{
    try
    {
        FileHandle file("test.txt");
        std::cout << "Before exception\n";
        throw std::runtime_error("Test exception");
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught exception: "
            << e.what() << '\n';
    }
}

int main()
{
    TestNormalReturn();
    TestEarlyReturn();
    TestException();
    return 0;
}