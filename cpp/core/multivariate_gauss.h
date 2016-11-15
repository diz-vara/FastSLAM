#ifndef MULTIVARIATE_GAUSS_H
#define MULTIVARIATE_GAUSS_H

#include <Eigen/Dense>
using namespace Eigen;

#include "api.h"

FastSLAM_core_API VectorXf multivariate_gauss(VectorXf x, MatrixXf P, int n);

#endif //MULTIVARIATE_GAUSS_H

