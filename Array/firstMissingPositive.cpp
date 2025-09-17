// 41. First Missing Positive

// Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
// You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int>&nums){
    int n=nums.size();
    for(int i=0;i<n;i++){
        while(nums[i]>0 && nums[i]<=n && nums[nums[i]-1]!=nums[i]){
            swap(nums[i],nums[nums[i]-1]);
        }
    }
    for(int i=0;i<n;i++){
        if(nums[i]!=i+1){
            return i+1;
        }
    }
    return n+1;
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter the numbers: ";
    for(int i=0;i<n;i++) cin>>nums[i];

    cout<<"The First Missing Positive Number from the series is : "<<firstMissingPositive(nums)<<endl;
    return 0;
}