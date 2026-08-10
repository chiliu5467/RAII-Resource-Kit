#include <iostream>
#include "FileHandle.h"

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
