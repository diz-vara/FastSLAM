
% Initialisations
particles= initialise_particles(NPARTICLES);
xtrue= zeros(3,1);



dt= DT_CONTROLS;    % change in time between predicts
dtsum= 0;           % change in time since last observation
ftag= 1:size(lm,2); % identifier for each landmark
da_table= zeros(1,size(lm,2)); % data association table 
iwp= 1;             % index to first waypoint 
G= 0;               % initial steer angle
plines=[];
if SWITCH_SEED_RANDOM ~= 0, rand('state',SWITCH_SEED_RANDOM), randn('state',SWITCH_SEED_RANDOM), end

Qe= Q; Re= R;

h= setup_animations(lm,wp);
veh= [0 -WHEELBASE -WHEELBASE; 0 -1 1];


function p= initialise_particles(np)
  for i=1:np
      p(i).w= 1/np;
      p(i).xv= [0;0;0];
      p(i).Pv= zeros(3);
      p(i).xf= [];
      p(i).Pf= [];
      p(i).da= [];
  end
end

%don't implement this
function p= make_covariance_ellipses(particle)
N= 10;
inc= 2*pi/N;
phi= 0:inc:2*pi;
circ= 2*[cos(phi); sin(phi)];

p= make_ellipse(particle.xv(1:2), particle.Pv(1:2,1:2) + eye(2)*eps, circ);

  lenf= size(particle.xf,2);
  if lenf > 0
      
      xf= particle.xf;
      Pf= particle.Pf;
      p= [p zeros(2, lenf*(N+2))];

      ctr= N+3;
      for i=1:lenf
          ii= ctr:(ctr+N+1);
          p(:,ii)= make_ellipse(xf(:,i), Pf(:,:,i), circ);
          ctr= ctr+N+2;
      end
  end
end
  
%don't implement this
function p= make_ellipse(x,P,circ)
  % make a single 2-D ellipse 
  r= sqrtm_2by2(P);
  a= r*circ;
  p(2,:)= [a(2,:)+x(2) NaN];
  p(1,:)= [a(1,:)+x(1) NaN];
end
%
%

%don't implement this
function h= setup_animations(lm,wp)
  figure
  plot(lm(1,:),lm(2,:),'g*', 'markersize', 10)
  hold on, axis equal
  plot(wp(1,:),wp(2,:), wp(1,:),wp(2,:),'ro')

  h.xt= patch(0,0,'g','erasemode','xor'); % vehicle true
  h.xm= patch(0,0,'r','erasemode','xor'); % mean vehicle estimate
  h.obs= plot(0,0,'m','erasemode','xor'); % observations
  h.obs1= plot(0,0,'c','erasemode','xor'); % observations
  h.xfp= plot(0,0,'r.','erasemode','background'); % estimated features (particle means)
  h.xvp= plot(0,0,'r.','erasemode','xor'); % estimated vehicle (particles)
  h.cov= plot(0,0,'erasemode','xor'); % covariances of max weight particle
end
  
%dont implement this
function do_plot(h, particles, xtrue, plines, veh, z)

  xvp = [particles.xv];
  xfp = [particles.xf];
  w = [particles.w]; 

  ii= find(w== max(w)); 
  xvmax= xvp(:,ii);
  plines1=make_laser_lines(z,xvmax);


  xt= TransformToGlobal(veh,xtrue);
  xm= TransformToGlobal(veh,xvmax);
  set(h.xt, 'xdata', xt(1,:), 'ydata', xt(2,:))
  set(h.xm, 'xdata', xm(1,:), 'ydata', xm(2,:))
  set(h.xvp, 'xdata', xvp(1,:), 'ydata', xvp(2,:))
  if ~isempty(xfp), set(h.xfp, 'xdata', xfp(1,:), 'ydata', xfp(2,:)), end
  if ~isempty(plines), set(h.obs, 'xdata', plines(1,:), 'ydata', plines(2,:)), end
  if ~isempty(plines1), set(h.obs1, 'xdata', plines1(1,:), 'ydata', plines1(2,:)), end
  pcov= make_covariance_ellipses(particles(ii(1)));
  if ~isempty(pcov), set(h.cov, 'xdata', pcov(1,:), 'ydata', pcov(2,:)); end

  drawnow
end
