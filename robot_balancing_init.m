Ts=0.0001;

amplitude_x=10*pi/180;
amplitude_y=10*pi/180;
amplitude_z=50*pi/180;
f_x=5;
f_y=5;
f_z=1;
p_show=[0.3;-0.2;0];
init_position=[0,0,0.65];
length_mid=0.001;
% 
q_x=[-0.2,0.2,-0.2,0.2];
q_y=[-0.2,-0.2,0.2,0.2];
q_z=[0,0,0,0];
l=[-0.6,-0.6,-0.6,-0.6];
desired_q=zeros(1,16);
for i = 1:4
    desired_q(4*i-3:4*i)=[q_x(i),q_y(i),q_z(i),l(i)];
end
% desired_q=[-0.,0.1,0,0.6,0.1,0.1,0,0.6,-0.1,-0.1,0,0.6,0.1,-0.1,0,0.6];
% desired_leg=-[0,0,0,0.5,0,0,0,1,0,0,0,-0.5,0,0,0,-1];
% Contact model parameters
% Normal force
c_k = 5e3;
c_b = 2e2;
% Friction
mu_k = 0.5;
mu_s = 0.7;
v_th = 0.0001; %m/s


% angle_gain=2;
% leg_gain=1;
gain=6;


for i=1:4
    eval(['roll',num2str(i),'=q_x(',num2str(i),');']);
    eval(['pitch',num2str(i),'=q_y(',num2str(i),');']);
    eval(['yaw',num2str(i),'=q_z(',num2str(i),');']);
    eval(['l',num2str(i),'=l(',num2str(i),');']);
end

init_position=[0,0,0.8];

        