#include "Cnvltion_algo/Naive_algo/naive_algo.hh"

using namespace Linear_space;

void Simple_test_2d()
{
    std::cout << "simple_testing_2d have started:\n";
    Tensor_4d tensor{4, 4, 1, 1, 2.5};
    std::cout << tensor;

    Tensor_4d kernel{3, 3, 1, 1, 4};
    std::cout << kernel;
    
    Tensor_4d result;

    result = naive_convolution(tensor, kernel);

    std::cout << result; 
}

void Simple_test_3d()
{
    std::cout << "simple_testing_3d have started:\n";
    Tensor_4d tensor{9, 9, 3, 1, 1.25};
    std::cout << tensor;

    Tensor_4d kernel{3, 3, 3, 1, 8};
    std::cout << kernel;
    
    Tensor_4d result;

    result = naive_convolution(tensor, kernel);

    std::cout << result; 
}


void Simple_test_4d()
{   
    std::cout << "simple_testing_4d have started:\n";

    Tensor_4d tensor{9, 9, 3, 3, 0.625};
    std::cout << tensor;

    Tensor_4d kernel{3, 3, 3, 1, 16};
    std::cout << kernel;
    
    Tensor_4d result;

    result = naive_convolution(tensor, kernel);

    std::cout << result; 
}




int main()
{
    Simple_test_2d();
    Simple_test_3d();
    Simple_test_4d();
}