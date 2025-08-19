#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& arr) {
        unordered_set<int> nums;
        for (int num : arr) {
            if (nums.find(num) != nums.end()) {
                return true;
            }
            nums.insert(num);
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5, 5};

    if (sol.containsDuplicate(arr)) {
        cout << "Contains duplicate" << endl;
    } else {
        cout << "No duplicates" << endl;
    }

    return 0;
}
