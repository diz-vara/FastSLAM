#ifndef PARTICLES_H
#define PARTICLES_H

#include <Eigen/Dense>
#include <vector>

using namespace Eigen;
using namespace std;

#include "api.h"

class Particle{
public:
	FastSLAM_core_API Particle();
	FastSLAM_core_API Particle(float w, VectorXf &xv, MatrixXf &Pv, vector<VectorXf> &xf, vector<MatrixXf> &Pf, float* da);
	FastSLAM_core_API ~Particle();
        
	//getters	
	FastSLAM_core_API float w() const;
	FastSLAM_core_API VectorXf xv() const; //robot pose: x,y,theta (heading dir)
	FastSLAM_core_API MatrixXf Pv() const; //controls: velocities
	FastSLAM_core_API vector<VectorXf> xf() const; //2d means of EKF
	FastSLAM_core_API vector<MatrixXf> Pf() const; //covariance matrices for EKF 
	FastSLAM_core_API float* da() const; //

	//setters
	FastSLAM_core_API void setW(float w);
	FastSLAM_core_API void setXv(VectorXf &xv);
	FastSLAM_core_API void setPv(MatrixXf &Pv);
	FastSLAM_core_API void setXf(vector<VectorXf> &xf);
	FastSLAM_core_API void setXfi(int i, VectorXf &vec);
	FastSLAM_core_API void setPf(vector<MatrixXf> &Pf);
	FastSLAM_core_API void setPfi(int i, MatrixXf &m);
	FastSLAM_core_API void setDa(float* da);
	
private:
	float _w;
	VectorXf _xv;
	MatrixXf _Pv;		
	vector<VectorXf> _xf;
	vector<MatrixXf> _Pf;
	float* _da;
};

#endif //PARTICLES_H
