#ifndef GET_OBSERVATIONS_H
#define GET_OBSERVATIONS_H

#include <Eigen/Dense>
#include <vector>

#include "api.h"
using namespace Eigen;
using namespace std;

FastSLAM_core_API vector<VectorXf> get_observations(VectorXf x,MatrixXf lm,vector<int> &idf,float rmax);
FastSLAM_core_API void get_visible_landmarks(VectorXf x, MatrixXf &lm,vector<int> &idf, float rmax);
FastSLAM_core_API vector<VectorXf> compute_range_bearing(VectorXf x, MatrixXf lm);
FastSLAM_core_API vector<int> find2(vector<float> dx, vector<float> dy, float phi, float rmax);

#endif
