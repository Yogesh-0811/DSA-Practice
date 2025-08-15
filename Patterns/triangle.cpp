#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int spaces = n - i;
        int stars = 2 * i - 1;

        cout << string(spaces, ' ') << string(stars, '*') << '\n';
    }

    return 0;
}