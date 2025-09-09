#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums){
    int n = nums.size();
    if(n==1) return nums[0];

    int prev2 = nums[0];
    int prev1 = max(nums[0],nums[1]);

    for(int i=2;i<n;i++){
        int take = nums[i]+prev2;
        int skip = prev1;
        int curr = max(take,skip);

        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}

int main(){
    int n;
    cout<<"Enter number of houses: ";
    cin>>n;

    vector<int>nums(n);
    cout<<"Enter money in each house: ";
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    int result = rob(nums);
    cout<<"Maximum money robber can steal: "<<result<<endl;
    return 0;
}