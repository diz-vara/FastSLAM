#ifndef STRATIFIED_RESAMPLE_H
#define STRATIFIED_RESAMPLE_H

#include <Eigen/Dense>
#include <vector>

using namespace Eigen;
using namespace std;

#include "api.h" //

FastSLAM_core_API
void stratified_resample(VectorXf w, vector<int> &keep, float &Neff);
FastSLAM_core_API
void cumsum(VectorXf &w);

#endif
