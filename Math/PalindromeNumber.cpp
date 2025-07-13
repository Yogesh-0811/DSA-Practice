#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int k = 0;
        long rev = 0;
        int n = x;
        while (x > 0) {
            k = x % 10;
            rev = (rev * 10) + k;
            x = x / 10;
        }
        return (n == rev);
    }
};

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;

    Solution sol;
    if (sol.isPalindrome(num)) {
        cout << num << " is a palindrome.\n";
    } else {
        cout << num << " is not a palindrome.\n";
    }

    return 0;
}
