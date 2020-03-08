% more params
% Note: need to check if ELMO supports this sampling rate!
Ts = 0.002; % sampling time of the system (500Hz)


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
q_k_offset = 90*pi/180; %91.479*pi/180;

lower_limits = -[3.2, 71.5, 28]*pi/180;
upper_limits = [79, 49.5, 48.5]*pi/180;

leg_params = [l_hip_offset, l1, l2, l3, q_hf_offset, q_hs_offset, q_k_offset];

%=======================================================================

% Initial angles for revolute joints
q_FR_HF0 = 9.98e-07;
q_FR_HS0 = -0.9706;
q_FR_K0 = 0.06964;
q_FL_HF0 = -1.003;
q_FL_HS0 = -1.172;
q_FL_K0 = -0.02261;
q_BR_HF0 = 9.932e-07;
q_BR_HS0 = 0.4184;
q_BR_K0 = -0.08643;
q_BL_HF0 = -9.932e-07;
q_BL_HS0 = -0.4272;
q_BL_K0 = 0.08643;


% initial body position, adding vertical distance to account for sphere on
% feet end
p_b0 = [0, 0, 0.44];

% intial leg locations relative to corresponding hip of each leg, in the
% following format:
% [p_FR(x,y,z), p_FL(x,y,z), p_BR(x,y,z), p_BL(x,y,z)]
%
% NOTE: hip coupling in CAD not assembled correctly, there is a 0.053 m
% offset in +x direction for all legs
%
% p_init = [-0.072127,-0.0350,-0.42342,  -0.072127,0.0350,-0.42342,  -0.072127,-0.0350,-0.42342,   -0.072127,0.0350,-0.42342];

p_init = [-0.072127,0,-0.42342,  -0.072127,0,-0.42342,  -0.072127,0,-0.42342,   -0.072127,0,-0.42342];
% p_init = p_init + [0.2,0,0.039,  0.2,0,0.039,  0,0,0,   0,0,0];
p_init = p_init + 1*[0.2,0.05,0.001,  0.2,0.35,0.2,  -0.1,-0.1,0,   -0.1,0.1,0];
% p_init = p_init + 1*[0.1,-0.02,0.004,  0.1,-0.02,0.004,  -0.1,-0.1,0,   -0.1,0.1,0];

% p_init = [0.072127,-0.0350,-0.42342,  0.072127,0.0350,-0.42342,  0.072127,-0.0350,-0.42342,   0.072127,0.0350,-0.42342];
% p_init = p_init + [0,0,0,  0,0,0,  0,0,0,   0,0,0];

backbone_mass_pos_wrt_body = [0.021107, -5.5457e-05, -0.041523];


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
% body mass,as described by CAD model
body.mass=2.2337;
body.MomentsofInertia=[0.0030709, 0.0046624, 0.0035462];
body.ProductsofInertia=[0.00010331, 0.00058252, -0.00020765];

femur_left.mass=0.71952;
femur_left.MomentsofInertia=[0.00047141, 0.00072824, 0.00044539];
femur_left.ProductsofInertia=[-1.4185e-06, -3.9569e-05, -6.3308e-06];

femur_right.mass=0.71952;
femur_right.MomentsofInertia=[0.00047141, 0.00072824, 0.00044539];
femur_right.ProductsofInertia=[1.4185e-06, 3.9569e-05, -6.3308e-06];

% Original values 
% 
% hip_left.mass=0.02228;
% hip_left.MomentsofInertia=[0.00000585,  0.00001678, 0.00001514];
% hip_left.ProductsofInertia=[0, -5e-08, 1.48e-06];
% 
% hip_right.mass=0.02228;
% hip_right.MomentsofInertia=[0.00000585,  0.00001678, 0.00001514];
% hip_right.ProductsofInertia=[0, 5e-08, -1.48e-06];

% tibia_left.mass=0.323034205629986;
% tibia_left.MomentsofInertia=[0.0005802981403470251, 0.000703725589207329, 0.000533163251971044];
% tibia_left.ProductsofInertia=[-5.14070037039191e-07, -4.54880548592882e-05, 1.21346102972198e-06];
% 
% tibia_right.mass=0.323034205629986;
% tibia_right.MomentsofInertia=[0.0005802981403470251, 0.000703725589207329, 0.000533163251971044];
% tibia_right.ProductsofInertia=[-5.14070037039209e-07, 4.54880548592882e-05, -1.21346102972198e-06];
% 
% tarsus_left.mass=0.18284;
% tarsus_left.MomentsofInertia=[0.00012076, 0.00011699, 2.5133e-05];
% tarsus_left.ProductsofInertia=[3.7744e-12, -6.9478e-13, -8.513900000000001e-12];
% 
% tarsus_right.mass=0.18284;
% tarsus_right.MomentsofInertia=[0.00012076, 0.00011699, 2.5133e-05];
% tarsus_right.ProductsofInertia=[-3.7744e-12, 6.9478e-13, -8.513900000000001e-12];

hip_left.mass=0.001;
hip_left.MomentsofInertia=[0, 0, 0];
hip_left.ProductsofInertia=[0, 0, 0];

hip_right.mass=0.001;
hip_right.MomentsofInertia=[0, 0, 0];
hip_right.ProductsofInertia=[0, 0, 0];

tibia_left.mass=0.001;
tibia_left.MomentsofInertia=[0, 0, 0];
tibia_left.ProductsofInertia=[0, 0, 0];

tibia_right.mass=0.001;
tibia_right.MomentsofInertia=[0, 0, 0];
tibia_right.ProductsofInertia=[0, 0, 0];

tarsus_left.mass=0.001;
tarsus_left.MomentsofInertia=[0, 0, 0];
tarsus_left.ProductsofInertia=[0, 0, 0];

tarsus_right.mass=0.001;
tarsus_right.MomentsofInertia=[0, 0, 0];
tarsus_right.ProductsofInertia=[0, 0, 0];

link_right.mass=0.0;
link_right.MomentsofInertia=[0,0,0];
link_right.ProductsofInertia=[0,0,0];

link_left.mass=0.0;
link_left.MomentsofInertia=[0 0 0];
link_left.ProductsofInertia=[0 0 0];

% link_right.mass=0.022232;
% link_right.MomentsofInertia=[9.8756e-07, 2.5372e-05, 2.4918e-05];
% link_right.ProductsofInertia=[-2.764e-14, 1.2525e-13, -3.8111e-08];
% 
% link_left.mass=0.022232;
% link_left.MomentsofInertia=[9.8756e-07, 2.5372e-05, 2.4918e-05];
% link_left.ProductsofInertia=[-2.764e-14, -1.2498e-13, 3.8111e-08];

