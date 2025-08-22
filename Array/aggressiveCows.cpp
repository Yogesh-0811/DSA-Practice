#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlace(vector<int>& stalls,int cows, int dist){
    int count=1;
    int last=stalls[0];

    for(int i=1;i<stalls.size();i++){
        if(stalls[i]-last>=dist){
            count++;
            last=stalls[i];
            if(count>=cows){
                return true;
            }
        }
    }
    return false;
}

int aggressiveCows(vector<int>& stalls, int cows){
    sort(stalls.begin(),stalls.end());
    int low=0,high=stalls.back()-stalls.front();
    int ans=0;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(canPlace(stalls,cows,mid)){
            ans=mid;
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number of stalls: ";
    cin>>n;
    vector<int> stalls(n);
    cout<<"Enter the stall positions: ";
    for(int i=0;i<n;i++){
        cin>>stalls[i];
    }
    int cows;
    cout<<"Enter the number of cows: ";
    cin>>cows;
    int answer = aggressiveCows(stalls,cows);
    cout<<"Largest minimum distance between cows: "<<answer<<endl;
    return 0;
}