class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // first we need to create a direction array 
       vector<pair<int, int>> directions = {
    {0, 1},   // Right
    {1, 0},   // Down
    {0, -1},  // Left
    {-1, 0},  // Up
    {-1, -1}, // Top-left diagonal
    {1, 1},   // Bottom-right diagonal
    {1, -1},  // Bottom-left diagonal
    {-1, 1}   // Top-right diagonal
};

        // we need to iterate over the grid and then store their value in the i ,j th poisition of the answer vector 
        int m=img.size();
        int n=img[0].size();
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int sum=img[i][j];
                int count=1;
                for(auto dir:directions){
                    int row=i+dir.first;
                    int col=j+dir.second;
                    if(row>=0 and row<m and  col>=0 and  col<n){

                    sum+=img[row][col];
                    count++;
                    }
                }
                ans[i][j]=sum/count;
            }
        }
        return ans;
    }
};