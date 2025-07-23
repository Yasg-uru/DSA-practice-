class Solution {
public:
    int  n;
    int t[501][501];
    int solve(int i , int j , vector<int>&nums1, vector<int>&nums2){
        if(i>=n || j>=n) return t[i][j]=  0 ;
        if(nums1[i]==nums2[j]){
            return t[i][j]=1+solve(i+1, j+1, nums1,nums2);
        }else{
            return t[i][j]=max(solve(i+1, j , nums1, nums2), solve(i, j+1, nums1 , nums2));
        }
    } 

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size();
        memset(t, -1 , sizeof(t));
        return solve(0 , 0 , nums1, nums2);
    }
};