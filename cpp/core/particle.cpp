#include <iostream>
#include "particle.h"
#include <algorithm>

/*************
** Particle
*************/
FastSLAM_core_API
Particle::Particle() 
{
	_w = 1.0; 
	_xv = VectorXf(3);
        _xv.setZero();
	_Pv = MatrixXf(3,3);
        _Pv.setZero();
	_da = NULL;
}

FastSLAM_core_API
Particle::Particle(float w, VectorXf &xv, MatrixXf &Pv, vector<VectorXf> &xf, vector<MatrixXf> &Pf, float* da)
{
	_w = w;
	_xv = xv;
	_Pv = Pv;
	_xf = xf;
	_Pf = Pf;
	_da = da;		
}

FastSLAM_core_API
Particle::~Particle()
{
}

//getters
FastSLAM_core_API
float Particle::w() const
{
	return _w;	
}

FastSLAM_core_API
VectorXf Particle::xv() const
{
	return _xv;	
}

FastSLAM_core_API
MatrixXf Particle::Pv() const
{
	return _Pv;	
}

FastSLAM_core_API
vector<VectorXf> Particle::xf() const
{
	return _xf;	
}

FastSLAM_core_API
vector<MatrixXf> Particle::Pf() const
{
	return _Pf;	
}

FastSLAM_core_API
float* Particle::da() const
{
	return _da;	
}

//setters
FastSLAM_core_API
void Particle::setW(float w)
{
	_w = w;
}

FastSLAM_core_API
void Particle::setXv(VectorXf &xv)
{
	_xv = xv;
}

FastSLAM_core_API
void Particle::setPv(MatrixXf &Pv)
{
	_Pv = Pv;
}

FastSLAM_core_API
void Particle::setXf(vector<VectorXf> &xf)
{
	_xf = xf;
}

FastSLAM_core_API
void Particle::setXfi(int i, VectorXf &vec) 
{
	if (i >= _xf.size()){
		_xf.resize(i+1);
	}
	_xf[i] = vec;
}

FastSLAM_core_API
void Particle::setPf(vector<MatrixXf> &Pf)
{
	_Pf = Pf;
}

FastSLAM_core_API
void Particle::setPfi(int i, MatrixXf &m) 
{
	if(i >= _Pf.size()) {
		_Pf.resize(i+1);
	}
	_Pf[i] = m;
}

FastSLAM_core_API
void Particle::setDa(float* da)
{
	_da = da;
}

