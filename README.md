# RAII Resource Kit

A small C++ learning project for exploring RAII,
resource ownership, and object lifetime.

## Concepts

- RAII
- Object lifetime
- Constructor and destructor
- Resource ownership
- Non-copyable resource handles

## FileHandle

`FileHandle` wraps a `FILE*`.

The file is opened when the object is created and
automatically closed when the object's lifetime ends.

Copy operations are disabled because two `FileHandle`
objects should not independently own the same `FILE*`.

## What I tested

- Normal scope exit
- Early return
- Exception
