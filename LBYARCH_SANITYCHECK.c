#include <stdio.h>
   #include <stdlib.h>
   #include <time.h>

   #define BILLION 1000000000.0

   float dot_product_c(const float* A, const float* B, int n) {
       float sdot = 0.0;
       for (int i = 0; i < n; i++) {
           sdot += A[i] * B[i];
       }
       return sdot;
   }

   int main() {
       int n = (1 << 20); // Change n for different test cases
       float *A = (float*) malloc(n * sizeof(float));
       float *B = (float*) malloc(n * sizeof(float));

       // Initialize vectors with random values
       srand(time(NULL));
       for (int i = 0; i < n; i++) {
           A[i] = (float) rand() / RAND_MAX;
           B[i] = (float) rand() / RAND_MAX;
       }

       // Repeat the computation to get more stable timing
       int iterations = 1000;
       struct timespec start, end;
       clock_gettime(CLOCK_MONOTONIC, &start);
       float result = 0.0;

       for (int i = 0; i < iterations; i++) {
           result = dot_product_c(A, B, n);
       }

       clock_gettime(CLOCK_MONOTONIC, &end);
       double time_taken = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / BILLION;
       double average_time = time_taken / iterations;

       printf("Dot Product (C version): %f\n", result);
       printf("Average execution time: %lf seconds\n", average_time);

       free(A);
       free(B);
       return 0;
   }
