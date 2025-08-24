#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
  public:
  
    bool canPlace(vector<int>& arr,int k,int m,int day){
        int bouquets=0,flower=0;
        for(int i:arr){
            if(i<=day){
                flower++;
                if(flower==k){
                    bouquets++;
                    flower=0;
                }
            }else{
                flower=0;
            }
        }
        return bouquets>=m;
    }
    
    int minDaysBloom(vector<int>& arr, int k, int m) {
        if(m*k>arr.size()) return -1;
        int low = *min_element(arr.begin(),arr.end());
        int high = *max_element(arr.begin(),arr.end());
        int ans = high;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(canPlace(arr,k,m,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};

int main() {
    int n, k, m;
    cout << "Enter number of flowers: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter bloom days of flowers: ";
    for(int i=0; i<n; i++) cin >> arr[i];

    cout << "Enter flowers per bouquet (k): ";
    cin >> k;

    cout << "Enter number of bouquets (m): ";
    cin >> m;

    Solution sol;
    int result = sol.minDaysBloom(arr, k, m);
    cout << "Minimum days required = " << result << endl;

    return 0;
}
