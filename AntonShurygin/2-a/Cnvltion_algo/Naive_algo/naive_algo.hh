#ifndef __NAIVE_ALGO__
#define __NAIVE_ALGO__

#include "../../Tensor_4D/tensor.hh"

using namespace Linear_space;

void convolution_2d(const Channel& channel,const Channel& kernel, Matrix& result);


void convolution_3d(const Channel& channel,const Tensor_4d& kernel, Channel& result);


Tensor_4d naive_convolution(const Tensor_4d& tensor,const Tensor_4d& kernel);






#endif /* __NAIVE_ALGO__ */