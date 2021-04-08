#ifndef __TENSOR_H__
#define __TENSOR_H__

#include "../Channel/channel.hh"

namespace Linear_space
{

class Tensor_4d final
{
private: 
    std::vector<Channel> butchs;

    uint height_, widht_;
    uint n_chnls_;
    uint n_butch_;

public:

    Tensor_4d(uint height, uint widht, uint n_chnls, uint n_butch);
    Tensor_4d(const std::vector<Channel>& chnl_vec, uint height, uint widht, uint n_chnls);
    Tensor_4d(const Tensor_4d& chnl) = delete;

    uint get_height() const;

    uint get_widht()  const;
  
    uint get_n_chnls() const;

    uint get_n_butch() const;

    const Matr_flt& get_matr(size_t index);
    const Channel& get_chnl(size_t index);

    const Channel& operator[] (size_t index);

    Tensor_4d& operator= (const Tensor_4d& chnl);
    
    bool operator== (const Tensor_4d& chnl);

};

std::ostream& operator << (std::ostream& os, Tensor_4d& chnl);

}

#endif /* __TENSOR_H__ */