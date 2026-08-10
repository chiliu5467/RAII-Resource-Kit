#include <iostream>
#include <cstdio> // Include necessary header for file operations

class FileHandle
{
public:
    FileHandle(const char* fileName)
    {
        errno_t err = fopen_s(&file_, fileName, "r"); // Use fopen_s correctly
        if (err != 0 || file_ == nullptr) // Check for errors
        {
            std::cout << "Failed to open file: " << fileName << std::endl;
            file_ = nullptr; // Ensure file_ is null if opening fails
            return;
        }

        std::cout << "Successfully opened file: " << fileName << std::endl;
    }

    ~FileHandle()
    {
        if (file_ != nullptr)
        {
            std::fclose(file_);
            std::cout << "Successfully closed file" << std::endl;
        }
        else
        {
            std::cout << "No file need to be closed" << std::endl;
        }
    }

    FileHandle(const FileHandle&) = delete; // Disable copy constructor
    FileHandle& operator=(const FileHandle&) = delete; // Disable copy assignment

private:
    FILE* file_ = nullptr; // File pointer
};

void Test()
{
    FileHandle file("test.txt");
}

int main()
{
    Test();
    return 0;
}
