#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    // First half
    for (int i = 1; i <= n; i++) {
        for (int space = 1; space <= n - i; space++) {
            cout << " ";
        }
        for (int star = 1; star <= i; star++) {
            cout << "*";
        }
        cout << "\n";
    }

    // Second half
    for (int i = n - 1; i >= 1; i--) {
        for (int space = 1; space <= n - i; space++) {
            cout << " ";
        }
        for (int star = 1; star <= i; star++) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
