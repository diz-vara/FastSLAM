#ifndef STRATIFIED_RANDOM_H
#define STRATIFIED_RANDOM_H

#include <Eigen/Dense>
#include <vector>

using namespace Eigen;
using namespace std;

#include "api.h" //

FastSLAM_core_API
void stratified_random(int N, vector<float> &di);
FastSLAM_core_API
double unifRand();

#endif
