#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlace(const vector<int>& pos, int m, int dist) {
    int count = 1;
    int last = pos[0];
    for (int i = 1; i < (int)pos.size(); i++) {
        if (pos[i] - last >= dist) {
            count++;
            last = pos[i];
            if (count >= m) return true;
        }
    }
    return false;
}

int maxDistance(vector<int> position, int m) {
    sort(position.begin(), position.end());
    int low = 0;
    int high = position.back() - position.front();
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPlace(position, m, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {

    int n, m;
    cout << "Enter number of positions: ";  
    cin >> n;

    cout << "Enter number of balls: ";      
    cin >> m;

    vector<int> position(n);
    cout << "Enter the positions: ";        
    for (int i = 0; i < n; i++) cin >> position[i];

    int answer = maxDistance(position, m);

    cout << "Maximum magnetic force: " << answer << "\n";  
    return 0;
}