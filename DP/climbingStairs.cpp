#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     int climbStairs(int n) {
//         if (n <= 2) {
//             return n;
//         }
//         int first = 1, second = 2, third;
//         for (int i = 3; i <= n; i++) {
//             third = first + second;
//             first = second;
//             second = third;
//         }
//         return second;
//     }
// };

class Solution {
public:
    int climbStairs(int n) {
        if(n<=2){
            return n;
        }
        vector<int>dp(n+1);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

int main() {
    Solution sol;

    int n;
    cout << "Enter number of stairs: ";
    cin >> n;

    cout << "Number of ways to climb " << n << " stairs = " 
         << sol.climbStairs(n) << endl;

    return 0;
}
