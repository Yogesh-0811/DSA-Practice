#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string minWindowSubstring(string s,string t){
    int n = s.size();
    int m = t.size();
    if(m>n) return "";
    unordered_map<char,int>freq_t;
    for(char c:t){
        freq_t[c]++;
    }
    unordered_map<char,int>freq_s;
    int left=0,right=0,start=0,minstreak=INT_MAX;
    int required=freq_t.size(),formed=0;
    while(right<n){
        char ch = s[right];
        freq_s[ch]++;
        if(freq_t.find(ch)!=freq_t.end() && freq_t[ch]==freq_s[ch]){
            formed++;
        }
        while(left<=right && formed==required){
            if(right-left+1<minstreak){
                minstreak=right-left+1;
                start=left;
            }
            char lc = s[left];
            freq_s[lc]--;
            if(freq_t.find(lc)!=freq_t.end() && freq_s[lc]<freq_t[lc]){
                formed--;
            }
            left++;
        }
        right++;
    }
    return minstreak==INT_MAX?"":s.substr(start,minstreak);
}

int main(){
    string s;
    cout<<"Enter the first string: ";
    cin>>s;
    string t;
    cout<<"Enter the second string: ";
    cin>>t;
    string ans = minWindowSubstring(s,t);
    if(ans.empty()){
        cout<<"No window Substring contains contains all characters of t";
    }else{
        cout<<"The minimum Window SubString in s which includes all of t characters is: "<<ans<<endl;
    }
}