#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
    int subarraySum(vector<int>& arr){

    //O(n³)
        // int n=arr.size();
        // int sum=0;
        // for(int i=0;i<arr.size();i++){
        //     for(int j=n-1;j>=i;j--){
        //         for(int k=i;k<=j;k++){
        //             sum+=arr[k];
        //         }
        //     }
        // }
        // return sum;
    
    //O(n²)
        // int n=arr.size();
        // int totalSum=0;
        // for(int i=0;i<n;i++){
        //     int currentSum=0;
        //     for(int j=i;j<n;j++){
        //         currentSum += arr[j];
        //         totalSum += currentSum;
        //     }
        // }
        // return totalSum;

    // // O(n)
        int n=arr.size();
        int totalSum = 0;
        for(int i=0;i<n;i++){
            int freq = (i+1)*(n-i); // how many subarrays include the element arr[i]
            totalSum+=arr[i]*freq;
        }
        return totalSum;

    }
};
    int main(){
        vector<int> arr={1,2,3};
        Solution sol;
        int result = sol.subarraySum(arr);
        cout<<"Total sum of all subarrays: "<<result<<endl;
        return 0;
    }