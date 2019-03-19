#include<cstdio>
#include<cstring>
using namespace std;
char ch[35];
int main(){
    int n,m,i,j,k,s,t;
    scanf("%d",&n);
    while(n--){
        memset(ch,0,sizeof(ch));
        scanf("%s",ch);
        s=strlen(ch);
        if(ch[s-1]=='a'){
            ch[s]='s';
        }else if(ch[s-1]=='i'||ch[s-1]=='y'){
            ch[s-1]='i';
            ch[s]='o';
            ch[s+1]='s';
        }else if(ch[s-1]=='l'){
            ch[s]='e';
            ch[s+1]='s';
        }else if(ch[s-1]=='n'){
            ch[s-1]='a';
            ch[s]='n';
            ch[s+1]='e';
            ch[s+2]='s';
        }else if(ch[s-2]=='n'&&ch[s-1]=='e'){
            ch[s-2]='a';
            ch[s-1]='n';
            ch[s]='e';
            ch[s+1]='s';
        }else if(ch[s-1]=='o'){
            ch[s]='s';
        }else if(ch[s-1]=='r'){
            ch[s]='e';
            ch[s+1]='s';
        }else if(ch[s-1]=='t'){
            ch[s]='a';
            ch[s+1]='s';
        }else if(ch[s-1]=='u'){
            ch[s]='s';
        }else if(ch[s-1]=='v'){
            ch[s]='e';
            ch[s+1]='s';
        }else if(ch[s-1]=='w'){
            ch[s]='a';
            ch[s+1]='s';
        }else{
            ch[s]='u';
            ch[s+1]='s';
        }
        printf("%s\n",ch);
    }
    return 0;
}