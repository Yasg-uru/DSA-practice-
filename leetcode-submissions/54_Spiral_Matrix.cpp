class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int top=0;
        int left=0;
        int right=matrix[0].size()-1;
        int bottom=matrix[0].size()-1;
        int direction=0;
        while(left<=right and top<=bottom){
            if(direction==0){
                for(int col=left;col<=right;col++){
                    ans.push_back(matrix[top][col]);
                    top++;
                }
            }else if(direction==1){
                for(int row=top;row<=bottom;row++){
                    ans.push_back(matrix[row][right]);
                    right--;
                }
            }else if(direction==2){
                for(int col=right;col>=left;col--){
                    ans.push_back(matrix[bottom][col]);
                    bottom--;
                }

            }else if(direction==3){
                for(int row=bottom;row>=top;row--){
                    ans.push_back(matrix[row][left]);
                    left++;
                }

            }
            direction=(direction+1)%4;
        }
        return ans;
    }
};