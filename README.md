# Dot Product Kernel Implementation

## Overview
This project implements a dot product kernel in both:
1. **C** using scalar floating-point operations.
2. **x86-64 Assembly** using functional scalar SIMD instructions.

The goal is to compare the performance of the C and assembly versions over various vector sizes and validate their correctness.

---

## Instructions

### Prerequisites
- GCC compiler for C code.
- NASM assembler for x86-64 assembly.
- A system with a 64-bit architecture.

### Files
- **main.c**: The main driver program.
- **dot_product_c.c**: Contains the C implementation of the dot product kernel.
- **dot_product_asm.asm**: Contains the x86-64 assembly implementation of the dot product kernel.
- **README.md**: Project documentation.

---

## Build Instructions

### Using Command Line
1. Assemble the assembly kernel:
   ```bash
   nasm -f elf64 dot_product_asm.asm -o dot_product_asm.o

## Results and Comparative Analysis

### Performance Results (Placeholders)

| Vector Size (n) | C Kernel Result | C Kernel Avg Time (s) | Assembly Kernel Result | Assembly Kernel Avg Time (s) | Correctness |
|------------------|-----------------|------------------------|-------------------------|-------------------------------|-------------|
| 2^20            | **TBD**         | **TBD**                | **TBD**                 | **TBD**                       | **TBD**     |
| 2^24            | **TBD**         | **TBD**                | **TBD**                 | **TBD**                       | **TBD**     |
| 2^30            | **TBD**         | **TBD**                | **TBD**                 | **TBD**                       | **TBD**     |

---

### Analysis

#### 1. **Execution Speed**
The table above demonstrates the average execution times for both the C and Assembly implementations across different vector sizes. Key observations will include:
- **Scalability**: How execution times scale as the vector size increases.
- **Performance Gains**: Quantify the speedup achieved by the Assembly implementation compared to the C version. This is calculated using:
  \[
  \text{Speedup} = \frac{\text{C Kernel Avg Time}}{\text{Assembly Kernel Avg Time}}
  \]

#### 2. **Correctness**
The results must validate that the Assembly implementation produces the same result as the C implementation for all vector sizes. Correctness is evaluated based on:
- Absolute difference between the two results:
  \[
  | \text{C Kernel Result} - \text{Assembly Kernel Result} | < \epsilon
  \]
  where \( \epsilon \) is a small threshold (e.g., \(10^{-5}\)).
- If the Assembly kernel fails the correctness check for any vector size, the issue will be investigated and documented.

#### 3. **Resource Utilization**
Assembly kernels are expected to show lower overhead due to direct use of hardware instructions (e.g., `mulss`, `addss`). However, this might come with the cost of increased complexity in code maintenance.

#### 4. **Impact of SIMD Instructions**
The Assembly implementation utilizes scalar SIMD instructions (`movss`, `mulss`, `addss`) for floating-point operations. Analysis will compare:
- Whether SIMD instructions result in measurable performance improvements.
- The potential benefits of extending this to parallel SIMD operations (e.g., `mulps` for parallel multiplication).

---

### Key Takeaways (Once Results Are Available)
1. **Performance Difference**:
   - Quantify the performance improvement achieved by Assembly over C for each vector size.
   - Discuss whether the speedup justifies the added complexity of writing Assembly code.

2. **Scalability**:
   - Highlight how both implementations handle increasing vector sizes.
   - Assess whether Assembly optimizations maintain performance gains as the workload scales.

3. **Recommendations**:
   - If Assembly provides significant performance benefits, recommend its use for high-performance scenarios.
   - If performance gains are marginal, suggest sticking with the C implementation for simplicity.

---

### Future Work
The comparative analysis of these results will inform the following potential enhancements:
1. Experiment with **parallel SIMD instructions** (e.g., `mulps`, `addps`) to achieve better performance for larger vector sizes.
2. Extend support for **double-precision floating-point numbers** using instructions like `movsd`, `mulsd`, and `addsd`.
3. Profile memory and CPU usage to provide deeper insights into resource efficiency.

---
