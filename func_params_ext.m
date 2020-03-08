% more params
% Note: need to check if ELMO supports this sampling rate!
Ts = 0.001; % sampling time of the system (500Hz)


% Where the convention is:
% q -  [q_hip_frontal_FR;
%       q_hip_sagittal_FR;
%       q_knee_FR;
%       q_hip_frontal_FL;
%       q_hip_sagittal_FL;
%       q_knee_FL;
%       q_hip_frontal_BR;
%       q_hip_sagittal_BR;
%       q_knee_BR;
%       q_hip_frontal_BL;
%       q_hip_sagittal_BL;
%       q_knee_BL]
%

% Link lengths in meters for each leg, see notes
% l_offset = 0.035;
% l1 = 0.1495;
% l2 = 0.3155;
% l3 = 0.176;
% l1a = 0.06;

l_hip_offset = 0; %0.007;
l1 = 0.158;
l2 = 0.333;
l3 = 0.12;
l1a = 0.06;

% add offset angles for each joint for initial condition in the robot

% Offset angle needed to match startup configuration of husky
q_hf_offset = 90*pi/180 ;   %90*pi/180 ;
q_hs_offset = 0*-52.428*pi/180;
q_k_offset = 91.479*pi/180; %91.479*pi/180;

lower_limits = -[3.2, 71.5, 28]*pi/180;
upper_limits = [79, 49.5, 48.5]*pi/180;

leg_params = [l_hip_offset, l1, l2, l3, q_hf_offset, q_hs_offset, q_k_offset];

%=======================================================================

% Contact model parameters
% Normal force
c_k = 5e3;
c_b = 2e2;
% Friction
% mu_k = 0.7;
% mu_s = 0.5;
mu_k = 0.6;
mu_s = 0.8;
v_th = 0.00001; %m/s

%=======================================================================

% Values for RSS trajectory
t_start = 0.32;
% number of waypoints in trajectory
n = 10;

% BR
T_f_back_BR = 0.1/n;
del_y_BR = 0.125/n;
z_max_BR = 0.04;
grid_BR = 1:n+1;
z_BR = z_max_BR*exp(-1/2*0.1*(grid_BR - n/2).^2);
del_z_BR = z_BR(2:end)-z_BR(1:n);

% BL
T_f_back_BL = 0.1/n;
del_y_BL = 0.125/n;
z_max_BL = 0.04;
grid_BL = 1:n+1;
z_BL = z_max_BL*exp(-1/2*0.1*(grid_BL - n/2).^2);
del_z_BL = z_BL(2:end)-z_BL(1:n);

% del_z = 0.05/n;
% velocities
v_y = 0; %del_y/T_f_back;
v_z = 0; %del_z/T_f_back;
% FL
T_f_FL_1 = 1;
del_p_FL_1 = [0.0, 0.18, 0.1];
T_f_FL_2 = 1;
del_p_FL_2 = [0.0, 0, 0.15];



%=======================================================================

% Initial angles and positions

% Initial angles for revolute joints
%  initial_configuration=repmat([10;30;20],4,1).*pi/180;
q_FR_HF0 = initial_configuration(1);
q_FR_HS0 = initial_configuration(2);
q_FR_K0 =  initial_configuration(3);

q_FL_HF0 = initial_configuration(4);
q_FL_HS0 = initial_configuration(5);
q_FL_K0 =  initial_configuration(6);

q_BR_HF0 = initial_configuration(7);
q_BR_HS0 = initial_configuration(8);
q_BR_K0 =  initial_configuration(9);

q_BL_HF0 = initial_configuration(10);
q_BL_HS0 = initial_configuration(11);
q_BL_K0 =  initial_configuration(12);


% initial body position, adding vertical distance to account for sphere on
% feet end
% p_b0 = [0, 0, 0.438];
p_b0 = [0, 0, 0.6];
% p_init = [-0.072127,-0.0350,-0.42342,  -0.072127,0.0350,-0.42342,  -0.072127,-0.0350,-0.42342,   -0.072127,0.0350,-0.42342];

p_init = [-0.072127,0,-0.42342,  -0.072127,0,-0.42342,  -0.072127,0,-0.42342,   -0.072127,0,-0.42342];

% Start with start up position of physical robot:
% p_init = p_init + [0.2,0,0.039,  0.2,0,0.039,  0,0,0,   0,0,0];

% Start with COM inside triangle:
% p_init = p_init + 1*[0.1,0.045,0,  0.2,0.35,0.2,  -0.1,-0.1,0,   -0.1,0.1,0];
p_init = p_init + 1*[0,0,0,  0,0,0,  0,-0,0,   0,0,0];

%========================================================================

% Mass and reference frame locations

hip_FR_origin_wrt_backbone = [0.19745, -0.045, 0];
hip_FL_origin_wrt_backbone = [0.19745, 0.045, 0];
hip_BR_origin_wrt_backbone = [-0.19745, -0.045, 0];
hip_BL_origin_wrt_backbone = [-0.19745, 0.045, 0];

hip_orgin_wrt_backbone = [hip_FR_origin_wrt_backbone, hip_FL_origin_wrt_backbone, hip_BR_origin_wrt_backbone, hip_BL_origin_wrt_backbone].';


hip_mass_loc = [0.024751, 0.0025459, 6.0284e-05];

femur_right_origin_wrt_hip = [0.053, 0.007, 0];

femur_mass_loc = [2.704e-07, -0.036112, -0.082829];

p_FR_end0 = p_b0 + hip_FR_origin_wrt_backbone + p_init(1:3);
p_FL_end0 = p_b0 + hip_FL_origin_wrt_backbone + p_init(4:6);
p_BR_end0 = p_b0 + hip_BR_origin_wrt_backbone + p_init(7:9);
p_BL_end0 = p_b0 + hip_BL_origin_wrt_backbone + p_init(10:12);

%====================================================================

% Mass and inertia properties for links
body.pCOM=[0.021107, 0, -0.041523];
body.mass=2.2337;
body.MomentsofInertia=[0.0030709, 0.0046624, 0.0035462];
body.ProductsofInertia=[0.00010331, 0.00058252, -0.00020765];

femur_left.pCOM=[-2.7039e-07, 0.036112, -0.082829];
femur_left.mass=0.71952;
femur_left.MomentsofInertia=[0.00047141, 0.00072824, 0.00044539];
femur_left.ProductsofInertia=[-1.4185e-06, -3.9569e-05, -6.3308e-06];

femur_right.pCOM=[2.7041e-07, -0.036112, -0.082829];
femur_right.mass=0.71952;
femur_right.MomentsofInertia=[0.00047141, 0.00072824, 0.00044539];
femur_right.ProductsofInertia=[1.4185e-06, 3.9569e-05, -6.3308e-06];

% Original values 
% 
hip_left.pCOM=[-0.00445414112780201, 0.0282493200966724, 6.02835802754331e-05];
hip_left.mass=0.02228;
hip_left.MomentsofInertia=[0.00000585,  0.00001678, 0.00001514];
hip_left.ProductsofInertia=[0, -5e-08, 1.48e-06];

hip_right.pCOM=[-0.0044541412224533, -0.0282493200680473, -6.02837332582817e-05];
hip_right.mass=0.02228;
hip_right.MomentsofInertia=[0.00000585,  0.00001678, 0.00001514];
hip_right.ProductsofInertia=[0, 5e-08, -1.48e-06];

tibia_left.pCOM=[-0.10575, 0.0039831, 1.084e-05];
tibia_left.mass=0.323034205629986;
tibia_left.MomentsofInertia=[0.0005802981403470251, 0.000703725589207329, 0.000533163251971044];
tibia_left.ProductsofInertia=[-5.14070037039191e-07, -4.54880548592882e-05, 1.21346102972198e-06];

tibia_right.pCOM=[-0.10575, -0.0039831, -1.0841e-05];
tibia_right.mass=0.323034205629986;
tibia_right.MomentsofInertia=[0.0005802981403470251, 0.000703725589207329, 0.000533163251971044];
tibia_right.ProductsofInertia=[-5.14070037039209e-07, 4.54880548592882e-05, -1.21346102972198e-06];

tarsus_left.pCOM=[-3.6453e-11, -2.4587e-10, -0.054555];
tarsus_left.mass=0.18284;
tarsus_left.MomentsofInertia=[0.00012076, 0.00011699, 2.5133e-05];
tarsus_left.ProductsofInertia=[3.7744e-12, -6.9478e-13, -8.513900000000001e-12];

tarsus_right.pCOM=[3.6446e-11, 2.4923e-10, -0.054555];
tarsus_right.mass=0.18284;
tarsus_right.MomentsofInertia=[0.00012076, 0.00011699, 2.5133e-05];
tarsus_right.ProductsofInertia=[-3.7744e-12, 6.9478e-13, -8.513900000000001e-12];
% 
% hip_left.mass=0.001;
% hip_left.MomentsofInertia=[0, 0, 0];
% hip_left.ProductsofInertia=[0, 0, 0];
% 
% hip_right.mass=0.001;
% hip_right.MomentsofInertia=[0, 0, 0];
% hip_right.ProductsofInertia=[0, 0, 0];
% 
% tibia_left.mass=0.001;
% tibia_left.MomentsofInertia=[0, 0, 0];
% tibia_left.ProductsofInertia=[0, 0, 0];
% 
% tibia_right.mass=0.001;
% tibia_right.MomentsofInertia=[0, 0, 0];
% tibia_right.ProductsofInertia=[0, 0, 0];
% 
% tarsus_left.mass=0.001;
% tarsus_left.MomentsofInertia=[0, 0, 0];
% tarsus_left.ProductsofInertia=[0, 0, 0];
% 
% tarsus_right.mass=0.001;
% tarsus_right.MomentsofInertia=[0, 0, 0];
% tarsus_right.ProductsofInertia=[0, 0, 0];
% 
% link_right.mass=0.0;
% link_right.MomentsofInertia=[0,0,0];
% link_right.ProductsofInertia=[0,0,0];
% 
% link_left.mass=0.0;
% link_left.MomentsofInertia=[0 0 0];
% link_left.ProductsofInertia=[0 0 0];

link_right.mass=0.022232;
link_right.MomentsofInertia=[9.8756e-07, 2.5372e-05, 2.4918e-05];
link_right.ProductsofInertia=[-2.764e-14, 1.2525e-13, -3.8111e-08];

link_left.mass=0.022232;
link_left.MomentsofInertia=[9.8756e-07, 2.5372e-05, 2.4918e-05];
link_left.ProductsofInertia=[-2.764e-14, -1.2498e-13, 3.8111e-08];

