#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int lengthofLongestSubstring(string s){
    int n = s.size();
    unordered_set<int>freq;
    int left=0,right=0;
    int maxstreak=0;
    while(right<n){
        if(freq.find(s[right])==freq.end()){
            freq.insert(s[right]);
            maxstreak = max(maxstreak,right-left+1);
            right++;
        }else{
            freq.erase(s[left]);
            left++;
        }
    }
    return maxstreak;
}

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    int length = lengthofLongestSubstring(s);
    cout<<"The length of Longest Substring without repeating characters is: "<<length<<endl;
}