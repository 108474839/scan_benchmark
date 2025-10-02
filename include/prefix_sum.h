#pragma once
#include <string>

enum class Algorithm {
    NAIVE,
    CPU_PARALLEL,
    CPU_SIMD,
    GPU_CUDA,
};

void prefix_sum(float* data, int n, Algorithm algo);

Algorithm parse_algorithm(const std::string& algo_str);