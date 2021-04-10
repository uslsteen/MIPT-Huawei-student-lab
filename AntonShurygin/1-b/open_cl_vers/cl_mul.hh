#ifndef __CL_MUL__
#define __CL_MUL__

/* Standard io libraries */
#include <cmath>
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>

/*****************************************/

/* std containers */
#include <string>
#include <vector>
/****************************************/

/* OpenCL library */

#define __CL_ENABLE_EXCEPTIONS
#include <CL/cl2.hpp>

/****************************************/

/* Our libs */

#include "../naive_algo/my_time.hpp"
#include "../naive_algo/Matrix.hpp"

/****************************************/


using namespace Linear_space;

/**
 * @brief OpenCL driver class
 *
 */
namespace Mul_optim
{


class Driver final
{
private:
  cl::Context context_;
  cl::Device device_;

  cl::Program::Sources sources_;
  cl::CommandQueue queue_;
  cl::Program prog_;

  std::string src_code_;

  cl::Kernel naive_mul_;

private:
 

  bool build();

  bool kernel_exec(cl::Kernel kernel, size_t global_size, size_t local_size, std::vector<cl::Event> &events);

  void gpu_timing(std::vector<cl::Event> &events, cl_ulong *time);

  void cl_mul(const Matr_int& lhs, const Matr_int& rhs);

public:

  Driver();
  Driver(Driver const &) = delete;
  Driver &operator=(Driver const &) = delete;

  ~Driver() = default;

  void Device_selection(); // choose first suited platform and device
};


Matr_int& cl_matr_mul(Matr_int& lhs, Matr_int& rhs);

//Matr_int bsort(std::vector<int> &vec, Dir dir);
const char *err_what(cl_int err_code);

} // namespace  Mul_optim

#endif /* __CL_MUL__ */