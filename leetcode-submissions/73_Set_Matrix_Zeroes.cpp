class Solution {
public:
void setrow(vector<vector<int>>&arr,int row){
    for(int j=0;j<arr[0].size();j++){
        if(arr[row][j]!=0){
            arr[row][j]=-1;
        }
    }
}
void setcol(vector<vector<int>>&arr,int col ){
    for(int i=0;i<arr.size();i++){
        if(arr[i][col]!=0){
            arr[i][col]=-1;
        }
    }
}
void setzeromatrix(vector<vector<int>>&arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            if(arr[i][j]==0){
                setrow(arr,i);
                setcol(arr,j);
            }
        }
    }
}
    void setZeroes(vector<vector<int>>& matrix) {
       setzeromatrix(matrix);
       for(int i=0;i<matrix.size();i++){
           for(int j=0;j<matrix[i].size();j++){
               if(matrix[i][j]==-1){
                   matrix[i][j]=0;
               }
           }
       }

    }
};