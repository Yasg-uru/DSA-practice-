class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n);
        int top=0;
        int left=0;
        int right=n-1;
        int bottom=n-1;
        int direction=0;
        int value=0;

        while(left<=right and top<=bottom){
            if(direction==0){
                for(int col=left;col<=right;col++){
                    ans[top][col]=value++;
                }
                top++;
            }
            if(direction==1){
                for(int row=top;row>=bottom;row--){
                    ans[row][right]=value++;
                }
                right--;
            }
            if(direction==2){
                for(int col=right;col>=left;col--){
                    ans[bottom][col]=value++;
                }
                bottom--;
            }else{
                for(int row=left;row>=top;row--){
                    ans[row][left]=value++;
                }
                left++;
            }
            direction=(1+direction)%4;
        }
        return ans;
    }
};