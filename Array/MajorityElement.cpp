// Given an array arr[] consisting of n integers, the task is to find all the array elements which occurs more than floor(n/3) times.
// Note: The returned array of majority elements should be sorted.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMajority(vector<int>& arr) {
        int n = arr.size();
        vector<int> result;
        unordered_map<int, int> freq;

        for (int i : arr) {
            freq[i]++;
        }

        for (auto &entry : freq) {
            if (entry.second > n / 3) {
                result.push_back(entry.first);
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 2, 3, 2, 2, 3, 1};

    vector<int> res = sol.findMajority(arr);
    cout << "Majority elements greater than n/3: ";
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
