#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        bool searchMatrix(vector<vector<int>>& matrix,int target){
            int n=matrix.size();
            int m=matrix[0].size();
            int low=0,high=n*m-1;

            while(low<=high){
                int mid = low+(high-low)/2;
                int row = mid/m;
                int col = mid%m;

                if(matrix[row][col]==target){
                    return true;
                }else if(matrix[row][col]<target){
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
            return false;
        }
};

int main(){
    int n,m,target;
    cout<<"Enter number of rows and columns: ";
    cin>>n>>m;

    vector<vector<int>>matrix(n,vector<int>(m));
    cout<<"Enter matrix elements row-wise: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"Enter target: ";
    cin>>target;

    Solution sol;
    if(sol.searchMatrix(matrix,target)){
        cout<<"Target found in matrix"<<endl;
    }else{
        cout<<"Target not found in matrix"<<endl;
    }
    return 0;
}