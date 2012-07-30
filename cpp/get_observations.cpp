#include "get_observations.h"
#include <iostream>
#include <math.h>

MatrixXf get_observations(VectorXf x, MatrixXf lm, VectorXf idf, float rmax)
{
	get_visible_landmarks(x,lm,idf,rmax);
	return compute_range_bearing(x,lm);	
}

void get_visible_landmarks(VectorXf x, MatrixXf &lm, VectorXf &idf, float rmax)
{
	//select set of landmarks that are visible within vehicle's 
	//semi-circular field of view
	MatrixXf dx(1,lm.cols());
	MatrixXf dy(1,lm.cols());
	for (int c=0; c<lm.cols(); c++) {
		dx(0,c) = lm(0,c) - x(0);
		dy(1,c) = lm(1,c) - x(1);
	}	
	float phi = x(2);
	VectorXf ii = find2(dx,dy,phi,rmax); 

	//lm(:[2 3]) return matrix of column 2 and colum 3 of lm
	MatrixXf lm_new (lm.rows(), ii.size()); 	
	vector<int>iterator::iter;
	int j;
	for (j=0; j<lm.rows(); j++){
		for(iter = ii.begin(); iter != ii.end; iter++){
			lm_new(j,iter) = lm(j,iter);	
		}
	}
	
	lm = lm_new; //TODO: does this properly copy it over? I need a copy constructor
	idf = VectorXf(ii); //check this too			
}

MatrixXf compute_range_bearing(VectorXf x, MatrixXf lm) 
{
	MatrixXf dx(1,lm.cols());
	MatrixXf dy(1,lm.cols());
	for (int c=0; c<lm.cols(); c++) {
		dx(0,c) = lm(0,c) - x(0);
		dy(1,c) = lm(1,c) - x(1);
	}	
	float phi = x(2);

	MatrixXf z(2,dx.size());
	for (int i =0; i<dx.size(); i++) {
		z(1,i) = pow(dx[i],2) + pow(dy[i],2);		
		z(2,i) = atan2(dy[i],dx[i]) - phi;	
	}

	return z; 
}

vector<int> find2(VectorXf dx, VectorXf dy, float phi, float rmax)
{
	VectorXf index;
	//incremental tests for bounding semi-circle
	for (int i =0; i<input.size(); i++) {
		if ((abs(dx[i]) < rmax) && (abs(dy[i]) < rmax)
		&& ((dx[i]* cos(phi) + dy[i]* sin(phi)) > 0)
		&& ((pow(dx[i],2) + pow(dy[i],2)) < pow(rmax,2))) {
			index.push_back(i);			
		}
	}	
	return index;				
}