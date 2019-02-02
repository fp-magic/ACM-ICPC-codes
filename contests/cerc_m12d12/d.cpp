#include<bits/stdc++.h>
using namespace std;
double ans(double a,double b,double c){
    //printf("%.6f %.6f %.6f\n",a,b,c);
    if(b*b-a*c*4.0<=0)return -1;
    return (-b+sqrt(b*b-a*c*4.0))/(a*2.0);
}
int main(){
    double tf,vf,hf,td,vd,hd,t1,t2,t3,t4,b,vdd,tans,tmp;
    scanf("%lf%lf%lf%lf%lf%lf",&tf,&vf,&hf,&td,&vd,&hd);
    vdd=sqrt(hd*6.0);
    t1=(-tf*vf+td*vd)/(vd-vf);
    t2=ans(2,-tf-td*3.0-vdd,-tf*tf*0.5+td*td*1.5+vdd*td+hf);
    t3=ans(0.5,tf,tf*tf*0.5+hd-hf);
    t4=sqrt(hf*2.0)+tf;
    
    //printf("%.6f %.6f %.6f %.6f\n",t1,t2,t3,t4);
    if(t1<=t3&&t3-td>=sqrt(hd*2.0/3.0)){
        tans=t3*2.0-td;//puts("1");
    }else
    if(t1<=t4){
        tans=max(t2*2.0-td,max(t1*2.0-td,));//puts("2");
    }else{
        tans=(t4-tf)*vf/vd*2.0+td;//puts("3");
    }
    printf("%.6f\n",tans);
    return 0;
}