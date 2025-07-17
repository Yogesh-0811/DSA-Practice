#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long rev = 0;  // used long long to detect overflow safely

        while (x != 0) {
            int digit = x % 10;
            rev = rev * 10 + digit;
            x = x / 10;
        }

        // Checked for 32-bit signed integer overflow
        if (rev < INT_MIN || rev > INT_MAX)
            return 0;

        return static_cast<int>(rev);
    }
};

int main() {
    Solution sol;
    int x = 123;
    cout << "Reversed: " << sol.reverse(x) << endl;
    return 0;
}

