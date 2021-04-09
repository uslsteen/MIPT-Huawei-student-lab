#include "Tensor_4D/tensor.hh"

using namespace Linear_space;

void Channel_test_func()
{
    
    //Channel test{matr_vec, height, widht}; 

}

int main()
{
    //Channel_test_func();


    //Channel test{5, 5, 5};
    Channel channel1{2, 2, 2};
    std::cout << channel1;

    Channel channel2{5, 5, 5, 5};
    std::cout << channel2;

    Channel channel3{2, 2, 2, 2};
    std::cout << channel3;


    Tensor_4d tensor1{2, 2, 2, 2, 2};

    std::cout << tensor1;


    //std::cout << test;
}