desired_input=[0,0,0,0,0,0,0,0,0,0,0,0];

% ctrl.pos_kp = 30;
hipf_ctrl.pos_kp = 50;
hipf_ctrl.pos_ki = 0;
hipf_ctrl.pos_kd = 10;
% ctrl.vel_kp = 4.4;
hipf_ctrl.vel_kp = 10;
hipf_ctrl.vel_ki = 0;
hipf_ctrl.vel_kd = 0;

hips_ctrl.pos_kp = 50;
hips_ctrl.pos_ki = 0;
hips_ctrl.pos_kd = 10;
hips_ctrl.vel_kp = 10;
hips_ctrl.vel_ki = 0;
hips_ctrl.vel_kd = 0;

knee_ctrl.pos_kp = 50;
knee_ctrl.pos_ki = 0;
knee_ctrl.pos_kd = 10;
knee_ctrl.vel_kp = 10;
knee_ctrl.vel_ki = 0;
knee_ctrl.vel_kd = 0;