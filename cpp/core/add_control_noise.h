#ifndef ADD_CONTROL_NOISE
#define ADD_CONTROL_NOISE

#include <Eigen/Dense>
#include "multivariate_gauss.h"
# include <cstdlib>
# include <cmath>

#include "api.h"  //FastSLAM_core_API



using namespace Eigen;

//MatrixXf randn(int m, int n); 
//MatrixXf rand(int m, int n);
FastSLAM_core_API void add_control_noise(float V, float G, Matrix2f Q, int addnoise,float* VnGn);


#endif //ADD_CONTROL_NOISE
