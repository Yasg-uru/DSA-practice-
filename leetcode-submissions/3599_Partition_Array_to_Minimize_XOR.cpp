class Solution {
public:
    int minXor(vector<int>& nums, int k) {
     int n = nums.size();
        vector<vector<int>>t(n+1, vector<int>(k+1, INT_MAX));
        t[0][0]=0 ;
        for(int i =1;i<=n;i++){
            for(int j =1;j<=k;j++){
                int minVal= 0 ;
                for(int c = i;c>=1;c--){
                    minVal^= nums[c-1];
                    t[i][j] = min(t[i][j], max(t[c-1][j-1], minVal));
                }
            }
        }
        return t[n][k];
    }
};