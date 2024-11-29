#include <stdio.h>
   #include <stdlib.h>
   #include <time.h>

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

       clock_t start = clock();
       float result = dot_product_c(A, B, n);
       clock_t end = clock();
       printf("Dot Product (C version): %f\n", result);
       printf("Execution time: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

       free(A);
       free(B);
       return 0;
   }
