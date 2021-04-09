#include "naive_algo.hh"

using namespace Linear_space;


float sum_and_mul(const Matrix& layer, const Matrix& kernel)
{
    float res = 0;
    uint kernel_rows = kernel.nrows(), kernel_cols = kernel.nclmns();

    for (uint i = 0; i < kernel_rows; ++i)
        for (uint j = 0; j < kernel_cols; ++j)
            
            res += layer[i][j] * kernel[i][j];
}


void convolution_2d(const Channel& channel,const Channel& kernel, Matrix& result)
{
    uint chnls_num = kernel.get_n_chnls();
    uint res_rows = result.nrows(), res_cols = result.nclmns();

    for (uint cur_channel = 0; cur_channel < chnls_num; ++cur_channel)
    {
        Matrix conv_res{res_rows, res_cols, 0};

        for (uint i = 0; i < res_rows; ++i)
            for (uint j = 0; j < res_cols; ++j)
            {
                Matrix chan_layer{channel[cur_channel], kernel[cur_channel].nrows(), kernel[cur_channel].nclmns(), i, j};
                conv_res[i][j] = sum_and_mul(chan_layer, kernel[cur_channel]);
            }
    }
}


void convolution_3d(const Channel& channel,const Tensor_4d& kernel, Channel& result)
{
    uint kernel_butch = kernel.get_n_butch();

    for (uint cur_kernel_btch = 0; cur_kernel_btch <  kernel_butch; ++cur_kernel_btch)
        convolution_2d(channel, kernel[cur_kernel_btch], result[cur_kernel_btch]);
}


Tensor_4d naive_convolution(const Tensor_4d& tensor,const Tensor_4d& kernel)
{
    uint res_height = tensor.get_height() - kernel.get_height() + 1;
    uint res_width = tensor.get_widht() - kernel.get_widht() + 1;
    uint tens_butch = tensor.get_n_butch();

    Tensor_4d result{res_height, res_width, tens_butch, kernel.get_n_butch()};


    for (uint cur_batch = 0; cur_batch < tens_butch; ++cur_batch)
        convolution_3d(tensor[cur_batch], kernel, result[cur_batch]);
    
    return result;
    
}