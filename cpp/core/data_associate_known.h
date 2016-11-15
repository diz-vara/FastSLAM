#ifndef DATA_ASSOCIATE_KNOWN_H
#define DATA_ASSOCIATE_KNOWN_H

#include <Eigen/Dense>
#include <vector>

using namespace std;
using namespace Eigen;

#include "api.h"

FastSLAM_core_API void data_associate_known(vector<VectorXf> z, vector<int> idz, VectorXf &table, int Nf, \
						  vector<VectorXf> &zf, vector<int> &idf, vector<VectorXf> &zn); 

#endif //DATA_ASSOCIATE_KNOWN_H
