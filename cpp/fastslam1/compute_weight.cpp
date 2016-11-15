#include "compute_weight.h"
#include <Eigen/LU>
#include "core/pi_to_pi.h"
#include "core/compute_jacobians.h"
#include <iostream>
#include <iomanip>
#include <vector>

#define pi 3.1416

using namespace std;
//
//compute particle weight for sampling
//
FastSLAM1_API
float compute_weight(Particle &particle, vector<VectorXf> z, vector<int> idf,
	MatrixXf R) 
{
    vector<MatrixXf> Hv;
    vector<MatrixXf> Hf;
    vector<MatrixXf> Sf;
    vector<VectorXf> zp;     

    //process each feature, incrementally refine proposal distribution
    compute_jacobians(particle,idf,R,zp,&Hv,&Hf,&Sf);

    vector<VectorXf> v;
	// z - observations
	// zp - predicted observations
    for (int j =0; j<z.size(); j++) {
		VectorXf v_j = z[j] - zp[j];
		v_j[1] = pi_to_pi(v_j[1]);
		v.push_back(v_j);
    }


    float w = 1.0f;

    MatrixXf S;
    float den, num;
    for (int i=0; i<z.size(); i++) {
		S = Sf[i];
		den = 2*pi*sqrt(S.determinant());
		float arg = v[i].transpose() * S.inverse() * v[i];
		num = std::exp(-0.5 * arg);
		w *= (float)num/(float) den; 
		if (w == 0) {
			cout << fixed << setprecision(4) << setw(10);
			cout << "v[" << i <<"]=(" << v[i][0] << "," << v[i][1] <<"),";
			cout << " S=(" << S(0, 0) << ", " << S(0, 1) << "; " << S(1, 0) << ", " << S(1, 1) << "),";
			cout << " arg=" << arg << " num=" << num << " den=" << den << endl;
		}
    }

    return w;
} 
