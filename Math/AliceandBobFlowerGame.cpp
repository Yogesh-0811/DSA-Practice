#include <iostream>
using namespace std;

long long flowerGame(int n,int m){
    long long count = 0;

    int odds_n = (n+1)/2;
    int evens_m = m/2;
    count+=(1LL*odds_n*evens_m);

    int evens_n = n/2;
    int odds_m = (m+1)/2;
    count+=(1LL*evens_n*odds_m);

    return count;
}

int main(){
    int n;
    cout<<"Enter the flowers in first lane: ";
    cin>>n;

    int m;
    cout<<"Enter the flowers in second lane: ";
    cin>>m;

    long long answer = flowerGame(n,m);

    cout<<"The number of possible pairs(x,y) that satisfy the conditions mentioned in the statements are: "<<answer<<endl;
}