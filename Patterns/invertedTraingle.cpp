#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int spaces = i - 1;
        int stars  = 2 * (n - i) + 1;

        cout << string(spaces, ' ') << string(stars, '*') << '\n';
    }
}
