# RAII Resource Kit

A small C++ project demonstrating RAII, resource ownership, and move semantics through a custom `FileHandle` wrapper around `FILE*`.

## Concepts

- RAII
- Object lifetime
- Resource ownership
- Copy restrictions
- Move constructor
- Move assignment
- Exception-safe cleanup
- Rule of Five

## FileHandle

`FileHandle` owns a `FILE*` and automatically closes it in its destructor.

Copying is disabled to prevent multiple objects from owning the same file handle:

```cpp
FileHandle(const FileHandle&) = delete;
FileHandle& operator=(const FileHandle&) = delete;
```

Moving is supported so ownership can be transferred safely:

```cpp
FileHandle(FileHandle&& other) noexcept;
FileHandle& operator=(FileHandle&& other) noexcept;
```

## What I Tested

- Normal scope exit
- Early return
- Exception stack unwinding
- Copy restrictions
- Move construction
- Move assignment
- Self-move assignment
- Compile-time checks with `static_assert`

## Build

Requirements:

- Visual Studio 2022
- C++17 or later

Open `RAII-Resource-Kit.sln`, build the solution, and run the executable.

## Key Takeaways

- RAII ties resource lifetime to object lifetime.
- `FILE*` acquired with `fopen` / `fopen_s` must be released with `fclose`.
- Exclusive resources should not be shallow-copied.
- Move semantics allow safe ownership transfer.
- A program not crashing does not necessarily mean the code is correct.
