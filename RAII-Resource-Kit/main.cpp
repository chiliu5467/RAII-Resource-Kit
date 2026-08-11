#include "FileHandle.h"
#include <iostream>


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
		file.writeData("Hello");
    }
    catch (...)
    {
        std::cout << "\n[catch 區塊] 捕捉到未知的例外！\n";
    }

    std::cout << "--- 程式正常繼續往下執行 ---\n";
}

int main()
{
    TestNormalReturn();
    TestEarlyReturn();
    TestException();
    return 0;
}