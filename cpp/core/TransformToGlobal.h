#ifndef TRANSFORMGLOBAL_H
#define TRANSFORMGLOBAL_H

#include <Eigen/Dense>
#include <iostream>

using namespace Eigen;

#include "api.h" //

FastSLAM_core_API
void TransformToGlobal(MatrixXf &p, VectorXf b);

#endif //TRANSFORMGLOBAL_H
