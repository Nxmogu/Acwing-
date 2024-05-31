#include <iostream>
using namespace std;
#define N 1000000
int stk[N],tt;
void Init(){
    tt = -1;
}
int main(){
    Init();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        //假若栈不为空则一直寻找左边比它小的第一个数
        while(tt>=0&&stk[tt]>=x){
            tt--;   
        }
        //成功找到输出
        if(tt>=0){
            cout<<stk[tt]<<' ';
        }
        //没找到则为-1
        else{
            cout<<"-1"<<' ';
        }
        //入栈
        stk[++tt]=x;
    }
}

/*
常见模型：找出每个数左边离它最近的比它大/小的数
int tt = 0;
for (int i = 1; i <= n; i ++ )
{
    while (tt && check(stk[tt], i)) tt -- ;
    stk[ ++ tt] = i;
}
*/