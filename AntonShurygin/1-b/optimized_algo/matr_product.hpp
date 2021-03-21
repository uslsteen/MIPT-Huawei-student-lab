#ifndef __MATR_PRODUCT_HPP__
#define __MATR_PRODUCT_HPP__

#include "Matrix.hpp"

namespace Linear_space
{
    template<typename Data>
    Matrix<Data> &matr_product(const Matrix<Data> &lhs, const Matrix<Data> &rhs, Matrix<Data>& result)
    {
        uint lhs_rows = lhs.nrows();
        uint lhs_cols = lhs.nclmns();

        uint rhs_rows = rhs.nrows();
        uint rhs_cols = rhs.nclmns();

        assert(lhs_cols == rhs_rows);


        for (uint i = 0; i < lhs_rows; ++i)

            for (uint j = 0; j < rhs_cols; ++j)

                for (uint k = 0; k < rhs_rows; ++k)
                    result[i][j] += lhs[i][k] * rhs[k][j];


    }

}

#endif __MATR_PRODUCT_HPP__   