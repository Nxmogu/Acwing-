#include <iostream>
using namespace std;
#define N 100000
int my_stack[N],top;
void Init(){
    top = -1;
}
void IfEmpty(){
    if(top == -1)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}
void Push(int x){
    my_stack[++top]=x;
}
void Pop(){
    my_stack[top--]=0;
}
void GetTop(){
    cout<<my_stack[top]<<endl;
}
int main(){
    Init();
    int n;
    cin>>n;
    while(n--){
        string c;
        cin>>c;
        if(c== "push"){
            int x;
            cin>>x;
            Push(x);
        }
        else if(c == "query")
            GetTop();
        else if(c == "pop")
            Pop();
        else if(c == "empty")
            IfEmpty();
    }
}