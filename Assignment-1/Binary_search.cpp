#include<iostream>
using namespace std;

int binarysearch(int arr[],int n,int x){
int low = 0, high = n-1;
while(low<=high){
    int mid = (low+high)/2;
    if(arr[mid]==x){
        return mid;
    }
    else if (x<arr[mid]){
        high = mid-1;
    }
    else{
        low = mid+1;
    }
}
return -1;
}
int main(){
    int arr[]={2,4,6,9,12,16,19,23};
    int n= (sizeof(arr)/sizeof(arr[0]));
    int r = binarysearch(arr,n,6);
    cout<<"Found at index : "<<r;
}
