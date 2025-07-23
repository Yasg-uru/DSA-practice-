class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int lo=0;
        int high=m*n-1;
       while(lo<=high){
           int mid=(lo+high)/2;
                int x=mid/m;
                int y=mid%m;

           if(matrix[x][y]==target){
               return true;
           }else if(matrix[x][y]>target){
               high=mid-1;
           }else{
               lo=mid+1;
           }
       }
       return false;
    }
};