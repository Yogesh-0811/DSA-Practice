#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElements(vector<int>& arr){
    int n = arr.size();
    vector<int>result(n,-1);
    stack<int>st;

    for(int i=0;i<2*n;i++){
        int num = arr[i%n];
        while(!st.empty() && arr[st.top()]<num){
            result[st.top()] = num;
            st.pop();
        }
        if(i<n)st.push(i);
    }
    return result;
}

int main(){     
    int n;
    cout<<"Enter the elements in arr: ";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter the elements in arr: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    vector<int>answer = nextGreaterElements(arr);
    for(int num:answer){
        cout<<num<<" ";
    }
    return 0;
}