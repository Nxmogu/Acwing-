#include <iostream>
#include <vector>
#include <list>
//搜索数组
class DFS{
public:
    DFS(){}
    void Begin(int cur,int n,std::vector<int>& num){
        if(cur == n){
            for(int i=0;i<n;i++)
                std::cout<<num[i]<<" ";
        }
        else{
            for(int i=0;i<n;i++){       //遍历 n个数，并从中选择k个数
                if(_book[num[i]]==0){   //若没有被访问
                    _a.push_back(num[i]); //选定本数字，并加入数组 
                    _book[num[i]]=1;   //标记已被访问
                    Begin(cur+1,num.size(),num);  //递归，cur+1 
                    _book[num[i]]=0;  //释放，标记为没被访问，方便下次引用
                    _a.pop_back();    //弹出刚刚标记为未访问的数
                }
            }
        }
    }
public:
    std::vector<int> _book;
    std::vector<int> _a;
};
//搜索图
class Graph {
public:
    // 构造函数，初始化顶点数量和邻接表
    Graph(int V) : V(V), adj(new std::list<int>[V]) {}

    // 添加边到图中
    void addEdge(int v, int w) {
        adj[v].push_back(w); // 在v的列表中添加w
    }

    // 对图进行深度优先搜索
    void DFS(int v) {
        // 将所有顶点标记为未访问
        std::vector<bool> visited(V, false);

        // 调用递归辅助函数
        DFSUtil(v, visited);
    }

private:
    int V; // 顶点数量
    std::list<int> *adj; // 指向包含邻接表的数组的指针

    // 递归辅助函数，用于深度优先搜索
    void DFSUtil(int v, std::vector<bool> &visited) {
        // 将当前节点标记为已访问并打印
        visited[v] = true;
        std::cout << v << " ";
        // 对所有与此顶点相邻的顶点进行递归
        std::list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i)
            if (!visited[*i])
                DFSUtil(*i, visited);
    }
};
