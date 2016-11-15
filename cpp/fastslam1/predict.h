#ifndef PREDICT_H
#define PREDICT_H

#include <Eigen/Dense>
#include "core/particle.h"
#include "core/multivariate_gauss.h"

using namespace Eigen;

#if defined _WINDOWS && defined FastSLAM1_EXPORTS
# define FastSLAM1_API __declspec(dllexport) 
#else
#define FastSLAM1_API
#endif


FastSLAM1_API
void predict(Particle &particle,float V,float G,Matrix2f Q, float WB,float dt, int addrandom);
FastSLAM1_API
float pi_to_pi2(float ang);

#endif //PREDICT_H
