// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cout << "Enter number of rows: ";
//     cin >> n;

//     // First half
//     for (int i = 1; i <= n; i++) {
//         cout << string(i, '*') << '\n';
//     }

//     // Second half
//     for (int i = n - 1; i >= 1; i--) {
//         cout << string(i, '*') << '\n';
//     }

//     return 0;
// }


#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of rows: ";
    cin >> n;

    // First half
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << "\n";
    }

    // Second half
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}
