main.c #include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Prototypes for kernels
float dot_product_c(const float* a, const float* b, int n); // C kernel
//extern float dot_product_asm(const float* a, const float* b, int n); // Assembly kernel

// Initialize vectors with random values
void initialize_vectors(float* a, float* b, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = (float)rand() / RAND_MAX;
        b[i] = (float)rand() / RAND_MAX;
    }
}

int main() {
    // Size of vectors
    int n = 1 << 20; // 2^20, adjust to 2^24 or higher for testing

    // Allocate memory for vectors
    float* a = (float*)malloc(n * sizeof(float));
    float* b = (float*)malloc(n * sizeof(float));
    if (!a || !b) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    // Initialize vectors
    initialize_vectors(a, b, n);

    //---------------------Run and time the C kernel ---------------------
    float sdot_c = 0.0f;
    clock_t start = clock();
    for (int i = 0; i < 20; i++) { // Run kernel 20 times for averaging
        sdot_c = dot_product_c(a, b, n);
    }
    clock_t end = clock();
    double c_time = ((double)(end - start) / CLOCKS_PER_SEC) / 20;

    printf("C Kernel Result: %f\n", sdot_c);
    printf("C Kernel Average Time: %f seconds\n", c_time);

    // --------------------- Run and time the Assembly kernel ---------------------
    float sdot_asm = 0.0f;
    start = clock();
    for (int i = 0; i < 20; i++) { // Run kernel 20 times for averaging
        //sdot_asm = dot_product_asm(a, b, n);
    }
    end = clock();
    double asm_time = ((double)(end - start) / CLOCKS_PER_SEC) / 20;

    //printf("Assembly Kernel Result: %f\n", sdot_asm);
    //printf("Assembly Kernel Average Time: %f seconds\n", asm_time);

    //--------------------- opt: Correctness check ---------------------
    if (fabs(sdot_c - sdot_asm) < 1e-5) {
        printf("Assembly Kernel Correctness: PASSED\n");
    }
    else {
        printf("Assembly Kernel Correctness: FAILED\n");
    }

    // Free memory
    free(a);
    free(b);

    return 0;
}
