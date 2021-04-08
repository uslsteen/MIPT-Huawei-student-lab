#include "channel.hh"

namespace Linear_space
{
    Channel::Channel(uint height, uint widht, uint n_chnls) : height_(height),
                                                              widht_(widht),
                                                              n_chnls_(n_chnls)
    {
        for (size_t k; k < n_chnls_; ++k)
            channels.push_back(Matr_flt{height_, widht_, 0});
    }

    Channel::Channel(uint height, uint widht, uint n_chnls) : height_(height),
                                                              widht_(widht),
                                                              n_chnls_(n_chnls)
    {
        for (size_t k; k < n_chnls_; ++k)
            channels.push_back(channels[k]);
    } 

    Channel::Channel(const Channel& chnl)
    {
        height_ = chnl.get_height();
        widht_ = chnl.get_widht();
        n_chnls_ = chnl.get_n_chnls();



    }

    std::ostream& operator << (std::ostream& os, Channel& chnl)
    {
    size_t n_chnl = chnl.get_n_chnls(),
           height = chnl.get_height(),
           widht = chnl.get_widht();

    for (size_t k = 0; k < n_chnl; ++k)
    {
        for (size_t i = 0; i < height; ++i)
        {
            for (size_t j = 0; j < widht; ++j)
                os << (chnl[k])[i][j] << " ";

                os << std::endl;
        }

        os << "         " << std::endl;
    }
}

uint Channel::get_height() const
{ 
    return height_;
}

uint Channel::get_widht()  const 
{
    return widht_;
}  

uint Channel::get_n_chnls() const
{
    return n_chnls_;
} 


                                                      
                                                                  
}