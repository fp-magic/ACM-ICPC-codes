#include <cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
map<string,int>mp;
vector<pair<string,int> >ve;
int main()
{
    string s;
    int n,m,i,j,k,t;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>s;
        mp.insert(make_pair(s,i));
    }
    scanf("%d",&m);
    ve.clear();
    k=0;
    for(i=1;i<=m;i++)
    {
        cin>>s>>t;
        k+=t;
        if(!mp.count(s))ve.push_back(make_pair(s,t));
    }
    sort(ve.begin(),ve.end());
    j=0;
    for(i=0;i<ve.size();++i){
        if(ve[i].second*m>k)
            cout<<ve[i].first<<endl,j++;
    }
    if(!j)cout<<"Bing Mei You";
    return 0;
}