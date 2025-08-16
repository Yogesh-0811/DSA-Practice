#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int space = 0; space < i; space++) {
            cout << " ";
        }
        for (int star = 0; star < 2 * (n - i) - 1; star++) {
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = 1; i < n; i++) {
        for (int space = 0; space < n - i - 1; space++) {
            cout << " ";
        }
        for (int star = 0; star < 2 * i + 1; star++) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
