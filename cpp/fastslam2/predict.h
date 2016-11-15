#ifndef PREDICT_H
#define PREDICT_H

#include <Eigen/Dense>
#include "core/particle.h"
#include "core/multivariate_gauss.h"

using namespace Eigen;

#if defined _WINDOWS && defined FastSLAM2_EXPORTS
# define FastSLAM2_API __declspec(dllexport) 
#else
#define FastSLAM2_API
#endif

FastSLAM2_API
void predict(Particle &particle,float V,float G,Matrix2f Q, float WB,float dt, int addrandom);

FastSLAM2_API
float pi_to_pi2(float ang);

#endif //PREDICT_H
