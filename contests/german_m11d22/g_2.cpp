#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
typedef long long ll;
struct Point{int x,y;}p[MAX];
Point operator+(Point A,Point B){return (Point){A.x+B.x,A.y+B.y};}        //vector A+B
Point operator-(Point A,Point B){return (Point){A.x-B.x,A.y-B.y};}        //vector A-B
ll operator^(Point A,Point B){return 1ll*A.x*B.y-1ll*A.y*B.x;}            //corss(A,B)
ll Polyarea(Point *p,int n)
{
    ll area=0;
    for(int i=1;i<n-1;i++)area+=(p[i]-p[0])^(p[i+1]-p[0]);
    return abs(area);
}
int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
int cal(Point A,Point B)
{
    if(A.x==B.x)return abs(A.y-B.y)-1;
    if(A.y==B.y)return abs(A.x-B.x)-1;
    return gcd(abs(B.y-A.y),abs(B.x-A.x))-1;
}
int main()
{printf("%d\n",__gcd(10,0));
    int n;
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d%d",&p[i].x,&p[i].y);
    ll S=Polyarea(p,n);
    printf("%lld\n",S);
    ll m=n;
    for(int i=0;i<n;i++)m+=cal(p[i],p[(i+1)%n]),printf("%d\n",cal(p[i],p[(i+1)%n]));
    printf("%lld\n",(S-m+2)/2);
}
