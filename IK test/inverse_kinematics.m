% syms r q1 q2 leg_length 
% p_U=[0;0;leg_length];
% p_U_h=[p_U;1];
% T=[eye(3,3),[0;r;0];0 0 0 1];
% R1=[1 0 0 0;0 cos(q1) -sin(q1) 0;0 sin(q1) cos(q1) 0;0 0 0 1];
% R2=[cos(q2),0,sin(q2),0;0,1,0,0;-sin(q2),0,cos(q2),0;0,0,0,1];
% p_W=R1*T*R2*p_U_h;
% 
% [q1,q2,l1]=IK([0.5,0.3,-0.8])
% 
% function [q1,q2,virtual_leg_length]=IK(p)
% r=-0.1;
% total_leg_length=norm(p);
% virtual_leg_length=sqrt(total_leg_length^2-r^2);
% virtual_leg_length=sqrt(p(1)^2+p(2)^2+p(3)^2-r^2)
% q2=acos(sqrt((p(2)^2+p(3)^2-r^2)/virtual_leg_length^2))
% q22=asin(p(1)/virtual_leg_length)
% p(1)/sin(q2)
% p1=p(1);
% p2=p(2);
% p3=p(3);
% a=(p3+sqrt(p3^2-r^2+p1^2))/(r+p1);
% a2=(p3-sqrt(p3^2-r^2+p1^2))/(r+p1)
% atan(a)
% atan(a2)
% 
% % q1=acos(p(3)-r*sin(q1))
% % l2=(p(2)-r)/(cos(q2)*sin(q1));
% q1=0;
% end

%husky IK
syms q1 q2 q3 L1 L2 L3

husky_R1=[cos(-q1),0,sin(-q1),0;0,1,0,0;-sin(-q1),0,cos(-q1),0;0,0,0,1];
husky_T1=[eye(3,3),[0;0;-L1];0 0 0 1];
husky_R2=[cos(-q2),0,sin(-q2),0;0,1,0,0;-sin(-q2),0,cos(-q2),0;0,0,0,1];
husky_T2=[eye(3,3),[-L2;0;0];0 0 0 1];
husky_R3=[cos(q2),0,sin(q2),0;0,1,0,0;-sin(q2),0,cos(q2),0;0,0,0,1];
husky_ftend=[0;0;-L3;1];
foot_end=husky_R1*(husky_T1*husky_R2)*(husky_T2*husky_R3)*husky_ftend