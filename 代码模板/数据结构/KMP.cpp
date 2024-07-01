#include <iostream>
#include <vector>
using namespace std;
vector<int> GetNext(string & T){
    vector<int> next(T.size());
    int i=0,k=-1;
    next[0]=-1;
    while(i<T.size()-1){
        if(k==-1||T[k]==T[i])
            next[++i] = ++k;
        else
            k=next[k];
    }
    return next;
}
int main(){
    int i=0,j=0;
    string t,s;
    cin>>i;
    cin>>t;
    cin>>j;
    cin>>s;
    vector<int>next = GetNext(t);
    i=0,j=0;
    while(i<s.size()){
        if(j==-1||s[i]==t[j])
            j++,i++;
        else
            j=next[j];
        if(j==t.size()){
            cout<<i-j<<' ';
            //匹配多次
            i=i-j+next[j-1]+1;
            j=next[j-1];
        }
    }
}