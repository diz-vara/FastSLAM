#ifndef KF_CHOLESKY_UPDATE_H
#define KF_CHOLESKY_UPDATE_H

#include <Eigen/Dense>

using namespace Eigen;
#include "api.h"
FastSLAM_core_API
void KF_cholesky_update(VectorXf &x,MatrixXf &P,VectorXf v,MatrixXf R,MatrixXf H);

#endif
