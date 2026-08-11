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

private:
    FILE* file_ = nullptr;
};