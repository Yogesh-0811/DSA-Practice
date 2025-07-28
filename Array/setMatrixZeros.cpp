#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<bool> row(m, false), col(n, false);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (row[i] || col[j]) {
                    mat[i][j] = 0;
                }
            }
        }
    }
};
int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    Solution sol;
    sol.setMatrixZeroes(mat);

    cout << "Matrix after setting zeroes: "<<endl;
    for (auto &row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
