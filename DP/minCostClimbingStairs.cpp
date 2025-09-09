#include <iostream>
#include <vector>
using namespace std;

int minCostClimbingStairs(vector<int>& cost){
    int n=cost.size();
    int prev2=cost[0];
    int prev1=cost[1];

    for(int i=2;i<n;i++){
        int curr = cost[i] + min(prev2,prev1);
        prev2=prev1;
        prev1=curr;
    }
    return min(prev2,prev1);
}

int main(){
    int n;
    cout<<"Enter the number if steps: ";
    cin>>n;
    vector<int>cost(n);
    cout<<"Enter the cost at each step: ";
    for(int i=0;i<n;i++) cin>>cost[i];

    int answer = minCostClimbingStairs(cost);
    cout<<"Minimum cost: "<<answer<<endl;

    return 0;
}