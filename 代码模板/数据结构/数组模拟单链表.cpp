//仅用于算法,工程上基本用动态vector
#define N 10000
int e[N];//存储数据
int ne[N];//存储next
int head;//存储头指针
int idx;//存储可用索引
//初始化
void Init(){
    head = -1;
    idx = 0;
}
//在头指针之后插入一个新节点
void AddtoHead(int x){
    e[idx]=x;
    ne[idx]=head;
    head = idx;
    idx++;
}
//在k之后插入x
void Add(int k,int x){
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx;
    idx++;
}
//删除k后面的一个节点
void Remove(int k){
    if(ne[k] == -1)
        return;
    ne[k]=ne[ne[k]];
}
// 将头结点删除，需要保证头结点存在
void remove()
{
    head = ne[head];
}