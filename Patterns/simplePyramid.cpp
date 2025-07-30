#include <iostream>
using namespace std;

void simplePyramid(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    // int i=0,j=0;
    // while(i<n){
    //     while(j<=i){
    //         cout<<"* ";
    //         j++;
    //     }
    //     j=0;
    //     i++;
    //     cout<<endl;
    // }
}

int main(){
    int n;
    cout<<"Enter number : ";
    cin>>n;
    simplePyramid(n);
    return 0;
}