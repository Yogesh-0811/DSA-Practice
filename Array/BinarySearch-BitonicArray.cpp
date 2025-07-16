//Given an array of integers arr[] that is first strictly increasing and then maybe strictly decreasing, find the bitonic point, that is the maximum element in the array.

#include <iostream>
#include <vector>
using namespace std;

int findBitonicPoint(const vector<int>& arr){
    int low=0,high=arr.size()-1;
    while(low<=high){
        int mid=low + (high-low)/2;
        if(mid==0 || arr[mid]>arr[mid-1]&& (mid==arr.size()-1 || arr[mid]>arr[mid+1])){
            return arr[mid];
        }
        else if(mid<arr.size()-1 && arr[mid]<arr[mid+1]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {1,2,4,5,7,8,3};
    cout<<"Bitonic Point: "<< findBitonicPoint(arr) <<endl;
    return 0;
}