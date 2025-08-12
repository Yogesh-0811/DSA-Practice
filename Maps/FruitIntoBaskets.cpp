#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> count;
        int left = 0, maxlen = 0;

        for (int right = 0; right < fruits.size(); right++) {
            count[fruits[right]]++;

            while (count.size() > 2) {
                count[fruits[left]]--;
                if (count[fruits[left]] == 0) {
                    count.erase(fruits[left]);
                }
                left++;
            }

            maxlen = max(maxlen, right - left + 1);
        }
        return maxlen;
    }
};

int main() {
    int n;
    cout << "Enter number of fruits: ";
    cin >> n;

    vector<int> fruits(n);
    cout << "Enter fruit types: ";
    for (int i = 0; i < n; i++) {
        cin >> fruits[i];
    }

    Solution sol;
    cout << "Maximum number of fruits: " << sol.totalFruit(fruits) << endl;

    return 0;
}
