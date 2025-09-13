#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getMinDiff(vector<int>& arr,int k){
    int n = arr.size();
    if(n==1) return 0;

    sort(arr.begin(),arr.end());

    int ans = arr[n-1]-arr[0];
    int smallest = arr[0]+k;
    int largest = arr[n-1]-k;

    for(int i=0;i<n-1;i++){
        int mn = min(smallest,arr[i+1]-k);
        int mx = max(largest, arr[i]+k);
        if(mn<0) continue;
        ans = min(ans,mx-mn);
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the number of towers: ";
    cin>>n;

    vector<int>arr(n);
    cout<<"Enter the heights of towers: ";
    for(int i=0;i<n;i++) cin>>arr[i];

    int k;
    cout<<"Enter k height to operate: ";
    cin>>k;

    int answer = getMinDiff(arr,k);
    cout<<"Minimum possible difference between the height of shortest and tallest towers after modification is : "<<answer<<endl;
    return 0;
}