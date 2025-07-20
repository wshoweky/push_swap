# push_swap

## Overview

**push_swap** is a sorting algorithm project from the 42 school curriculum. The goal is to sort a stack of integers using a limited set of stack operations, outputting the shortest possible sequence of instructions. The project is a test of algorithmic thinking, optimization, and careful handling of edge cases.

## Stack Operations

The only allowed operations are:
- `sa`, `sb`, `ss`: swap the top two elements of stack A, B, or both.
- `pa`, `pb`: push the top element from one stack to the other.
- `ra`, `rb`, `rr`: rotate stack A, B, or both (top element becomes last).
- `rra`, `rrb`, `rrr`: reverse rotate stack A, B, or both (last element becomes top).

## Project Logic

### Input Handling

- The program accepts input as either a single quoted string or as multiple arguments.
- It robustly checks for invalid, empty, or mixed input and handles errors gracefully.

### Sorting Logic

#### Small Inputs (2–5 elements)
- For very small stacks, the program uses hardcoded, optimal solutions to minimize the number of operations.

#### Large Inputs (Radix Sort)
- For larger stacks, the program uses a **binary radix sort** algorithm:
  1. **Indexing:** Each value is replaced by its index in the sorted order (0 for smallest, N-1 for largest).
  2. **Bitwise Sorting:** For each bit position (from least to most significant), the program:
     - Pushes elements with a `0` in the current bit to stack B.
     - Rotates elements with a `1` in the current bit to the bottom of stack A.
  3. **Restoration:** After each bit pass, all elements from stack B are pushed back to stack A.
  4. This process is repeated for each bit position until the stack is sorted.

- **Why Radix Sort?**  
  Radix sort is chosen for its O(n log n) complexity and its ability to work efficiently with the allowed stack operations, even for large input sizes.

### Error Handling

- The program prints `"Error"` to `stderr` and exits if the input is invalid, contains duplicates, or is out of integer bounds.

## Usage

```sh
make
./push_swap 3 2 1
# or
./push_swap "3 2 1"
```

## Example Output

```
pb
sa
pa
```

---

## Notes

- The project is written in C and uses a custom linked list implementation for stack management.
- The code is optimized for both correctness and operation count, especially for small input sizes.

---
