#pragma once

#include <cstdio>
#include <string>

class FileHandle
{
public:
    explicit FileHandle(const char* fileName);
    ~FileHandle();

    FileHandle(const FileHandle&) = delete;
    FileHandle& operator=(const FileHandle&) = delete;

    FileHandle(FileHandle&& source)noexcept;
    FileHandle& operator=(FileHandle&& source)noexcept;

private:
    FILE* file_ = nullptr;
};