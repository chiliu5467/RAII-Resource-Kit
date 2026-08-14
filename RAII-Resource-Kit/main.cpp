#include "FileHandle.h"

#include <iostream>
#include <utility>

static_assert(!std::is_copy_constructible_v<FileHandle>, "FileHandle should not be copy constructible");
static_assert(!std::is_copy_assignable_v<FileHandle>, "FileHandle should not be copy assignable");
static_assert(std::is_move_constructible_v<FileHandle>, "FileHandle should be move constructible");
static_assert(std::is_move_assignable_v<FileHandle>, "FileHandle should be move assignable");

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

void TestMoveConstructor()
{
    FileHandle file1("test.txt");
    FileHandle file2 = std::move(file1);
}

void TestMoveAssignment()
{
    FileHandle file1("test.txt");
    FileHandle file2("test.txt");

    file2 = std::move(file1);
}

void TestMoveSelfAssignment()
{
    FileHandle file("test.txt");
    file = std::move(file);
}

int main()
{
    TestNormalReturn();
	TestEarlyReturn();
    TestException();
    TestMoveConstructor();
    TestMoveAssignment();
    TestMoveSelfAssignment();
    return 0;
}