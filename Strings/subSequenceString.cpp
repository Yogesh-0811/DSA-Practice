// Check if a String is Subsequence of Other

// Given two strings s1 and s2. You have to check that s1 is a subsequence of s2 or not.
// Note: A subsequence is a sequence that can be derived from another sequence by deleting some elements without changing the order of the remaining elements.

// Examples:

// Input: s1 = "AXY", s2 = "YADXCP"
// Output: false
// Explanation: s1 is not a subsequence of s2 as 'Y' appears before 'A'.
// Input: s1 = "gksrek", s2 = "geeksforgeeks"
// Output: true
// Explanation: If we combine the bold character of "geeksforgeeks", it equals to s1. So s1 is a subsequence of s2. 

#include <bits/stdc++.h>
using namespace std;

bool isSubSeq(string& s1, string& s2) {
    int i = 0, j = 0;
    int m = s1.size(), n = s2.size();
    
    while (i < m && j < n) {
        if (s1[i] == s2[j]) {
            i++; 
        }
        j++; 
    }
    
    return i == m;
}

int main() {
    string s1, s2;
    cout << "Enter string s1: ";
    cin >> s1;
    cout << "Enter string s2: ";
    cin >> s2;

    if (isSubSeq(s1, s2)) {
        cout << "s1 is a subsequence of s2" << endl;
    } else {
        cout << "s1 is NOT a subsequence of s2" << endl;
    }
    return 0;
}
