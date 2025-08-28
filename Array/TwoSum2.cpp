#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1}; 
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = s.twoSum(numbers, target);

    cout << "Result: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
