#include<iostream>
using namespace std;

int minside(int n, int l, int w){
    int low=0; int high;
    if(l>=w){high=l*n;}
    else{high=w*n;}
    int side=high;
    while(low<=high){
        int mid=(low+high)/2;
        if((mid/l)*(mid/w)>=n){
            side=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return side;

}
int main(){
    int s=minside(6,3,2);
    cout<<"Minimum side required is "<<s;
}
