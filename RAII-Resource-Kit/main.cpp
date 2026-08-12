#include "FileHandle.h"

#include <iostream>
#include <stdexcept>
#include <type_traits>

static_assert(!std::is_copy_constructible_v<FileHandle>, "FileHandle should not be copy constructible");
static_assert(!std::is_copy_assignable_v<FileHandle>, "FileHandle should not be copy assignable");

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