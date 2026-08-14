# RAII Resource Kit

A minimal C++ learning project exploring **RAII (Resource Acquisition Is Initialization)**, resource ownership transfer (move semantics), and object lifetime management.

## Concepts Covered

- RAII & Object Lifetime Management
- Constructor / Destructor pair for resource safety
- Resource Ownership & Single Ownership semantics
- Non-copyable resource handles (`delete` copy operations)
- Move semantics implementation (`std::move`, move ctor/assignment)
- Rule of Five / Rule of Zero

## Key Components

### `FileHandle`
A custom RAII wrapper around C-style `FILE*`.

* **Resource Allocation:** Opens the file upon object construction.
* **Automatic Cleanup:** Guarantees file closure when the object goes out of scope.
* **Copy Prevention:** Copy constructor and copy assignment are disabled to prevent duplicate ownership of the underlying `FILE*`.
* **Move Ownership:** Move operations allow explicit transfer of resource ownership.

## What I Tested

- [x] **Scope Safety:** Normal scope exit and early returns
- [x] **Exception Safety:** Automatic cleanup during stack unwinding
- [x] **Move Semantics:** Move constructor and move assignment
- [x] **Edge Cases:** Self-move assignment handling (`file = std::move(file)`)
- [x] **Moved-from State:** Ensuring object is in a valid but empty state post-move
- [x] **Compile-time Checks:** Verifying copy prevention at compile time

## Key Takeaways
- How RAII simplifies resource cleanup and guarantees exception safety.
- Designing predictable, leak-free C++ classes using the **Rule of Five**.
- Managing explicit resource handoffs via move semantics without accidental double-free errors.
