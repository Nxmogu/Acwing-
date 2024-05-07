bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
/*
#include <iostream>
using namespace std;
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int *q = new int[n];
    for(int i=0;i<n;i++)
        scanf("%d",&q[i]);
    while(m --){
        int x;
        scanf("%d",&x);
        int l=0,r=n-1,mid;
        while(l<r){
            mid =(l+r)/2;
            if(q[mid]>=x)
                r=mid;
            else
                l=mid+1;
        }
        if(q[l]!=x){
            cout<<"-1 -1"<<endl;
            continue;
        }
        else{
            cout <<l<<" ";
        }
        l=0,r=n-1;
        while(l<r){
            mid = (l+r+1)/2;
            if(q[mid]<=x)
                l=mid;
            else
                r=mid-1;
        }
        cout<<r<<endl;
    }
}*/