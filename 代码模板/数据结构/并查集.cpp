#include <iostream>
#include <string>
using namespace std;
#define N 1000000
//存储父节点的编号i的父节点的编号为pre[i]
int pre[N];
//该节点是多少个节点的父节点包括自己本身
int my_rank[N];

//初始化
void Init(){
    for(int i=0;i<N;i++){
        pre[i] = i;
        my_rank[i] = 1;
    }
}
//寻找并优化路径，将所有节点挂在一个父节点下面
int find(int x){
    if(pre[x]!=x)
        pre[x] = find(pre[x]);
    return pre[x];
}
//合并
bool join(int x,int y){
    int pre_x = find(x);
    int pre_y = find(y);
    if(pre_x == pre_y)
        return false;
    //将节点少的挂在节点多的下面
    if(my_rank[pre_x]>my_rank[pre_y]){
        my_rank[pre_x]+=my_rank[pre_y];
        pre[pre_y] = pre_x;
    }
    else{
        my_rank[pre_y]+=my_rank[pre_x];
        pre[pre_x] = pre_y;
    }
        
    return true;
}
int main(){
    Init();
    int n=0,m=0;
    cin >> n >> m;
    string c;
    for(;m>0;m--){
        cin >> c;
        if(c == "C"){
            int i,j;
            cin >> i >> j;
            join(i,j);
        }
        if(c == "Q1"){
            int i,j;
            cin >> i >> j;
            if(find(i)==find(j))
                cout<<"Yes"<<endl;
            else
                cout<<"No"<<endl;
        }
        if(c == "Q2"){
            int i;
            cin >> i ;
            cout<<my_rank[find(i)]<<endl;
        }
    }
}