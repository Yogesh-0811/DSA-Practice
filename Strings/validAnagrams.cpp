#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> freqcount;
        
        for (char c : s) {
            freqcount[c]++;
        }
        
        for (char c : t) {
            freqcount[c]--;
        }
        
        for (auto it : freqcount) {
            if (it.second != 0) {
                return false;
            }
        }
        
        return true;
    }
};

int main() {
    Solution sol;

    string s = "anagram";
    string t = "nagaram";

    if (sol.isAnagram(s, t)) {
        cout << "Yes, they are anagrams." << endl;
    } else {
        cout << "No, they are not anagrams." << endl;
    }

    return 0;
}
