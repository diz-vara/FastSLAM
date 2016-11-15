#ifndef ADD_OBSERVATION_NOISE_H
#define ADD_OBSERVATION_NOISE_H

#include <Eigen/Dense>
#include <iostream>
#include <vector>

#include "api.h"

using namespace Eigen;
using namespace std;

namespace nRandMat{
	FastSLAM_core_API MatrixXf randn(int m, int n);
	FastSLAM_core_API MatrixXf rand(int m, int n);
}

FastSLAM_core_API void add_observation_noise(vector<VectorXf> &z, MatrixXf R, int addnoise);

#endif //ADD_OBSERVATION_NOISE_H
