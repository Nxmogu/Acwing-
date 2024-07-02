#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;
class TrieNode{
public:
    TrieNode():Isword(false),child(26,nullptr){
    }
public:
    bool Isword;
    vector<TrieNode*> child;
};
class TrieTree{
public:
    TrieTree(){
        if(root == nullptr)
            root = new TrieNode();
    }
    void Insert(string s){
        TrieNode * cur = root;
        for(int i=0;i<s.size();i++){
            if(cur->child[s[i]-'a']==nullptr)
                cur->child[s[i]-'a'] = new TrieNode();
            cur = cur->child[s[i]-'a'];
        }
        cur->Isword = true;
    }
    bool Search(string s){
        TrieNode * cur = root;
        for(int i=0;i<s.size();i++){
            if(cur->child[s[i]-'a']==nullptr)
                return false;
            else
                cur = cur->child[s[i]-'a'];
        }
        return cur->Isword;
    }
public: 
    TrieNode* root = nullptr;
};
int main(){
    TrieTree t;
    t.Insert(string("shabi"));
    t.Insert(string("nihao"));
    if(t.Search(string("shabi"))){
        cout << "寻找shabi成功"<<endl;
    }
    if(!t.Search(string("shab"))){
        cout << "寻找shab失败"<<endl;
    }
    cout<<"finish"<<endl;
}


//不用vector版本
#define N 1000000
int son[N][26], cnt[N], idx;
// 0号点既是根节点，又是空节点
// son[][]存储树中每个节点的子节点
// cnt[]存储以每个节点结尾的单词数量

// 插入一个字符串
void insert(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++ ;
}

// 查询字符串出现的次数
int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}
