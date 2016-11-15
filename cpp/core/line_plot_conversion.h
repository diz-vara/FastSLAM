#ifndef LINE_PLOT_CONVERSION_H
#define LINE_PLOT_CONVERSION_H

#include <Eigen/Dense>

using namespace Eigen;

#include "api.h" //FastSLAM_core_API
FastSLAM_core_API MatrixXf line_plot_conversion(MatrixXf lnes);

#endif //LINE_PLOT_CONVERSION_H
