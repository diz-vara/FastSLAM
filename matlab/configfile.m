%%% Configuration file
%%% Permits various adjustments to parameters of the FastSLAM algorithm.
%%% See fastslam_sim.m for more information

% control parameters
V= 3; % m/s
MAXG= 30*pi/180; % radians, maximum steering angle (-MAXG < g < MAXG)
RATEG= 20*pi/180; % rad/s, maximum rate of change in steer angle
WHEELBASE= 4; % metres, vehicle wheel-base
DT_CONTROLS= 0.025; % seconds, time interval between control signals

% control noises
sigmaV= 0.5; % m/s
sigmaG= (2.0*pi/180); % radians
Q= [sigmaV^2 0; 0 sigmaG^2];

% observation parameters
MAX_RANGE= 30.0; % metres
DT_OBSERVE= 2*DT_CONTROLS; % seconds, time interval between observations

% observation noises
sigmaR= 5.0; % metres
sigmaB= (5.0*pi/180); % radians
R= [sigmaR^2 0; 0 sigmaB^2];

% waypoint proximity
AT_WAYPOINT= 1.0; % metres, distance from current waypoint at which to switch to next waypoint
NUMBER_LOOPS= 3; % number of loops through the waypoint list


% resampling
NPARTICLES= 10; 
NEFFECTIVE= 0.75*NPARTICLES; % minimum number of effective particles before resampling

% switches
SWITCH_CONTROL_NOISE= 1;
SWITCH_SENSOR_NOISE = 1;
SWITCH_INFLATE_NOISE= 0;
SWITCH_PREDICT_NOISE = 0;   % sample noise from predict (usually 1 for fastslam1.0 and 0 for fastslam2.0)
SWITCH_SAMPLE_PROPOSAL = 1; % sample from proposal (no effect on fastslam1.0 and usually 1 for fastslam2.0)
SWITCH_HEADING_KNOWN= 1;
SWITCH_RESAMPLE= 1; 
SWITCH_PROFILE= 0;
SWITCH_SEED_RANDOM= 0; % if not 0, seed the randn() with its value at beginning of simulation (for repeatability)

