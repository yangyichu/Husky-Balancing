T_FR=[zeros(3,3),[0.3;0.2;0];0,0,0,1]; 
R_FR=[eul2rotm([30*pi/180,0,0],'XYZ'),[0;0;0];0,0,0,1];
% p_FR_e_h=R_FR*T_FR*[0;0;-1;1]
% eul2rotm([30*pi/180,0,0],'XYZ')
d_eul=[0.1,0.2,0.3];
R=eul2rotm(d_eul,'XYZ');
% q=quaternion(eul2quat(d_eul,'XYZ'));
q=quaternion(rotm2quat(R));
q=q./norm(q)
% q*(conj(q)./norm(q));

A=[0;0;-0.6];
x1=R*A;
qA=quaternion([0;A]');
RR1=quat2rotm(q)
eul1=rotm2eul(RR1,'XYZ')
x2=q*qA'*(conj(q)./norm(q))

% 
% 
% % rotm_z_h(0.3)*rotm_y_h(0.2)*rotm_x_h(0.1)
% x=R*[0;0;-0.6];
q2=quaternion(vec2quat2(A,x1));
q2=q2./norm(q2)
% q2=quaternion(vec2quat2(x1,A));
RR2=quat2rotm(q2)
eul2=rotm2eul(RR2,'XYZ')

x3=q2*qA'*(conj(q2)./norm(q2))
% quat2eul(eul2quat([0.1,0.2,0.4],'XYZ'),'XYZ')
% A=[0;0;-0.6];
% k=cross(A,x)
% t=acos(A'*x/norm(A)/norm(x));
% k1=k(1);
% k2=k(2);
% k3=k(3);
% R=eye(3,3)*cos(t)+(1-cos(t))*[k1;k2;k3]*[k1,k2,k3]+sin(t)*[0,-k3,k2;k3,0,-k1;-k2,k1,0]
% b=atan2(-R(3,1),sqrt(R(3,2)^2+R(3,3)^2))
% a=atan2(R(3,2)/cos(b),R(3,3)/cos(b))
% v=atan2(R(2,1)/cos(b),R(1,1)/cos(b))
% 
%  p1 = A; p2 = x;
function q=vec2quat2(p1,p2)
    u = cross(p1,p2)/norm(cross(p1,p2));
    alpha = acos(dot(p1,p2)/(norm(p1)*norm(p2)));
    q = [cos(alpha/2), sin(alpha/2)*u(1), sin(alpha/2)*u(2), sin(alpha/2)*u(3)]
end
 %  angle= quat2eul(q,'XYZ')
%  angle= quat2eul(q)
% 
% function rotm=rotm_z_h(theta)
%     rotm=[cos(theta),-sin(theta),0,0;sin(theta),cos(theta),0,0;0,0,1,0;0,0,0,1];
% end
% 
function q=vec2quat(u,v)
    q=zeros(4);
    nu=u/norm(u);
    nv=v/norm(v);
    if norm(nu+nv)==0
    q = [0,1,0,0];
    else
    half = (nu + nv)/norm(nu + nv);
    q = [nu'*half;cross(nu, half)];
    end
end