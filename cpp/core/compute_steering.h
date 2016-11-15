#ifndef COMPUTE_STEERING_H
#define COMPUTE_STEERING_H

#include <Eigen/Dense>

#include "api.h"
using namespace Eigen;

FastSLAM_core_API void compute_steering(VectorXf x, MatrixXf wp, int& iwp, float minD,
						float& G, float rateG, float maxG, float dt);

#endif //COMPUTE_STEERING_H
