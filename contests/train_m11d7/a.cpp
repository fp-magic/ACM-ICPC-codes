
#include<cstring>
#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<queue>
#include<map>
using namespace std;
vector<int>a[200005];
int in[200005];
queue<int>q;
map<string,int>mp;
int main()
{
    int tot,n,m,i,j,k,s,t;
    string s1,s2,s3;
    while(cin>>n)
    {
        mp.clear();
        for(i=1;i<=2*n;i++)a[i].clear();
        memset(in,0,sizeof(in));
        tot=0;
        while(n--)
        {
            cin>>s1>>s2>>s3;
            if(mp.count(s1))
            {
                s=mp[s1];
            }else
            {
                mp.insert(make_pair(s1,++tot));
                s=tot;
            }
            if(mp.count(s3))
            {
                t=mp[s3];
            }else
            {
                mp.insert(make_pair(s3,++tot));
                t=tot;
            }
            if(s2[0]=='<')a[s].push_back(t),in[t]++;
            else a[t].push_back(s),in[s]++;
        }
        while(!q.empty())q.pop();
        t=0;
        for(i=1;i<=tot;i++)
            if(in[i]==0)q.push(i),t++;
        tot-=t;
        while(!q.empty())
        {
            s=q.front();q.pop();//cout<<s<<endl;
            for(i=0;i<a[s].size();i++)
            {
                in[a[s][i]]--;
                if(in[a[s][i]]==0)q.push(a[s][i]),tot--;
            }
        }
        if(tot==0)cout<<"possible"<<endl;
        else cout<<"impossible"<<endl;
    }
    return 0;
}