#include "FileHandle.h"

#include <iostream>

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

FileHandle::FileHandle(FileHandle&& source)noexcept
    : file_{ source.file_ }
{
    // 1. 紀錄轉移前的資源指標
    void* old_resource = source.file_;

    // 2. 轉移所有權（歸零 source）
    source.file_ = nullptr;

    // 3. 印出完整轉移歷程
    std::cout << "[Move Constructor] Object (" << this << ")"
        << " stole file handle [" << old_resource << "]"
        << " from Source (" << &source << ")."
        << " Source is now nullptr.\n";
}

FileHandle& FileHandle::operator=(FileHandle&& source)noexcept  
{  
    if (this == &source)
    {
        std::cout << "[Move Assignment] Self-assignment detected for Object (" << this << "), skipped.\n";
        return *this;
    }

    if (file_ != nullptr)
    {
        std::cout
            << "[Move Assignment] Object (" << this
            << ") releasing old file handle ["
            << file_ << "].\n";

		std::fclose(file_); // Cannot use delete here because file_ is a FILE* pointer, not a dynamically allocated memory pointer.
    }

    // 轉移所有權
    file_ = source.file_;
    source.file_ = nullptr;

    std::cout
        << "[Move Assignment] Object (" << this
        << ") stole file handle [" << file_
        << "] from Source (" << &source
        << "). Source is now nullptr.\n";

    return *this;
}
