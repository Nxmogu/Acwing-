#include <iostream>
#include <string>
#define N 1000000
class StringHash{
public:
    StringHash(std::string& str1):str(str1){
        h[0]=0;
        p[0]=1;
        for(int i=1;i<str.size()+1;i++){
            p[i]=(p[i-1]*Base);
            h[i]=(h[i-1]*Base+str[i-1]);
        }
    }
    unsigned long long get(int l,int r){
        return (h[r]-h[l-1]*p[r-l+1]);
    }
public:
    unsigned long long h[N];
    unsigned long long p[N];
    //经验值:Base取131 or 13331,在99%的情况下不会出现冲突
    int Base = 133;
    std::string& str;
};