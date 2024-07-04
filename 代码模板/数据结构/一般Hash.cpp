#include <iostream>
#include <vector>
//开放寻址法
#define _2
#ifdef _1
const int N = 196613, INF = 0x3f3f3f3f;  //假定数据范围不超过1e9
class HashTable{
public:
    HashTable(){
        h = std::vector<int>(N,INF);
    }
    int my_hash(int x){
        int idx = (x%N+N)%N;
        while(h[idx]!=INF&&h[idx]!=x){
            idx=(idx+1)%N;
            if(idx == N)
                idx = 0;
        }
            
        return idx;
    }
    void insert(int x){
        h[my_hash(x)]=x;
    }
    bool query(int x){
        return (h[my_hash(x)]==x);
    }
public:
    std::vector<int> h;
};
#endif
//拉链法
const int N = 100003,INF = 0x3f3f3f3f;
class HashTable{
public:
    HashTable(){
        Table = std::vector<std::vector<int>*>(N,nullptr);
    }
    int Hash(int x){
        int idx = (x%N+N)%N;
        return idx;
    }
    void Insert(int x){
        int idx = Hash(x);
        if(Table[idx]==nullptr)
            Table[idx] = new std::vector<int>;
        Table[idx]->push_back(x);
    }
    bool Query(int x){
        int idx = Hash(x);
        if(Table[idx]==nullptr)
            return false;
        else{
            for(auto p = Table[idx]->begin();p!=Table[idx]->end();p++){
                if(*p == x)
                    return true;
            }
        }
        return false;
    }
public:
    std::vector<std::vector<int>*>Table;
};
#ifdef _2

#endif