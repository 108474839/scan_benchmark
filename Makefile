CXX = g++
NVCC = nvcc
CXXFLAGS = -O3 -fopenmp -mavx2
USE_CUDA ?= 1

SRC_CPP = src/main.cpp src/prefix_sum.cpp src/naive.cpp src/cpu_parallel.cpp src/cpu_simd.cpp
OBJ_CPP = $(SRC_CPP:.cpp=.o)

ifeq ($(USE_CUDA),1)
    SRC_CUDA = gpu/gpu_cuda.cu
    OBJ_CPP += gpu/gpu_cuda.o
endif

all: prefix_sum_app

# link
prefix_sum_app: $(OBJ_CPP)
ifeq ($(USE_CUDA),1)
	$(NVCC) -O3 -arch=sm_70 -o $@ $(OBJ_CPP)
else
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ_CPP)
endif
	@echo "Build complete, removing object files..."
	@rm -f $(OBJ_CPP)

# CPU 
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# GPU 
gpu/%.o: gpu/%.cu
	$(NVCC) -O3 -arch=sm_70 -c $< -o $@

clean:
	rm -f $(OBJ_CPP) prefix_sum_app
