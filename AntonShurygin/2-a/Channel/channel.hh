#include "../Matrix/matrix.hh"


namespace Linear_space
{

class Channel final
{
    private: 
    std::vector<Matr_flt> channels;

    uint height_, widht_;
    uint n_chnls_;

    public:

    Channel(uint height, uint widht, uint n_chnls);

    Channel(std::vector<Matr_flt>& matr_vec, uint height,
                                             uint widht, 
                                             uint n_chnls);

    Channel(const Channel& chnl);

    uint get_height() const
    { return height_; }

    uint get_widht()  const 

    { return widht_;  }  
    uint get_n_chnls() const

    { return n_chnls_; } 
    Matr_flt& get_matr(size_t index)   { return channels[index]; }


    Matr_flt& operator[] (size_t index);

    Channel& operator= (Channel& chnl);

    bool operator== (Channel& chnl);

    

};

std::ostream& operator << (std::ostream& os, Channel& chnl);

}