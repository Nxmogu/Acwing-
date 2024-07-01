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