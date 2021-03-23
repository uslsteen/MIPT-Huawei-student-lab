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
        {
            float* res = result[i];

            for (uint j = 0; j < rhs_cols/8; ++j)
               _mm256_storeu_ps(res + j*8 + 0, _mm256_setzero_ps());

            for (uint k = 0; k < lhs_cols; ++k)
            {
                const float* rhs_row = rhs[k];
                __m256 lhs_elem = _mm256_set1_ps(lhs[i][k]);

                float lhs_elem_ = lhs[i][k];


                for (uint j = 0; j < rhs_cols/16; j++)
                {
                    _mm256_storeu_ps(res + j*8 + 0, _mm256_fmadd_ps(lhs_elem, _mm256_loadu_ps(rhs_row + j + 0), _mm256_loadu_ps(res + j + 0)));
                    _mm256_storeu_ps(res + j*8 + 8, _mm256_fmadd_ps(lhs_elem, _mm256_loadu_ps(rhs_row + j + 8), _mm256_loadu_ps(res + j + 8)));
                }


                for (uint k = (rhs_cols - rhs_cols % 16) ; k < rhs_cols ; ++k)
                    res[k] += rhs_row[k] * lhs_elem_;
            }
        }
    }



}

#endif __MATR_PRODUCT_HPP__