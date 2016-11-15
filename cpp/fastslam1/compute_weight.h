#ifndef COMPUTE_WEIGHT_H
#define COMPTUE_WEIGHT_H

#include <Eigen/Dense>
#include <vector>
#include "core/particle.h"

using namespace Eigen;
using namespace std;

#if defined _WINDOWS && defined FastSLAM1_EXPORTS
# define FastSLAM1_API __declspec(dllexport) 
#else
#define FastSLAM1_API
#endif

FastSLAM1_API float compute_weight(Particle &particle, vector<VectorXf> z, vector<int> idf, MatrixXf R);

#endif
