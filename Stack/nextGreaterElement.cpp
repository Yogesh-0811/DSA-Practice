#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

vector<int> nextGreaterElement(vector<int>&nums1,vector<int>&nums2){
    unordered_map<int,int> nextGreater;
    stack<int>st;

    for(int num:nums2){
        while(!st.empty() && num>st.top()){
            nextGreater[st.top()]=num;
            st.pop();
        }
        st.push(num);
    }

    while(!st.empty()){
        nextGreater[st.top()]=-1;
        st.pop();
    }

    vector<int>result;
    for(int num:nums1){
        result.push_back(nextGreater[num]);
    }

    return result;
}

int main(){
    int n;
    cout<<"Enter the number of elements in nums1: ";
    cin>>n;
    vector<int>nums1(n);
    cout<<"Enter the elements in nums1: "<<endl;
    for(int &num:nums1) cin>>num;

    int m;
    cout<<"Enter the number of elements in nums2: ";
    cin>>m;
    vector<int>nums2(m);
    cout<<"Enter the elements in nums2: "<<endl;
    for(int &num:nums2) cin>>num;

    vector<int>answer = nextGreaterElement(nums1,nums2);
    cout<<"The next greater element for each number of nums1 in nums2 is: ";
    for(int ans:answer){
        cout<<ans<<" ";
    }
    return 0;
}