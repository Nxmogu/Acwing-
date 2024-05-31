#include <iostream>
using namespace std;
#define N 100000
int q[N],hh,tt;
void Init(){
    hh=0;//队头
    tt=-1;//队尾
}
void Push(int x){
    q[++tt]=x;
}
int Pop(){
    return q[hh++];
}
int Query(){
    return q[hh];
}
void IsEmpty(){
    if(hh>tt)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
int main(){
    int n;
    cin>>n;
    Init();
    while(n--){
        string c;
        cin>>c;
        if(c=="push"){
            int x;
            cin>>x;
            Push(x);
        }
        else if(c=="pop"){
            Pop();
        }
        else if(c=="query"){
            cout<<Query()<<endl;
        }
        else if(c=="empty"){
            IsEmpty();
        }
    }
}