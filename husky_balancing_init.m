

amplitude_x=15*pi/180;
amplitude_y=10*pi/180;
amplitude_z=45*pi/180;
amplitude_height=0;
f_x=4*pi;
f_y=2*pi;
f_z=2*pi;
f_height=2;

x_start=2;
x_stop=4;
y_start=2;
y_stop=4;
z_start=4;
z_stop=6;

sign_convert=[-1;1;1;1;1;1;-1;1;1;1;1;1];
% initial_configuration=[0.3449;0.8327;0.2679;    0.3449;0.8327;0.2679;    0.3449;0.2968;0.2679;    0.3449;0.2968;0.2679].*sign_convert;
initial_configuration=repmat([10;40;25],4,1).*pi/180.*sign_convert;

% initial_configuration=[5;50;5;5;50;5;5;35;15;5;35;15].*pi/180.*sign_convert;
gain=1;

control_params_init;
func_params_ext;
