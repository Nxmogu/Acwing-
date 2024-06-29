#include <string>
#include <iostream>
#include <memory>
#include <vector>
using namespace std;
vector<int> GetNext(string T){
         vector<int> next(T.size());
         next[0]=-1;
         int k,i=0;
         while(i<T.size()-1){
            k=next[i];
            if(T[i]==T[k]||k==-1){
                next[i++]=k+1;
            }
            else
                k=next[k];
         }
         return next;
   }

int kmp(string &s,string &t) {
    vector<int> next = GetNext(t);
    int i = 0,j = 0;
    while (i < s.size() && j < (int) t.size()) {
        if (j == -1 || s[i] == t[j]) i++, j++;
        else j = next[j];
    }
    if (j == t.size()) return i - j;
    else return -1;
}