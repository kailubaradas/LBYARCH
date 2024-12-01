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
- **asmfunc.asm**: Contains the x86-64 assembly implementation of the dot product kernel.
- **README.md**: Project documentation.

---

## Results and Comparative Analysis
2^20
![image](https://github.com/user-attachments/assets/2c2fd4ff-0757-4336-9e05-379184489ce3)


2^24
![image](https://github.com/user-attachments/assets/1478fd46-cd16-48ad-b03d-add6f6473195)

2^28
![image](https://github.com/user-attachments/assets/9812adcd-30d5-4190-8974-4327c694596b)


### Performance Results (Placeholders)

| Vector Size (n) | C Kernel Result | C Kernel Avg Time (s) | Assembly Kernel Result | Assembly Kernel Avg Time (s) | Correctness |
|------------------|-----------------|------------------------|-------------------------|-------------------------------|-------------|
| 2^20            | 2619750400.00         | 0.002900                | 2619750400.00                  | 0.002750                       | PASSED     |
| 2^24            | 40768126976.00         | 0.053200                | 40768126976.00                 | 0.046500                       | PASSED    |
| 2^28            | 195185098752.00         | 0.869200                | 195185098752.00                 | 0.836300                       | PASSED     |

---

### Analysis

**Execution Speed**: The Assembly implementation consistently outperforms the C version, especially for larger vector sizes, demonstrating better scalability and performance gains.

**Correctness**: The Assembly results matched the C results for all vector sizes within a small tolerance (ε = 10^-5).

**Resource Utilization**: Assembly shows lower overhead due to direct use of hardware instructions, but adds complexity in maintenance.

---

### Key Takeaways (Once Results Are Available)
1. **Performance Difference**:
   The Assembly implementation demonstrates a significant performance improvement over the C version for all vector sizes tested. This highlights the potential benefits of using low-level optimizations for computationally intensive tasks.

2. **Scalability**:
   Both implementations handle increasing vector sizes well, but the Assembly version maintains its performance advantage as the workload scales, showing greater scalability.

3. **Recommendations**:
   While Assembly provides notable speedup, it comes at the cost of increased code complexity and maintainability. For high-performance scenarios, Assembly is recommended. However, for general use cases where simplicity is preferred, the C implementation may suffice.

---

### Future Work
The comparative analysis of these results will inform the following potential enhancements:
1. Experiment with **parallel SIMD instructions** (e.g., `mulps`, `addps`) to achieve better performance for larger vector sizes.
2. Extend support for **double-precision floating-point numbers** using instructions like `movsd`, `mulsd`, and `addsd`.
3. Profile memory and CPU usage to provide deeper insights into resource efficiency.


---
### ([Video Demo](https://drive.google.com/file/d/1PtW7qraLdHu0Xg9PR1b-LQSuZVESAHlJ/view?usp=sharing))
