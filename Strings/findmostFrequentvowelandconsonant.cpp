#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int maxFreqSum(string s){
    int n = s.size();
    unordered_map<char,int>vowel;
    unordered_map<char,int>consonant;
    for(int i=0;i<n;i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            vowel[s[i]]++;
        }else{
            consonant[s[i]]++;
        }
    }
    int vfreq=0,cfreq=0;
    for(auto &pair:vowel){
        vfreq=max(vfreq,pair.second);
    }
    for(auto &pair:consonant){
        cfreq=max(cfreq,pair.second);
    }
    return vfreq+cfreq;
}

int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    int answer = maxFreqSum(s);
    cout<<"The sum of two maximum frequencies is : "<<answer<<endl;
    return 0;
}