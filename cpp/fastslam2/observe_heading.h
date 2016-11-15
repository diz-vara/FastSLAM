#ifndef OBSERVE_HEADING_H
#define OBSERVE_HEADING_H

#include<Eigen/Dense>

#include "core/particle.h"
#if defined _WINDOWS && defined FastSLAM2_EXPORTS
# define FastSLAM2_API __declspec(dllexport) 
#else
#define FastSLAM2_API
#endif

FastSLAM2_API
void observe_heading(Particle &particle, float phi, int useheading);

#endif
