#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> result;

    for(int i = 0; i < n - 2; i++) {
        if(i > 0 && nums[i] == nums[i-1]) continue; // skip duplicates
        int left = i + 1, right = n - 1;
        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if(sum == 0) {
                result.push_back({nums[i], nums[left], nums[right]});
                while(left < right && nums[left] == nums[left+1]) left++;
                while(left < right && nums[right] == nums[right-1]) right--;
                left++;
                right--;
            }
            else if(sum < 0) left++;
            else right--;
        }
    }

    return result;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) cin >> nums[i];

    vector<vector<int>> res = threeSum(nums);

    cout << "Triplets that sum to 0:\n";
    for(auto &triplet : res) {
        cout << "{ ";
        for(int x : triplet) cout << x << " ";
        cout << "}\n";
    }

    return 0;
}
