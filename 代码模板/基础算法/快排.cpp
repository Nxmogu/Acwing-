#include <iostream>
using namespace std;
void QuickSort(int q[],int l,int r){
    if(l>=r)
        return;
    else{
        int x = q[l + r >> 1];//万能边界点
        int i=l-1,j=r+1;
        while(i<j){
            while(q[++i]<x);
            while(q[--j]>x);
            if(i<j)
                swap(q[i],q[j]);
        }
        //此时边界点不可以选择为q[r]
        QuickSort(q,l,j);
        QuickSort(q,j+1,r);
        //此时边界点不可以选择为q[l]
        /*
        quicksort(q,l,i-1);
        quicksort(q,i,r);
        */
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int *q = new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",&q[i]);
    }
    QuickSort(q,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",q[i]);
    }
}