#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#include <Eigen/Dense>

//******************
// Global Variables
//******************
#include "api.h"

namespace config {
	FastSLAM_core_API extern float V;
	FastSLAM_core_API extern float MAXG;
	FastSLAM_core_API extern float RATEG;
	FastSLAM_core_API extern int WHEELBASE;
	FastSLAM_core_API extern float DT_CONTROLS;

	FastSLAM_core_API extern float sigmaV;
	FastSLAM_core_API extern float sigmaG;

	FastSLAM_core_API extern Eigen::MatrixXf Q;

	FastSLAM_core_API extern float MAX_RANGE;
	FastSLAM_core_API extern float DT_OBSERVE;

	FastSLAM_core_API extern float sigmaR;
	FastSLAM_core_API extern float sigmaB;
		
	FastSLAM_core_API extern Eigen::MatrixXf R;

	FastSLAM_core_API extern float AT_WAYPOINT;
	FastSLAM_core_API extern int NUMBER_LOOPS;

	FastSLAM_core_API extern unsigned int NPARTICLES;
	FastSLAM_core_API extern float NEFFECTIVE;

	FastSLAM_core_API extern int SWITCH_CONTROL_NOISE;
	FastSLAM_core_API extern int SWITCH_SENSOR_NOISE;
	FastSLAM_core_API extern int SWITCH_INFLATE_NOISE;
	FastSLAM_core_API extern int SWITCH_PREDICT_NOISE;

	FastSLAM_core_API extern int SWITCH_SAMPLE_PROPOSAL;
	FastSLAM_core_API extern int SWITCH_HEADING_KNOWN;
	FastSLAM_core_API extern int SWITCH_RESAMPLE;
	FastSLAM_core_API extern int SWITCH_PROFILE;
	FastSLAM_core_API extern int SWITCH_SEED_RANDOM;
}


#endif //CONFIGFILE_H
