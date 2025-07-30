// Given an unsorted array arr[] of integers, find the number of subarrays whose sum exactly equal to a given number k.

// Examples:

// Input: arr[] = [10, 2, -2, -20, 10], k = -10
// Output: 3
// Explaination: Subarrays: arr[0...3], arr[1...4], arr[3...4] have sum exactly equal to -10.

#include <bits/stdc++.h>
using namespace std;

//-------------------------------------O(n²)----------------------------------
// class Solution {
//   public:
//     int cntSubarrays(vector<int> &arr, int k) {
//         int count = 0;
//         int n = arr.size();

//         for (int i = 0; i < n; i++) {
//             int sum = 0;
//             for (int j = i; j < n; j++) {
//                 sum += arr[j];
//                 if (sum == k) {
//                     count++;
//                 }
//             }
//         }

//         return count;
//     }
// };

//-------------------------------------O(n)--------------------------------------
class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> precount;
        precount[0] = 1; //imp
        int sum = 0, count = 0;

        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];

            if (precount.find(sum - k) != precount.end()) {
                count += precount[sum - k];
            }

            precount[sum]++;
        }

        return count;
    }
};

int main() {
    vector<int> arr = {3, 4, 7, 2, -3, 1, 4, 2};
    int k = 7;

    Solution sol;
    int result = sol.cntSubarrays(arr, k);
    cout << "Count of subarrays with sum " << k << " = " << result << endl;

    return 0;
}
