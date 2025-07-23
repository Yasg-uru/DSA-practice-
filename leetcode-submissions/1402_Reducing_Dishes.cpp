class Solution {
public:
    int t[1001][1001];
    int solve(vector<int>&nums  , int i , int time ){
        if(i>=nums.size()) return 0 ;
        if(t[i][time]!=-1) return t[i][time];
        int take = solve(nums, i+1, time+1) + nums[i]*time;
        int not_take = solve(nums, i+1, time);
        return t[i][time]=max(take, not_take);
    }
    int maxSatisfaction(vector<int>& nums) {
        // we need to sort the array in ascending order because always we want to peek max satisfaction 
        memset(t, -1, sizeof(t));
        sort(nums.begin(), nums.end());
        return solve(nums , 0 , 1);

    }
};