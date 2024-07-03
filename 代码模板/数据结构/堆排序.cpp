#include <iostream>
#include <vector>
class My_Headp{
public:
    My_Headp(){}
    void Heap_Insert(std::vector<int>& arr){
        for(int i=0;i<arr.size();i++){
            int current_inx = i;
            int father_inx = (i-1)/2;
            while(arr[current_inx]>arr[father_inx]){
                swap(arr,current_inx,father_inx);
                current_inx = father_inx;
                father_inx = (current_inx - 1)/2;
            }
        }
    }
    void Heapfy(std::vector<int>& arr,int index,int size){
        int left = 2*index +1;
        int right = 2*index + 2;
        int largeindex;
        while(left<size){
            if(arr[left]<arr[right]&&right<size)
                largeindex = right;
            else 
                largeindex = left;
            if(arr[index]>arr[largeindex])
                largeindex=index;
            if(index == largeindex)
                break;
            else
                swap(arr,index,largeindex);
            index = largeindex;
            left = 2*index +1;
            right = 2*index + 2;
        }
    }
    void swap(std::vector<int>& arr,int i,int j){
        int temp = arr[i];
        arr[i]=arr[j];
        arr[j] = temp;
    }
};
