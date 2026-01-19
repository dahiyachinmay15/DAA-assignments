#include<iostream>
using namespace std;

int getmax(int arr[],int left,int mid,int right){
    int sum=0;
    int leftsum=arr[mid];
    for(int i=mid;i>=left;i--){
        sum += arr[i];
        if(sum>leftsum){
            leftsum=sum;
        }
    }
    sum =0;
    int rightsum = arr[mid+1];
    for(int i=mid+1;i<=right;i++){
        sum += arr[i];
        if(sum>rightsum){
            rightsum=sum;
        }
    }
    return rightsum+leftsum;
}
int maxsubsum(int arr[],int left,int right){
    if(left==right){return arr[left];}
    int mid=(left+right)/2;
    int lm=maxsubsum(arr,left,mid);
    int rm=maxsubsum(arr,mid+1,right);
    int cm=getmax(arr,left,mid,right);
    if(lm>=cm && lm>=rm){return lm;}
    else if(cm>=lm && cm>=rm){return cm;}
    else return rm;
}
int main(){
    int arr[]={-2,1,-3,4,-1,2,1,-5,4};
    int n= sizeof(arr)/sizeof(arr[0]);
    int r = maxsubsum(arr,0,n-1);
    cout<<"Max subarray sum is "<<r;
}
