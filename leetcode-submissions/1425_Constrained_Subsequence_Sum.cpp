class Solution {
public:
    int n ;
    int solve(vector<int>&nums , int &k, int prev , int i){
        if(i>=n){
            return 0 ;

        }
        int take = 0 ;

        if(prev==-1 or i-prev<=k){
            take = nums[i]+solve(nums , k , i , i+1);
        }
        int not_take = solve(nums , k, prev, i+1);
        return max(take ,not_take);

    }
    int constrainedSubsetSum(vector<int>& nums, int k) {
        n= nums.size();
        int ans  = solve(nums , k ,-1,  0 );
        return ans==0?-1:ans;
    }
};