#include <stdio.h>
#include <algorithm>
#include <iterator>
#ifdef _WINDOWS
# include <io.h>
#else
# include <unistd.h>
#endif
#include <errno.h>
#include <string>
#include <vector>

#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

#include "api.h" //

FastSLAM_core_API
void read_input_file(const string s, MatrixXf *lm, MatrixXf *wp);