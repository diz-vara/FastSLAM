#ifndef PREDICT_TRUE_H
#define PREDICT_TRUE_H

#include <Eigen/Dense>

using namespace Eigen;
#include "api.h" //

FastSLAM_core_API
void predict_true(VectorXf &xv,float V,float G,int WB,float dt);
//V is m/s
// G is steering angle
//WB = WHEELBASE	 
	
#endif //PREDICT_TRUE_H
