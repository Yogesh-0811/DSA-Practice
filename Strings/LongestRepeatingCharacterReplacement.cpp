#include <iostream>
#include <vector>
#include <string>
using namespace std;

int charReplacement(string s,int k){
    int n = s.size();
    int left=0,right=0;
    vector<int>alphaCount(26,0);
    int count = 0;
    int ans=0;

    while(right<n){
        alphaCount[s[right]-'A']++;
        count = max(count, alphaCount[s[right]-'A']);

        while((right-left+1)-count>k){
            alphaCount[s[left]-'A']--;
            left++;
        }
        ans = max(ans,right-left+1);
        right++;
    }
    return ans;
}

int main(){
    string s;
    int k;
    cout<<"Enter the string: ";
    cin>>s;
    cout<<"Maximum Replacements allowed: ";
    cin>>k;

    int result = charReplacement(s,k);
    cout<<"Longest substring length after replacement: "<<result<<endl;
}