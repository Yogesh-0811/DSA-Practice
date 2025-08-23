#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool canShip(vector<int>&weights, int D,int capacity){
    int current_load=0;
    int days=1;
    for(int weight:weights){
        if(current_load+weight>capacity){
            days++;
            current_load=weight;
            if(days>D){
                return false;
            }
        }else{
            current_load+=weight;
        }
    }
    return true;
}

int minCapacity(vector<int>&weights, int D){
    int low = *max_element(weights.begin(),weights.end());
    int high = accumulate(weights.begin(),weights.end(),0);
    int ans = high;

    while(low<=high){
        int mid = low + (high-low)/2;
        if(canShip(weights,D,mid)){
            ans=mid;
            high=mid-1;
        }else{
            low=mid+1;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number of packages: ";
    cin>>n;
    int D;
    cout<<"Maximum number of days to ship within: ";
    cin>>D;
    vector<int> weights(n);
    cout<<"Enter the weights of the packages: ";
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    int ans = minCapacity(weights,D);
    cout<<"The minimum capacity of ship could be: "<<ans<<endl;
}