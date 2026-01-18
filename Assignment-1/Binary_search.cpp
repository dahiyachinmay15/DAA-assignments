// ITERATIVE
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

//RECURSIVE
#include<iostream>
using namespace std;

int binarysearch(int arr[],int low,int high,int x){
    if(low==high){
        if(x==arr[low]){
            return low;
        }
        else return -1;
    }
    else {
        int mid =(low+high)/2;
        if(x==arr[mid]){return mid;}
        else if (x<arr[mid]) {return binarysearch(arr,low,mid-1,x);}
        else {return binarysearch(arr,mid+1,high,x);}
    }
}
int main(){
    int arr[]={2,4,6,9,12,16,19,23};
    int n=(sizeof(arr)/sizeof(arr[0]));
    int r = binarysearch(arr,0,n,12);
    cout<<"Found at index : "<<r;
}

