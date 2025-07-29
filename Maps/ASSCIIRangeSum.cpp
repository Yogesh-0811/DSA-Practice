// Given a string s consisting of lowercase English letters, for every character whose first and last occurrences are at different positions, calculate the sum of ASCII values of characters strictly between its first and last occurrence.
// Return all such non-zero sums (order does not matter).

// Examples:

// Input: s = "abacab"
// Output: [293, 294]
// Explanation: characters 'a' and 'b' appear more than once:
// 'a' : between positions 1 and 5 → characters are b, a, c and ascii sum is 98 + 97 + 99 = 294.
// 'b' : between positions 2 and 6 → characters are a, c, a and ascii sum is 97 + 99 + 97 = 293.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asciiRangeSum(string s) {
        unordered_map<char, pair<int, int>> pos; 
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            if (pos.find(s[i]) == pos.end()) {
                pos[s[i]] = {i, i};
            } else {
                pos[s[i]].second = i;
            }
        }

        vector<int> result;
        for (auto &entry : pos) {
            int start = entry.second.first;
            int end = entry.second.second;

            if (start != end) {
                int sum = 0;
                for (int i = start + 1; i < end; ++i) {
                    sum += (int)s[i];
                }
                if (sum > 0) {
                    result.push_back(sum);
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;
    string s = "abacab";

    vector<int> res = sol.asciiRangeSum(s);
    cout << "ASCII range sums: ";
    for (int sum : res) {
        cout << sum << " ";
    }
    cout << endl;

    return 0;
}
