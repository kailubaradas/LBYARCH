float dot_product_c(const float* a, const float* b, int n) {
    float sdot = 0.0f;
    for (int i = 0; i < n; i++) {
        sdot += a[i] * b[i];
    }
    return sdot;
}
