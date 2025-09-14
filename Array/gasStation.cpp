#include <iostream>
#include <vector>
using namespace std;


int startStation(vector<int>&gas,vector<int>&cost){

    //O(n²)

    // int n=gas.size();
    // for(int i=0;i<n;i++){
    //     gas.push_back(gas[i]);
    //     cost.push_back(cost[i]);
    // }
    // for(int i=0;i<n;i++){
    //     int tank=0;
    //     bool travelled=true;
    //     for(int j=i;j<i+n;j++){
    //         tank+=gas[i];
    //         tank-=cost[i];
    //         if(tank<0){
    //             travelled=false;
    //             break;
    //         }
    //     }
    //     if(travelled){
    //         return i;
    //     }
    // }
    // return -1;

    //O(n)

    int n=gas.size();
    int start=0,tank=0,total=0;
    for(int i=0;i<n;i++){
        total+=gas[i]-cost[i];
        tank+=gas[i]-cost[i];
        if(tank<0){
            start=i+1;
            tank=0;
        }
    }
    return total<0?-1:start;
}

int main(){
    int n;
    cout<<"Enter the number of gas stations: ";
    cin>>n;

    cout<<"Enter the amount of gas at each station: ";
    vector<int>gas(n);
    for(int i=0;i<n;i++) cin>>gas[i];

    cout<<"Enter the cost of gas at each station: ";
    vector<int>cost(n);
    for(int i=0;i<n;i++) cin>>cost[i];

    int startFrom = startStation(gas,cost);
    if(startFrom!=-1){
        cout<<"The index of starting station is: "<<startFrom<<endl;
    }else{
        cout<<"There is no such index present."<<endl;
    }
    return 0;
}