#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximizeones(vector<int>& arr, int k){
    int n = arr.size();
    int count = 0;
    int ans = 0;
    int left=0,right=0;
    while(right<n){
        if(arr[right]==0) count++;
        while(count>k){
            if(arr[left]==0) count--;
            left++;
        }
        ans = max(ans,right-left+1);
        right++;
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int>arr(n);
    cout<<"The elements in arr (only 0s and 1s): ";
    for(int i=0;i<n;i++) cin>>arr[i];
    int k;
    cout<<"Maximum 0s to flip: ";
    cin>>k;
    int answer = maximizeones(arr,k);
    cout<<"Count of longest subarray of 1's: "<<answer<<endl;
}