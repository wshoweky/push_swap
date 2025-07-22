# 🚀 push_swap

## 📝 Overview

**push_swap** is a sorting algorithm project from the 42 school curriculum. The goal is to sort a stack of integers using a limited set of stack operations, outputting the shortest possible sequence of instructions. The project is a test of algorithmic thinking, optimization, and careful handling of edge cases.

## 🧩 Stack Operations

The only allowed operations are:
- `sa`, `sb`, `ss`: swap the top two elements of stack A, B, or both.
- `pa`, `pb`: push the top element from one stack to the other.
- `ra`, `rb`, `rr`: rotate stack A, B, or both (top element becomes last).
- `rra`, `rrb`, `rrr`: reverse rotate stack A, B, or both (last element becomes top).

## 🧠 Project Logic

### 🛠️ Input Handling

- The program accepts input as either a single quoted string or as multiple arguments.
- It robustly checks for invalid, empty, or mixed input and handles errors gracefully.

### 🔄 Sorting Logic

#### 🟢 Small Inputs (2–5 elements)
- For very small stacks, the program uses hardcoded, optimal solutions to minimize the number of operations.

#### 🔵 Large Inputs (Double Stack Radix Sort)
- For larger stacks, the program uses an **optimized double stack binary radix sort** algorithm:

  1. **Indexing:** Each value is replaced by its index in the sorted order (0 for smallest, N-1 for largest).

  2. **Bitwise Sorting with Two Stacks:**
     - The algorithm processes the stack bit by bit, starting from the least significant bit (LSB) to the most significant bit (MSB).
     - For each bit position:
      - **Step 1 (A to B):**
       - For every element in stack A, check the current bit:
        - If the bit is 0, push the element to stack B (`pb`).
        - If the bit is 1, rotate stack A (`ra`).
        - This separates elements based on the current bit: 0-bits go to B, 1-bits stay in A (but rotated).
      - **Step 2 (B to A):**
       - For the next bit position, process stack B:
       - For every element in B, check the next bit:
        - If the bit is 1, push the element back to A (`pa`).
        - If the bit is 0, rotate stack B (`rb`).
        - This further filters and moves elements back to A as soon as they are ready for the next bit pass.
     - This alternation between A and B continues for each bit position, efficiently filtering and moving elements closer to their sorted position with each pass.

  3. **Final Restoration:**
     - After all bit positions have been processed, any remaining elements in B are pushed back to A.

- **Why Radix Sort?**  
  Radix sort is chosen for its O(n log n) complexity and its ability to work efficiently with the allowed stack operations, even for large input sizes.

### 🚨 Error Handling

- The program prints `"Error"` to `stderr` and exits if the input is invalid, contains duplicates, or is out of integer bounds.

## ⚡ Usage

```sh
make
./push_swap 3 2 1
# or
./push_swap "3 2 1"
```

## 📦 Example Output

```
sa
rra
```

---

## 💡 Notes

- The project is written in C and uses a custom linked list implementation for stack management.
- The code is optimized for both correctness and operation count, especially for small input sizes.

---

## 🌐 Helpful Resources

- 📚 [Notion push_swap Guide](https://suspectedoceano.notion.site/push_swap-ee2c472005d54d978412bfc37a1ab3e7)
- 📖 [42 Cursus push_swap Guide (GitBook)](https://42-cursus.gitbook.io/guide/2-rank-02/push_swap)
- 📝 [Push_swap Tutorial (Medium)](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
- 🎥 [Radix Sort Algorithm Introduction (YouTube)](https://www.youtube.com/watch?v=XiuSW_mEn7g)
- 💻 [Reference Implementation by hu8813 (GitHub)](https://github.com/hu8813/push_swap)
- 🧪 [Push-Swap-Tester by gemartin99 (GitHub)](https://github.com/gemartin99/Push-Swap-Tester)
- 🖥️ [push_swap_visualizer by o-reo (GitHub)](https://github.com/o-reo/push_swap_visualizer)
- 👀 [push_swap42 Visualizer (Web)](https://push-swap42-visualizer.vercel.app/)


---

😎 Happy coding and good luck with your push_swap journey!
