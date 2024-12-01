#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Prototypes for kernels
float dotProduct(int length, float* arrayX, float* arrayY); // C kernel
extern float dotProduct(int length, float* arrayX, float* arrayY); // Assembly kernel

// C kernel implementation
float dotProduct(int length, float* arrayX, float* arrayY) {
    float resultSum = 0.0f;
    for (int i = 0; i < length; i++) {
        resultSum += arrayX[i] * arrayY[i];
    }
    return resultSum;
}

// Initialize vectors with random values
void initializeVectors(float* arrayX, float* arrayY, int length) {
    for (int i = 0; i < length; i++) {
        arrayX[i] = ((float)rand() / (float)(RAND_MAX)) * 100.0f;
        arrayY[i] = ((float)rand() / (float)(RAND_MAX)) * 100.0f;
    }
}

int main() {
    // Size of vectors
    int length = 1 << 28; // 2^20

    // Allocate memory for vectors
    float* arrayX = (float*)malloc(length * sizeof(float));
    float* arrayY = (float*)malloc(length * sizeof(float));
    if (!arrayX || !arrayY) {
        printf("Error: Memory allocation failed.\n");
        return -1;
    }

    // Initialize vectors
    srand((unsigned int)time(NULL));
    initializeVectors(arrayX, arrayY, length);

    //--------------------- Run and time the C kernel ---------------------
    float cKernelResult = 0.0f;
    clock_t startClock = clock();
    for (int i = 0; i < 20; i++) { // Run kernel 20 times for averaging
        cKernelResult = dotProduct(length, arrayX, arrayY);
    }
    clock_t endClock = clock();
    double cKernelAverageTime = ((double)(endClock - startClock) / CLOCKS_PER_SEC) / 20;

    printf("C Kernel Result: %f\n", cKernelResult);
    printf("C Kernel Average Time: %f seconds\n", cKernelAverageTime);

    //--------------------- Run and time the Assembly kernel ---------------------
    float asmKernelResult = 0.0f;
    startClock = clock();
    for (int i = 0; i < 20; i++) { // Run kernel 20 times for averaging
        asmKernelResult = dotProduct(length, arrayX, arrayY);
    }
    endClock = clock();
    double asmKernelAverageTime = ((double)(endClock - startClock) / CLOCKS_PER_SEC) / 20;

    printf("Assembly Kernel Result: %f\n", asmKernelResult);
    printf("Assembly Kernel Average Time: %f seconds\n", asmKernelAverageTime);

    //--------------------- Correctness check ---------------------
    if (fabs(cKernelResult - asmKernelResult) < 1e-5) {
        printf("Assembly Kernel Correctness: PASSED\n");
    }
    else {
        printf("Assembly Kernel Correctness: FAILED\n");
    }

    // Free memory
    free(arrayX);
    free(arrayY);

    return 0;
}