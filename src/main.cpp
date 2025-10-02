#include "../include/prefix_sum.h"
#include <iostream>
#include <string>
#include <cstdlib>

int main(int argc, char** argv) {
    if(argc < 3) {
        std::cout << "Usage: " << argv[0] << " <algorithm> <size>\n";
        std::cout << "Algorithms: naive, cpu_parallel, cpu_simd, gpu\n";
        return 1;
    }

    std::string algo_name = argv[1];
    int n = std::atoi(argv[2]);

    Algorithm algo;
    try {
        algo = parse_algorithm(algo_name);
    } catch (const std::exception& e) {
        std::cerr << e.what() << "\n";
        return 1;
    }

    float* data = new float[n];
    for(int i = 0; i < n; ++i) data[i] = 1.0f;

    prefix_sum(data, n, algo);

    std::cout << "Result (first 10 elements): ";
    for(int i = 0; i < 10 && i < n; ++i) std::cout << data[i] << " ";
    std::cout << "\n";

    delete[] data;
    return 0;
}
