//recursive
#include<iostream>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot= arr[high];
    int i = low-1;
    for(int j=low;j<=high;j++){
        if(arr[j]<pivot){
            i++;
            int temp = arr[j];
            arr[j]= arr[i];
            arr[i]=temp;
        }
    }
    int temp = arr[high];
    arr[high]=arr[i+1];
    arr[i+1]=temp;
    return i+1;
}
void quicksort(int arr[], int low, int high){
    if(low<high){
    int pi = partition(arr,low,high);
    quicksort(arr,low,pi-1);
    quicksort(arr,pi+1,high);
    }
}
int main(){
    int arr[]={10,7,8,9,1,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,n-1);
    cout<<"Sorted array : "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
// iterative
#include<iostream>
using namespace std;

int partition(int arr[],int low,int high){
    int pivot= arr[high];
    int i= low-1;
    for(int j=low; j<high; j++){
        if(arr[j]<pivot){
            i++;
            int temp = arr[j];
            arr[j]= arr[i];
            arr[i]=temp;
        }
    }
    int temp = arr[high];
    arr[high]=arr[i+1];
    arr[i+1]=temp;
    return i+1;

}

void quicksort(int arr[], int n){
    
    int stack[n], top =-1;
    stack[++top]=0;
    stack[++top]=n-1;
    while (top>=0){
        int high =stack[top--];
        int low =stack[top--];
        int pi = partition(arr,low,high);
        if(pi-1>low){
            stack[++top]=low;
            stack[++top]=pi-1;
        }
        if(pi+1<high){
            stack[++top]=pi+1;
            stack[++top]=high;
        }
    }
}
int main(){
    int arr[]={4,6,1,32,12,23,16,31};
    int n=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
}
