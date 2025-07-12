#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> romanmap = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
            {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
            {1, "I"}
        };

        string result = "";
        for (auto &pair : romanmap) {
            while (num >= pair.first) {
                result += pair.second;
                num -= pair.first;
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    int num;
    cout << "Enter an integer (1 to 3999): ";
    cin >> num;

    if (num < 1 || num > 3999) {
        cout << "Invalid input. Please enter a number between 1 and 3999." << endl;
    } else {
        string roman = sol.intToRoman(num);
        cout << "Roman numeral: " << roman << endl;
    }

    return 0;
}
