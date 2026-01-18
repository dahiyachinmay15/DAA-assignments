#include<iostream>
using namespace std;

void merge(int arr[], int l, int m, int h){
    int n1=m-l+1, n2 =h-m; 
    int left[n1],right[n2];
    for(int i=0;i<n1;i++){
        left[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        right[i]=arr[m+1+i];
    }
    int i=0, j=0, k=l;
while(i<n1 && j<n2){
    if(left[i]<=right[j]){
        arr[k]=left[i];
        i++;
    }
    else{
        arr[k]=right[j];
        j++;
    }
    k++;
}
while (i<n1){
    arr[k]=left[i];
    i++;
    k++;
}
while(j<n2){
    arr[k]=right[j];
    j++;
    k++;
}
}
void mergesort(int arr[],int l,int h){
    if(l<h){
        int m=(l+h)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,h);
        merge(arr,l,m,h);
    }
}
int main(){
    int  arr[]={4,7,6,23,11,5,2,15,20};
    int n=sizeof(arr)/sizeof(arr[0]);
   mergesort(arr,0,n);
   cout<<"Sorted array :"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
