#include "../include/naive.h"

void naive_prefix_sum(float* data, int n) {
    for(int i = 1; i < n; ++i) {
        data[i] += data[i - 1];
    }
}