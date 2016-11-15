#pragma once

#ifndef API_H
# define API_H


#if defined _WINDOWS && defined FastSLAM_core_EXPORTS
# define FastSLAM_core_API __declspec(dllexport) 
#else
# define FastSLAM_core_API __declspec(dllimport) 
#endif


#endif
