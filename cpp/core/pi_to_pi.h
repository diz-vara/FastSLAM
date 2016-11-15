#ifndef PI_TO_PI_H
#define PI_TO_PI_H

#include <Eigen/Dense>
#include <vector>
#include <math.h>
#define pi 3.1416

using namespace Eigen;
using namespace std;

#include "api.h" //

FastSLAM_core_API
void pi_to_pi(VectorXf &angle); //takes in array of floats, returna array 
FastSLAM_core_API
float pi_to_pi(float ang);
//vector<int> find1(VectorXf input);

#endif //PI_TO_PI_H
