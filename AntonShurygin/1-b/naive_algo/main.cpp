#include "matr_product.hpp"
#include "my_time.hpp"

using namespace Linear_space;

#define OUT std::cout


template <typename Data>
void Buffer_init(Data& buffer, uint& num_of_rws, uint& num_of_clmns)
{
    std::cin >> num_of_rws >> num_of_clmns;

    buffer.reserve(num_of_rws * num_of_clmns);

    for (size_t i = 0; i < num_of_rws*num_of_clmns; ++i)
        std::cin >> buffer[i];
}

int main()
{
    uint num_of_rws1 = 0, num_of_clmns1 = 0, num_of_rws2 = 0, num_of_clmns2 = 9;
    std::vector<float> buffer1, buffer2;


    Buffer_init(buffer1, num_of_rws1, num_of_clmns1);
    Buffer_init(buffer2, num_of_rws2, num_of_clmns2);

    Linear_space::Matrix<float> mtr1{num_of_rws1, num_of_clmns1, buffer1};
    Linear_space::Matrix<float> mtr2{num_of_rws2, num_of_clmns2, buffer2};


    Linear_space::Matrix<float> naive_mul_{num_of_rws1, num_of_clmns2, 0};
    Linear_space::Matrix<float> fast_mul{num_of_rws1, num_of_clmns2, 0};
    Linear_space::Matrix<float> unroll_mul_2x{num_of_rws1, num_of_clmns2, 0};
    Linear_space::Matrix<float> unroll_mul_4x{num_of_rws1, num_of_clmns2, 0};
    Linear_space::Matrix<float> unroll_mul_8x{num_of_rws1, num_of_clmns2, 0};



    Time::Timer naive_mul_time;
    naive_mul(mtr1, mtr2, naive_mul_);
    std::cout << std::endl << "Naive time:" << naive_mul_time.elapsed() << " millisecs\n";

    std::cout << "res matrix:\n";


    //OUT << naive_mul_ << "              <================= result\n";

    /* <=====================================================================> */

    Time::Timer unroll_mul_2x_time{};

    mul_unroll_2x(mtr1, mtr2, unroll_mul_2x);
    std::cout << std::endl << "Unroll_2 time:" << unroll_mul_2x_time.elapsed() << " millisecs\n";


    std::cout << "res matrix:\n";
   // OUT << unroll_mul_2 << "              <================= result\n";


    if (naive_mul_ == unroll_mul_2x)
        std::cout << "Mul is right!\n";

    else
        std::cout << "Something went wrong!\n";


    /* <=====================================================================> */

    Time::Timer unroll_mul_4x_time{};

    mul_unroll_4x(mtr1, mtr2, unroll_mul_4x);
    std::cout << std::endl << "Unroll_4 time:" << unroll_mul_4x_time.elapsed() << " millisecs\n";


    std::cout << "res matrix:\n";
    // OUT << unroll_mul_2 << "              <================= result\n";


    if (naive_mul_ == unroll_mul_4x)
        std::cout << "Mul is right!\n";

    else
        std::cout << "Something went wrong!\n";

    /* <=====================================================================> */

    Time::Timer unroll_mul_8x_time{};

    mul_unroll_4x(mtr1, mtr2, unroll_mul_8x);
    std::cout << std::endl << "Unroll_8 time:" << unroll_mul_8x_time.elapsed() << " millisecs\n";


    std::cout << "res matrix:\n";
    // OUT << unroll_mul_2 << "              <================= result\n";


    if (naive_mul_ == unroll_mul_8x)
        std::cout << "Mul is right!\n";

    else
        std::cout << "Something went wrong!\n";

    /* <=====================================================================> */

    Time::Timer optimiz_mul{};

    mul_with_intrinsics(mtr1, mtr2, fast_mul);
    std::cout << std::endl << "Optimazed time:" << optimiz_mul.elapsed() << " millisecs\n";


    std::cout << "res matrix:\n";
    // OUT << fast_mul << "              <================= result\n";


    if (naive_mul_ == fast_mul)
        std::cout << "Mul is right!\n";

    else
        std::cout << "Something went wrong!\n";

    
    return 0;
}
