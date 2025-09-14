#include <iostream>
#include <vector>
#include <string>
using namespace std;

int compress(vector<char>& chars){
    int n = chars.size();
    int write = 0;
    int i=0;
    while(i<n){
        char current = chars[i];
        int j=i;
        while(j<n && chars[j]==current){
            j++;
        }
        chars[write++]=current;
        int count = j-i;
        if(count>1){
            string num = to_string(count);
            for(char c:num){
                chars[write++]=c;
            }
        }
        i=j;
    }
    return write;
}

int main(){
    int n;
    cout<<"Enter number of characters: ";
    cin>>n;

    vector<char>chars(n);
    cout<<"Enter the characters (space seperated): ";
    for(int i=0;i<n;i++) cin>>chars[i];

    int newlen = compress(chars);

    cout<<"Compressed length: "<<newlen<<endl;
    cout<<"Compressed characters: ";
    for(int i=0;i<newlen;i++){
        cout<<chars[i]<<" ";
    }
    cout<<endl;
    return 0;
}