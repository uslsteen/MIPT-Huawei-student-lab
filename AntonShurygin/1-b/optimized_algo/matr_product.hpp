#ifndef __MATR_PRODUCT_HPP__
#define __MATR_PRODUCT_HPP__

#include "Matrix.hpp"

namespace Linear_space
{

    template<typename Data>
    Matrix<Data> &product_with_intr(const Matrix<Data> &lhs, const Matrix<Data> &rhs, Matrix<Data>& result)
    {
        uint lhs_rows = lhs.nrows();
        uint lhs_cols = lhs.nclmns();

        uint rhs_rows = rhs.nrows();
        uint rhs_cols = rhs.nclmns();
        uint optim_size = rhs_cols - rhs_cols % 16;

        assert(lhs_cols == rhs_rows);

        for (uint i = 0; i < lhs_rows; ++i)
        {
            float* res = result[i];

            for (uint p = 0; p < rhs_cols/8; ++p)
               _mm256_storeu_ps(res + p*8 + 0, _mm256_setzero_ps());

            for (uint j = 0; j < lhs_cols; ++j)
            {
                const float* rhs_row = rhs[j];
                __m256 lhs_elem = _mm256_set1_ps(lhs[i][j]);

                uint k = 0;
                for (; k < optim_size; k += 16)
                {
                    _mm256_storeu_ps(res + k  + 0 , _mm256_fmadd_ps(lhs_elem, _mm256_loadu_ps(rhs_row  + k  + 0) , _mm256_loadu_ps(res + k  + 0)));
                    _mm256_storeu_ps(res + k  + 8 , _mm256_fmadd_ps(lhs_elem, _mm256_loadu_ps(rhs_row + k + 8) , _mm256_loadu_ps(res + k  + 8)));
                }

                for (; k < rhs_cols; ++k)
                    res[k] += lhs[i][j]* rhs_row[k];
            }
        }
    }


    /* LOOP UNORLLING */


    template <typename Data>
    void product_unroll_2x(const Matrix<Data> &lhs, const Matrix<Data> &rhs, Matrix<Data>& result)
    {
        uint lhs_rows = lhs.nrows(), rhs_cols = rhs.nclmns(), lhs_cols = lhs.nclmns();
        uint unroll_size = lhs_cols - lhs_cols % 2;


        for (size_t i = 0; i < lhs_rows; ++i)
        {
            for (size_t j = 0; j < rhs_cols; ++j)
            {
                float* lhs_row = lhs[i];

                //! Common variable for cycle of mult
                size_t k = 0;
                for (; k < unroll_size; k += 2)
                {
                    result[i][j] += lhs_row[k] * rhs[k][j];
                    result[i][j] += lhs_row[k + 1] * rhs[k + 1][j];
                }

                for (; k < lhs_cols; ++k)
                    result[i][j] += lhs_row[k] * rhs[k][j];

            }
        }
    }

    template <typename Data>
    void product_unroll_4x(const Matrix<Data> &lhs, const Matrix<Data> &rhs, Matrix<Data>& result)
    {
        uint lhs_rows = lhs.nrows(), rhs_cols = rhs.nclmns(), lhs_cols = lhs.nclmns();
        uint unroll_size = lhs_cols - lhs_cols % 2;


        for (size_t i = 0; i < lhs_rows; ++i)
        {
            for (size_t j = 0; j < rhs_cols; ++j)
            {
                float* lhs_row = lhs[i];

                //! Common variable for cycle of mult
                size_t k = 0;
                for (; k < unroll_size; k += 2)
                {
                    result[i][j] += lhs_row[k] * rhs[k][j];
                    result[i][j] += lhs_row[k + 1] * rhs[k + 1][j];
                }

                for (; k < lhs_cols; ++k)
                    result[i][j] += lhs_row[k] * rhs[k][j];

            }
        }
    }




}

#endif __MATR_PRODUCT_HPP__