#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int closest = nums[0] + nums[1] + nums[2];

    for(int i = 0; i < n-2; i++){
        int left = i + 1, right = n - 1;

        while(left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if(abs(target - sum) < abs(target - closest)){
                closest = sum;
            }

            if(sum < target) left++;
            else right--;
        }
    }

    return closest;
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> nums[i];

    cout << "Enter target: ";
    cin >> target;

    int result = threeSumClosest(nums, target);
    cout << "Closest sum to " << target << " is: " << result << endl;

    return 0;
}
