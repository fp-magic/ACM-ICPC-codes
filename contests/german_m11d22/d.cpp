#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<map>
using namespace std;
map<string,int>mp;
vector<int>a[500];
queue<int>q;
int in[500];
vector<int>b[500];
int main()
{
    int n,m,i,j,k,s,t1,t2,tot,flag;
    string s1,s2,are,worse,than;
    cin>>n>>m;
    for(i=1;i<=2*n;i++)a[i].clear(),b[i].clear(),in[i]=0;
    while(!q.empty())q.pop();
    tot=0;
    while(n--)
    {
        cin>>s1>>are>>worse>>than>>s2;
        if(mp.count(s1))
        {
            t1=mp[s1];
        }else
        {
            mp.insert(make_pair(s1,++tot));
            t1=tot;
        }
        if(mp.count(s2))
        {
            t2=mp[s2];
        }else
        {
            mp.insert(make_pair(s2,++tot));
            t2=tot;
        }
        a[t1].push_back(t2);
        in[t2]++;
    }
    for(i=1;i<=tot;i++)
        if(in[i]==0)
            q.push(i);
    while(!q.empty())
    {
        s=q.front();q.pop();
        for(i=0;i<a[s].size();i++)
        {
            in[a[s][i]]--;
            if(in[a[s][i]]==0)q.push(a[s][i]);
            for(j=0;j<b[s].size();j++)
                b[a[s][i]].push_back(b[s][j]);
            b[a[s][i]].push_back(s);
        }
    }
    while(m--)
    {
        cin>>s1>>are>>worse>>than>>s2;
        if(mp.count(s1))
        {
            t1=mp[s1];
        }else
        {
            mp.insert(make_pair(s1,++tot));
            t1=tot;
        }
        if(mp.count(s2))
        {
            t2=mp[s2];
        }else
        {
            mp.insert(make_pair(s2,++tot));
            t2=tot;
        }
        flag=0;
        for(i=0;i<b[t1].size();i++)
            if(b[t1][i]==t2)
                flag=1;
        for(i=0;i<b[t2].size();i++)
            if(b[t2][i]==t1)
                flag=2;
        if(flag==0)
            printf("Pants on Fire\n");
        if(flag==1)
            printf("Alternative Fact\n");
        if(flag==2)
            printf("Fact\n");
    }
    return 0;
}