#include <iostream>
#include "FileHandle.h"
#include <string>

FileHandle::FileHandle(const char* fileName)
{
    errno_t err = fopen_s(&file_, fileName, "r");

    if (err != 0 || file_ == nullptr)
    {
        std::cout << "Failed to open file: "
            << fileName << '\n';

        file_ = nullptr;
        return;
    }

    std::cout << "Successfully opened file: "
        << fileName << '\n';
}

FileHandle::~FileHandle()
{
    if (file_ != nullptr)
    {
        std::fclose(file_);

        std::cout << "Successfully closed file\n";
    }
}

void FileHandle::writeData(const std::string& data)
{
    // 假設遇到了某種錯誤情境
    bool isDiskFull = true;

    if (isDiskFull)
    {
        std::cout << "throw exception\n";
        throw std::runtime_error("exception error!");
    }

    std::cout << "Writing data success" << data << '\n';
}
