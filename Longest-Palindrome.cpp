//Brute Force

/*
#include <iostream>
using namespace std;

bool isPalindrome(const string &s, int left, int right){
    while(left<right){
        if(s[left]!=s[right]){
            return false;
        }
        left++;
        right--;
    }
    return true;
}

string longestPalindrome(string s){
    int n = s.size();
    string longest="";
    
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(isPalindrome(s,i,j)){
                int len = j-i+1;
                if(len>longest.length()){
                    longest = s.substr(i,len);
                }
            }
        }
    }
    return longest;
}

int main(){
    string s = "cacad";
    cout<< longestPalindrome(s);
}
*/

#include <iostream>
using namespace std;

string expandAroundCenter(const string &s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(string s) {
    string longest = "";
    for (int i = 0; i < s.size(); ++i) {
        string odd = expandAroundCenter(s, i, i);       
        string even = expandAroundCenter(s, i, i + 1);   
        if (odd.size() > longest.size()) longest = odd;
        if (even.size() > longest.size()) longest = even;
    }
    return longest;
}

int main() {
    string s = "babad";
    cout << longestPalindrome(s);  
}