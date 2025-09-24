#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            vector<int> currentrow(i + 1, 1);
            for (int j = 1; j < i; j++) {
                currentrow[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(currentrow);
        }
        return result;
    }
};

int main() {

    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    Solution sol;
    vector<vector<int>> pascal = sol.generate(n);

    cout << "Pascal's Triangle:\n";
    for (auto &row : pascal) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout<<endl;
    }

    return 0;
}
