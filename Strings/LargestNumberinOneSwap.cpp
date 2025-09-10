// Given a string s, return the lexicographically largest string that can be obtained by swapping at most one pair of characters in s.

// Examples:

// Input: s = "768"
// Output: "867"
// Explanation: Swapping the 1st and 3rd characters(7 and 8 respectively), gives the lexicographically largest string.
// Input: s = "333"
// Output: "333"
// Explanation: Performing any swaps gives the same result i.e "333".

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

string largestSwap(string& s){
    int n = s.size();
    vector<int>max(n);
    int maxpos = n-1;
    max[n-1]=n-1;

    for(int i=n-2;i>=0;i--){
        if(s[i]>s[maxpos]){
            maxpos=i;
        }
        max[i]=maxpos;
    }

    for(int i=0;i<n;i++){
        if(s[i]<s[max[i]]){
            swap(s[i],s[max[i]]);
            break;
        }
    }
    return s;
}

int main(){
    string s;
    cout<<"Enter the string of numbers: ";
    cin>>s;
    cout<<"Largest number after 1 swap: "<<largestSwap(s)<<endl;
    return 0;
}