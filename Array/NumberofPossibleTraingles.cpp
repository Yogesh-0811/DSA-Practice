#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int countTriangles(vector<int>& arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int count = 0;

    for (int i = n - 1; i >= 2; i--) {
        int left = 0, right = i - 1;
        while (left < right) {
            if (arr[left] + arr[right] > arr[i]) { 
                count += (right - left); 
                right--;
            } else {
                left++;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int result = countTriangles(arr);
    cout << "Number of possible triangles: " << result << endl;

    return 0;
}
