// A beautiful matrix is defined as a square matrix in which the sum of elements in every row and every column is equal. Given a square matrix mat[][], your task is to determine the minimum number of operations required to make the matrix beautiful.
// In one operation, you are allowed to increment the value of any single cell by 1.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinOperation(vector<vector<int>>& mat, int n) {
        vector<int> rowSum(n, 0), colSum(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i] += mat[i][j];
                colSum[j] += mat[i][j];
            }
        }

        int maxSum = 0;
        for (int i = 0; i < n; i++) {
            maxSum = max({maxSum, rowSum[i], colSum[i]});
        }

        int i = 0, j = 0, ops = 0;
        while (i < n && j < n) {
            int diff = min(maxSum - rowSum[i], maxSum - colSum[j]);
            mat[i][j] += diff;
            rowSum[i] += diff;
            colSum[j] += diff;
            ops += diff;

            if (rowSum[i] == maxSum) i++;
            if (colSum[j] == maxSum) j++;
        }

        return ops;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 2, 3},
        {3, 2, 1}
    };
    int n = mat.size();
    cout << sol.findMinOperation(mat, n) << endl;
    return 0;
}
