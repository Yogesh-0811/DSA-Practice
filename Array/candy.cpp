#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int>& ratings){
    int n=ratings.size();
    vector<int>candies(n,1);

    for(int i=1;i<n;i++){
        if(ratings[i]>ratings[i-1]){
            candies[i]=candies[i-1]+1;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(ratings[i]>ratings[i+1]){
            candies[i]=max(candies[i],candies[i+1]+1);
        }
    }
    int sum=0;
    for(int c:candies){
        sum+=c;
    }
    return sum;
}

int main(){
    int n;
    cout<<"Enter number of children: ";
    cin>>n;

    vector<int>ratings(n);
    cout<<"Enter the ratings of each child: "<<endl;
    for(int i=0;i<n;i++) cin>>ratings[i];

    int minimum = candy(ratings);
    cout<<"The minimum number of candies to distribute: "<<minimum<<endl;
    return 0;
}