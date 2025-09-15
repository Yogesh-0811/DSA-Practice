#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>>mergeIntervals(vector<vector<int>>& intervals){
    if(intervals.empty()) return {};
    sort(intervals.begin(),intervals.end());
    int n=intervals.size();
    vector<vector<int>>result;
    result.push_back(intervals[0]);

    for(int i=1;i<n;i++){
        if(intervals[i][0]<=result.back()[1]){
            result.back()[1]=max(result.back()[1],intervals[i][1]);
        }else{
            result.push_back(intervals[i]);
        }
    }
    return result;
}

int main(){
    int n;
    cout<<"Enter number of intervals: ";
    cin>>n;

    vector<vector<int>> given(n,vector<int>(2));
    cout<<"Enter the intervals (start end): "<<endl;
    for(int i=0;i<n;i++){
        cin>>given[i][0]>>given[i][1];
    }
    vector<vector<int>>result = mergeIntervals(given);

    cout<<"Merged Intervals: "<<endl;
    for(auto &pair:result){
        cout<<"["<<pair[0]<<","<<pair[1]<<"]"<<endl;
    }
    return 0;
}
