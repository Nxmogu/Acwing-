#include <iostream>
using namespace std;
#define N 100000
class My_Queue{
public:
    My_Queue(){
        this->hh=0;
        this->tt=0;
    }
    void push(int x){
        if(tt==N)
            tt=0;
        e[tt++]=x;
    }
    void pop(){
        if(hh==N)
            hh=0;
        hh++;
    }
    void query(){
        cout<< e[hh]<<endl;
    }
    void IsEmpty(){
        if(hh!=tt)
            cout<<"NO"<<endl;
        if(hh==tt)
            cout<<"YES"<<endl;
    }
private:
    int hh;//队头
    int tt;//队尾
    int e[N];
};
int main(){
    My_Queue q;
    int n;
    cin>>n;
    while(n--){
        string c;
        cin>>c;
        if(c=="push"){
            int x;
            cin>>x;
            q.push(x);
        }
        else if(c=="empty")
            q.IsEmpty();
        else if(c=="pop")
            q.pop();
        else if(c=="query")
            q.query();
    }
}