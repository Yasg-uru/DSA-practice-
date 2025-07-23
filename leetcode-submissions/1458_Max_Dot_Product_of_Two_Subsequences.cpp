class Solution {
public:
    int m , n ;
    int t[501][501];
    int solve(vector<int>& nums1, vector<int>& nums2, int i , int j){
        if(i==m or j==n) return -1e9;
        if(t[i][j]!=-1e9){
            return t[i][j];

        }
        int num = nums1[i]*nums2[j];
        int take_both = num+ solve(nums1, nums2, i+1, j+1);
        int skip_i= solve(nums1, nums2, i+1, j);
        int skip_j= solve(nums1, nums2, i, j+1);
        return t[i][j]= max({take_both, num,skip_i,skip_j});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
       for(int i=0;i<501;i++){
        for(int j=0;j<501;j++){
            t[i][j]= -1e9;
        }
       }
        return solve(nums1, nums2, 0  , 0 );
    }
};