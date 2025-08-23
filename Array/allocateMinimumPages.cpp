#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool canAllocate(vector<int>& arr, int k, int mid) {
    int pages = 0;
    int students = 1;
    for (int page : arr) {
        if (pages + page > mid) {
            students++;
            pages = page;
            if (students > k) return false;
        } else {
            pages += page;
        }
    }
    return true;
}

int findPages(vector<int>& arr, int k) {
    int n = arr.size();
    if (k > n) return -1;  // More students than books

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canAllocate(arr, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, k;
    cout << "Enter number of books: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter number of pages in each book: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of students: ";
    cin >> k;

    int result = findPages(arr, k);
    if (result == -1) {
        cout << "Allocation not possible\n";
    } else {
        cout << "Minimum maximum pages = " << result << endl;
    }

    return 0;
}
