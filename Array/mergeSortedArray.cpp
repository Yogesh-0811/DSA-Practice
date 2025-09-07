#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1,int m,vector<int>& nums2,int n){
    int i=m-1;
    int j=n-1;
    int k=m+n-1;

    while(i>=0 && j>=0){
        if(nums1[i]>=nums2[j]){
            nums1[k--]=nums1[i--];
        }else{
            nums1[k--]=nums2[j--];
        }
    }
    while(j>=0){
        nums1[k--]=nums2[j--];
    }
}

int main(){
    int m;
    cout<<"Enter the size of 1st arr: ";
    cin>>m;

    cout<<"Enter the elements of first array: ";
    vector<int>nums1;
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        nums1.push_back(x);
    }

    int n;
    cout<<"Enter the size of 2nd arr: ";
    cin>>n;

    cout<<"Enter the elements of 2nd arr: ";
    vector<int>nums2(n);
    for(int i=0;i<n;i++){
        cin>>nums2[i];
        nums1.push_back(0);
    }
    
    merge(nums1,m,nums2,n);

    for(int nums:nums1){
        cout<<nums<<" ";
    }
     return 0;
}