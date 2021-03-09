#include "Matrix.hpp"

using namespace Linear_space;

#define OUT std::cout

void Buffer_init(std::vector<int>& buffer, uint& num_of_rws, uint& num_of_clmns)
{
    std::cin >> num_of_rws >> num_of_clmns;

    buffer.reserve(num_of_rws * num_of_clmns);

    for (size_t i = 0; i < num_of_rws*num_of_clmns; ++i)
        std::cin >> buffer[i];
}

int main()
{
    uint num_of_rws1 = 0, num_of_clmns1 = 0, num_of_rws2 = 0, num_of_clmns2 = 9;
    std::vector<int> buffer1, buffer2;

    Buffer_init(buffer1, num_of_rws1, num_of_clmns1);
    Buffer_init(buffer2, num_of_rws2, num_of_clmns2);

    Linear_space::Matrix<int> mtr1{num_of_rws1, num_of_clmns1, buffer1};
    Linear_space::Matrix<int> mtr2{num_of_rws2, num_of_clmns2, buffer2};

    
    Linear_space::Matrix<int> mtr_res = mtr1 * mtr2;

    std::cout << "res matrix:\n";
    OUT << mtr_res;

    return 0;
}
