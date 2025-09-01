#include <iostream>
#include <vector>
using namespace std;

int maxWater(vector<int>& heights){
    int n = heights.size();
    int left=0,right=n-1;
    int maxarea=0;
    while(left<right){
        int area=0;
        if(heights[left]<heights[right]){
            area=heights[left]*(right-left);
            left++;
        }else{
            area=heights[right]*(right-left);
            right--;
        }
        maxarea=max(maxarea,area);
    }
    return maxarea;
}

int main(){
    int n;
    cout<<"Enter the number of vertical lines: ";
    cin>>n;

    vector<int>heights(n);
    cout<<"Enter the height of vertical lines: ";
    for(int i=0;i<n;i++) cin>>heights[i];

    int answer = maxWater(heights);

    cout<<"The maximum amount of water that can be contained between any two lines: "<<answer<<endl;
}