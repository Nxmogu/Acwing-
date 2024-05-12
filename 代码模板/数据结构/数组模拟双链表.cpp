#include <iostream>
using namespace std;
#define N 100000
int e[N],l[N],r[N],idx;
void Init(){
    r[0] = 1;
    l[1] = 0;
    idx = 2;
}
void Insert(int k,int x){
    e[idx]=x;
    l[idx]=k;
    r[idx]=r[k];
    l[r[k]]=idx;
    r[k]=idx;
    idx++;
}
void Remove(int k){
    r[l[k]]=r[k];
    l[r[k]]=l[k];
}
int main(){
    Init();
    int n=0;
    cin>>n;
    while(n--){
        string c;
        cin>>c;
        if(c=="L"){
            int x;
            cin>>x;
            Insert(0,x);
        }
        else if(c=="R"){
            int x;
            cin>>x;
            Insert(l[1],x);
        }
        else if(c=="D"){
            int k;
            cin>>k;
            Remove(k+1);
        }
        else if(c=="IL"){
            int k,x;
            cin>>k>>x;
            Insert(l[k+1],x);
        }
        else if(c=="IR"){
            int k,x;
            cin>>k>>x;
            Insert(k+1,x);
        }
    }
    for(int x = r[0];x!=1;x=r[x]){
        printf("%d ",e[x]);
    }
}