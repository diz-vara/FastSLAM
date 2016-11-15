#ifndef KF_JOSEPH_UPDATE_H
#define KF_JOSEPH_UPDATE_H

#include <Eigen/Dense>

using namespace Eigen;

#include "api.h"

FastSLAM_core_API void KF_joseph_update(VectorXf &x,MatrixXf &P,float v,float R, MatrixXf H);
FastSLAM_core_API MatrixXf make_symmetric(MatrixXf P);

#endif
