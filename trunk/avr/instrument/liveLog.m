fclose(conn)

conn=udp('localhost')
conn.LocalPort=21567
conn.Timeout=1000000
conn.TimerPeriod=10

fopen(conn)
conn.Timeout=1000000
conn.TimerPeriod=10

l=100;

rpm=zeros(1,l);
clt=zeros(1,l);
speed=zeros(1,l);
tp=zeros(1,l);
iat=zeros(1,l);
map=zeros(1,l);
bat=zeros(1,l);
lambda=zeros(1,l);
x=zeros(1,l);
y=zeros(1,l);
z=zeros(1,l);

i=1

mean_clt=0;
mean_iat=0;
mean_rpm=0;

while 1
  pause(0.2)
  dat=fread(conn,229)';
  
  if length(dat)<220
    continue
  end
 
  new_rpm=hex2dec(char(dat(54*2+1:55*2+2)))*0.9408;
  new_clt=hex2dec(char(dat(46*2+1:47*2+2)))*-150.0/3840+120;
  new_speed=hex2dec(char(dat(62*2+1:63*2+2)))*0.01;
  new_iat=hex2dec(char(dat(48*2+1:49*2+2)))*-150.0/3840+120;
  new_map=hex2dec(char(dat(64*2+1:64*2+2)))*1.0/800/5*3000;
  new_bat=hex2dec(char(dat(66*2+1:67*2+2)))*1.0/210;
  new_lambda=hex2dec(char(dat(68*2+1:69*2+2)));
  new_tp=hex2dec(char(dat(50*2+1:51*2+2)))*1/25.1-487/25.1;
  new_x=hex2dec(char(dat(50*2+1:51*2+2)))*1/25.1-487/25.1;
  new_x=hex2dec(char(dat(96*2+1:97*2+2)));
  new_y=hex2dec(char(dat(98*2+1:99*2+2)));
  new_z=hex2dec(char(dat(100*2+1:101*2+2)));
  
  if new_x<32768
    new_x=new_x*1.0/16384;
  else
    new_x=(-65535+new_x)*1.0/16384;
  end
  
  if new_y<32768
    new_y=new_y*1.0/16384;
  else
    new_y=(-65535+new_y)*1.0/16384;
  end
  
  if new_z<32768
    new_z=new_z*1.0/16384;
  else
    new_z=(-65535+new_z)*1.0/16384;
  end
  
  if new_lambda<32768
    new_lambda=new_lambda*-14.7*0.6/3840+0.7*14.7;
  else
    new_lambda=(-65535+new_lambda)*-14.7*0.6/3840+0.7*14.7;
  end
  
  if new_rpm<13000 && new_clt>10 && new_iat>5 && (i==1||(new_clt<clt(i-1)+5 && new_clt>clt(i-1)-5))
  
    rpm(i)=new_rpm;
    clt(i)=new_clt;
    speed(i)=new_speed;
    iat(i)=new_iat;
    map(i)=new_map;
    bat(i)=new_bat;
    lambda(i)=new_lambda;
    tp(i)=new_tp;
    x(i)=new_x;
    y(i)=new_y;
    z(i)=new_z;
    
    if mod(i,10)==1
      mean_rpm=mean(rpm);
      mean_rpm_s=num2str(mean_rpm);
      mean_clt=mean(clt);
      mean_clt_s=num2str(mean_clt);
      mean_iat=mean(iat);
      mean_iat_s=num2str(mean_iat);
      min_bat=min(bat);
      min_bat_s=num2str(min_bat);
    end
    
    figure(1)
    subplot(2,2,1)
    hold off
    plot(rpm)
    hold on
    plot([i,i],[0,12000],'r')
    axis([0 l 0 12000])
    plot([0,l],[mean_rpm,mean_rpm],'b--')
    legend(mean_rpm_s)
    grid on
    
%    subplot(2,2,2)
%    hold off
%    plot(speed)
%    hold on
%    plot([i,i],[0,120],'r')
%    axis([0 l 0 120])
%    grid on

    subplot(4,2,2)
    hold off
    plot(x)
    hold on
    plot([i,i],[-1.5,1.5],'r')
    axis([0 l -1.5 1.5])
    grid on
    
    subplot(4,2,4)
    hold off
    plot(y)
    hold on
    plot([i,i],[-1.5,1.5],'r')
    axis([0 l -1.5 1.5])
    grid on
    
    subplot(2,2,3)
    hold off
    plot(tp)
    hold on
    plot([i,i],[0,100],'r')
    axis([0 l 0 100])
    grid on
    
    subplot(4,2,6)
    hold off
    plot([0:5:l-1],clt(1:5:end),'m')
    hold on
    plot([0:5:l-1],iat(1:5:end),'b')
    plot([i,i],[0,120],'r')
    axis([0 l 10 120])
    plot([0,l],[mean_clt,mean_clt],'m--')
    legend(mean_clt_s,mean_iat_s)
    grid on
    
%    subplot(2,2,4)
%    hold off
%    plot(map)
%    hold on
%%    plot([i,i],[500,1500],'r')
%%    axis([0 100 500 1500])
%    grid on
    
    subplot(4,2,8)
    hold off
    plot([0:5:l-1],bat(1:5:end))
    hold on
    plot([0,l],[min_bat,min_bat],'b--')
    plot([i,i],[10,15],'r')
    axis([0 l 10 15])
    legend(min_bat_s)
    grid on
    
%    subplot(3,2,6)
%    hold off
%    plot(lambda)
%    hold on
%    plot([i,i],[9,15],'r')
%    axis([0 l 9 15])
%    grid on
    
    
    i=mod(i,l)+1;
  end
  
  
  

end

fclose(conn)
%echoudp('off')
