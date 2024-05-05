#include <iostream>
using namespace std;
void MergeSort(int q[],int l,int r){
    if(l>=r)
        return;
    int mid = (l+r)/2;//确定分界点
    MergeSort(q,l,mid);MergeSort(q,mid+1,r);//递归左半段与右半段知道数组长度为1
    //对左右半段进行归并
    int *temp = new int[r-l+1];
    int k=0,i=l,j=mid+1;
    while (i <= mid && j <= r){
        if(q[i]<=q[j])
        temp[k++]=q[i++];
    else 
        temp[k++]=q[j++];
    }
    while(i<=mid)
        temp[k++]=q[i++];
    while(j<=r)
        temp[k++]=q[j++];
    for(int i=l,j=0;i<=r;i++,j++){
        q[i] = temp[j];
    }
    delete[] temp;
}
int main(){
    int n;
    scanf("%d",&n);
    int *p = new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    MergeSort(p,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",p[i]);
    }
}