#include <iostream>
#include <deque>
using namespace std;
#define N 10000010
int a[N],q[N],tt,hh;
void Init(){
    hh=0;
    tt=-1;
}
int main(){
    Init();
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    deque<int> q;
    for(int i=0;i<n;i++){
        while(q.size()&&q.back()>a[i])//假如双头队列不为空且新加入元素大于队尾元素则队尾元素出列保持队列元素升序
            q.pop_back();
        q.push_back(a[i]);
    if(i-k>=0&&q.front()==a[i-k])//当队列数大于窗口数值且最小值刚好是队头则队头元素出队
        q.pop_front();
    if(i>=k-1)
        cout<<q.front()<<' ';
    }
    //最大值同理只是将双头队列变为降序
    q.clear();
    cout<<endl;
    for(int i=0;i<n;i++){
        while(q.size()&&q.back()<a[i])
            q.pop_back();
        q.push_back(a[i]);
    if(i-k>=0&&q.front()==a[i-k])
        q.pop_front();
    if(i>=k-1)
        cout<<q.front()<<' ';
    }
}
/*
常见模型：找出滑动窗口中的最大值/最小值
int hh = 0, tt = -1;
for (int i = 0; i < n; i ++ )
{
    while (hh <= tt && check_out(q[hh])) hh ++ ;  // 判断队头是否滑出窗口
    while (hh <= tt && check(q[tt], i)) tt -- ;
    q[ ++ tt] = i;
}
*/