#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > farthest) return false; // stuck
            farthest = max(farthest, i + nums[i]);
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {2,3,1,1,4};
    vector<int> nums2 = {3,2,1,0,4};

    cout << (sol.canJump(nums1) ? "true" : "false") << endl;  // true
    cout << (sol.canJump(nums2) ? "true" : "false") << endl;  // false

    return 0;
}
