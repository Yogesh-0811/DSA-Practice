#include <iostream>
#include <vector>
using namespace std;

bool canEat(vector<int>& piles,int h,int k){
    long long hours = 0;
    for(int bananas : piles){
        hours+=(bananas+k-1)/k;
    }
    if(hours<=h){
        return true;
    }
    return false;
}

int minSpeed(vector<int>& piles, int h){
    int low = 1;
    int high = piles[0];
    for(int i=0;i<piles.size();i++){
        if(piles[i]>high){
            high=piles[i];
        }
    }
    int ans = high;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(canEat(piles,h,mid)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    int n,h;
    cout<< "Enter the number of piles: ";
    cin>>n;
    cout<<"The guards will come back in ? hours: ";
    cin>>h;
    vector<int> piles(n);
    cout<<"Enter the number of bananas in each pile: ";
    for(int i=0;i<n;i++){
        cin>>piles[i];
    }
    int ans = minSpeed(piles,h);
    cout<<"The minimum speed in which she can eat all the bananas: "<<ans<<endl;
    return 0;
}