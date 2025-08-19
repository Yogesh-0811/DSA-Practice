#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> farMin(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n, -1), suffMin(n);

        suffMin[n-1] = arr[n-1];
        for (int i = n-2; i >= 0; i--) {
            suffMin[i] = min(arr[i], suffMin[i+1]);
        }

        // int n = arr.size();
        // vector<int>result(n,-1);
        // for(int i=0;i<n;i++){
        //     for(int j=n-1;j>i;j--){
        //         if(arr[j]<arr[i]){
        //             result[i]=j;
        //             break;
        //         }
        //     }
        // }

        for(int i=0;i<n;i++){
            int l=i+1,r=n-1,ans=-1;
            while(l<=r){
                int mid = (l+r)/2;
                if(suffMin[mid]<arr[i]){
                    ans=mid;
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            result[i]=ans;
        }

        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 1, 5, 2, 4};
    vector<int> ans = sol.farMin(arr);
    cout << "Farthest smaller element indices: ";
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}
