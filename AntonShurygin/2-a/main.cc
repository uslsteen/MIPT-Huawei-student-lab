#include "Cnvltion_algo/Naive_algo/naive_algo.hh"

using namespace Linear_space;

void Simple_test_2d()
{
    Tensor_4d tensor{4, 4, 1, 1, 5};
    std::cout << tensor;

    Tensor_4d kernel{3, 3, 1, 1, 2};
    std::cout << kernel;
    
    Tensor_4d result;

    result = naive_convolution(tensor, kernel);

    std::cout << result; 
}

int main()
{
    
    Simple_test_2d();

    //std::cout << test;
}