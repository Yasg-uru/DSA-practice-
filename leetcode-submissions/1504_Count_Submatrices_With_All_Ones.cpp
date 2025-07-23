class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n  = mat[0].size();
        vector<vector<int>>arr(m , vector<int>(n, 0));
        for(int i =0;i<m;i++){
            int count =0 ;
            for(int j = n-1;j>=0;j--){
                if(mat[i][j]){
                    count++;
                }else{
                    count=0;
                }
                arr[i][j] = count;
                
            }
        }
        int ans = 0 ;
        for(int i =0 ;i<m;i++){
            for(int j =0 ;j<n;j++){
                int minWidth = INT_MAX;
                for(int k = i;k<m;k++){
                    minWidth = min(minWidth ,arr[k][j]);
                    ans += minWidth;
                }
            }
            
        }
        return ans;
    }
};