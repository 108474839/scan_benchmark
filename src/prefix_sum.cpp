#include "../include/prefix_sum.h"
#include "../include/naive.h"
#include "../include/cpu_parallel.h"
#include "../include/cpu_simd.h"
#ifdef USE_CUDA
#include "../gpu/gpu_cuda.cuh"
#endif
#include <stdexcept>

Algorithm parse_algorithm(const std::string& name) {
    if(name == "naive") return Algorithm::NAIVE;
    if(name == "cpu_parallel") return Algorithm::CPU_PARALLEL;
    if(name == "cpu_simd") return Algorithm::CPU_SIMD;
    if(name == "gpu") return Algorithm::GPU_CUDA;
    throw std::runtime_error("Unknown algorithm: " + name);
}

void prefix_sum(float* data, int n, Algorithm algo) {
    switch(algo) {
        case Algorithm::NAIVE: 
            naive_prefix_sum(data, n); 
            break;
        case Algorithm::CPU_PARALLEL: 
            //cpu_parallel_prefix_sum(data, n); 
            break;
        case Algorithm::CPU_SIMD: 
            //cpu_simd_prefix_sum(data, n); 
            break;
        case Algorithm::GPU_CUDA:
#ifdef USE_CUDA
            gpu_cuda_prefix_sum(data, n);
#else
            throw std::runtime_error("CUDA not enabled");
#endif
            break;
        default:
            throw std::runtime_error("Algorithm not implemented");
    }
}
