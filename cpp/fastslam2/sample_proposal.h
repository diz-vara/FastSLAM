#ifndef SAMPLE_PROPOSAL_H
#define SAMPLE_PROPOSAL_H

#include <vector>
#include <Eigen/Dense>

#include "core/particle.h"
#include "core/compute_jacobians.h"
#include "core/multivariate_gauss.h"
#include "gauss_evaluate.h"
#include "core/pi_to_pi.h"

using namespace Eigen;
using namespace std;


#if defined _WINDOWS && defined FastSLAM2_EXPORTS
# define FastSLAM2_API __declspec(dllexport) 
#else
#define FastSLAM2_API
#endif


FastSLAM2_API
void sample_proposal(Particle &particle, vector<VectorXf> z, vector<int> idf, MatrixXf R);
//float likelihood_given_xv(Particle particle, MatrixXf z, vector<int>idf, MatrixXf R);
FastSLAM2_API
float likelihood_given_xv(Particle particle, vector<VectorXf> z, vector<int>idf, MatrixXf R);
FastSLAM2_API
VectorXf delta_xv(VectorXf xv1, VectorXf xv2);

#endif
