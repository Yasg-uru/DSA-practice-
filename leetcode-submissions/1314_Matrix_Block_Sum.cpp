class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>>ans(m , vector<int>(n , 0));
        for(int i =0 ;i<m;i++){
            for(int j =0 ;j<n;j++){
                int m_ = max(0 , i-k);
                int m__ = min(m-1 , i+k);
                int n_ = max(0 , j-k);
                int n__ = min(n-1 , j+k);
                int sum =0 ;
                for(int r=m_ ;r<=m__;r++){
                    for(int c = n_ ;c<=n__;c++){
                        sum+=mat[r][c];
                    }
                }
                ans[i][j]= sum ;
            }
        }
        return ans ;
    }
};