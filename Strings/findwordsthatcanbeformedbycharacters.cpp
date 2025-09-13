#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26, 0);
        for (char c:chars) {
            freq[c-'a']++;
        }
        int sum = 0;
        for (string &word:words) {
            vector<int> wordfreq(26,0);
            for (char c:word) {
                wordfreq[c-'a']++;
            }
            bool formed=true;
            for (int i=0;i<26;i++) {
                if (wordfreq[i]>freq[i]) {
                    formed = false;
                    break;
                }
            }
            if (formed) sum += word.size();
        }
        return sum;
    }
};

int main() {

    int n;
    cout<<"Enter the number of strings in an arr: ";
    cin>>n;
    vector<string> words(n);
    cout<<"Enter the strings: ";
    for (int i=0; i<n; i++) {
        cin>>words[i];
    }
    string chars;
    cout<<"Enter chars: ";
    cin>>chars;

    Solution sol;
    cout<<"The sum of lengths of all good strings in words is: "<<sol.countCharacters(words, chars)<<endl;

    return 0;
}
