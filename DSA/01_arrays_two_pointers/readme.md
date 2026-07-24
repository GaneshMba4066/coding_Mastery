# 01. Arrays & The Two-Pointer Technique

**Core Concept:** Using two variables to point to different indices in an array to solve a problem in a single pass $O(n)$, avoiding a nested double loop $O(n^2)$.

## 🧠 Engineering Reality & Mental Models

1. **Why Arrays Rule the Hardware:** Arrays are contiguous blocks of memory. Whether you are allocating a static buffer in an RTOS or flattening a matrix for a neural network, arrays play perfectly with the CPU's L1 cache. The CPU grabs a full cache line all at once, making sequential reads nearly instantaneous.
2. **The "Space for Time" Tradeoff:** The classic "Two Sum" problem (finding two numbers that add up to a target) can be solved in $O(n)$ time using a Hash Map, but that requires $O(n)$ extra memory. If the array is sorted, the Two-Pointer technique solves it in $O(n)$ time using exactly $O(1)$ memory. In constrained environments, avoiding dynamic allocation is the winning strategy.
3. **Pointers vs. Indices:** High-level application languages use indices (`left = 0`). In C, you can use actual memory addresses (pointers) to slide through the array, skipping the ALU math required to calculate index offsets at runtime.
