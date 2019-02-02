#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

/**
 * ICPC Central Europe Regional Contest 2018
 * Sample solution: Game of Stones
 * 
 * @author Vaclav Blazej
 */

int main(){
    ll N,A,B;cin>>N>>A>>B;
    vector<ll> a(N),nimber(N);
    for(ll &n:a)cin>>n;
    for(int i=0; i<N; ++i){
        nimber[i]=a[i]%(A+1);
    }
    ll x=0;
    for(ll n:nimber)x^=n;
    ll pile=-1,take=-1;
    if(x){
        ll b=1<<30;
        while(b>0 && (b&x)==0)b>>=1;
        for(int i=0; i<N; ++i){
            if((nimber[i]&b)!=0){
                pile=i;
                break;
            }
        }
        if(B>A){
            ll cnt=0,b=-1;
            for(int i=0; i<N; ++i)if(a[i]>A){cnt++;pile=i;}
              pile=-1; // enemy advantage, he can play 0 next move
            else if(cnt==1){ // enemy advantage, but can we play to this particular pile and make it small?
                ll goal=nimber[pile]^x;
                take=(a[pile]-goal)%(A+1);
                if(a[pile]-take>A)pile=-1;
            }else{ // we can really win!
            }
        }
    }else{
        if(A>B){ // weird nim: if A > B then we can play B+1! which is 0-move
            for(int i=0; i<N; ++i){
                if(a[i]>B){
                    pile=i;
                    take=B;
                    break;
                }
            }
        }else{ // classical nim: no way to win, xor==0 :(
        }
    }
    if(pile!=-1){
        if(take==-1){
            ll goal=nimber[pile]^x;
            take=(a[pile]-goal)%(A+1);
        }
        cout<<"Petyr\n";
        //cout<<1+pile<<' '<<take<<endl;
    }else{
        cout<<"Varys\n";
    }
    return 0;
}

